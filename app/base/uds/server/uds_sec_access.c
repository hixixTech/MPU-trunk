#include  <stdlib.h>
#include "timer.h"
#include "uds_request.h"
#include "uds_server.h"
#include "key_access.h"

#define RequestSeed_Secrity_Level1          0x01
#define RequestSeed_Secrity_Level2          0x03
#define RequestSeed_Secrity_Level3          0x11
#define SeedKey_Secrity_Level1              0x02
#define SeedKey_Secrity_Level2              0x04
#define SeedKey_Secrity_Level3              0x12

void UDS_SRV_SecrityAcess(UDS_T *tUDS, uint8_t *p_u8PDU_Data, uint16_t u16PDU_DLC)
{
    uint8_t  Ar_u8RePDU_DATA[10], i = 0;
    static uint8_t flag, counter = 0;
    static uint32_t SecrityAccessFailCounter = 0;
    static uint32_t time = 0;
    static uint32_t seed, key1, key2, attempt = 0;
    static uint32_t  current_time = 0;

    if (u16PDU_DLC < 2)
    {
        uds_negative_response(tUDS, p_u8PDU_Data[0], NRC_IncorrectMessageLengthOrInvailFormat);
        return;
    }

    if (tm_get_time() < (900))  /*refer to wanshuai*/
    {
        uds_negative_response(tUDS, p_u8PDU_Data[0], NRC_RequiredTimeDelayNotExpired);
        return;
    }

    current_time = tm_get_time() / 1000;

    if (SecrityAccessFailCounter >= 3)
    {
        if ((current_time - time) < 10) // 10S
        {
            uds_negative_response(tUDS, p_u8PDU_Data[0], NRC_RequiredTimeDelayNotExpired);
            return;
        }
        else
        {
            SecrityAccessFailCounter--;
        }
    }

    switch (p_u8PDU_Data[1] & suppressPosRspMsgIndicationBitMask)
    {
        case RequestSeed_Secrity_Level1:
        case RequestSeed_Secrity_Level2:
            if (u16PDU_DLC != 2)
            {
                uds_negative_response(tUDS, p_u8PDU_Data[0], NRC_IncorrectMessageLengthOrInvailFormat);
                return;
            }

            if (flag == 1)
            {
                SecrityAccessFailCounter++;

                if (SecrityAccessFailCounter == 3)
                {
                    time = current_time;
                }
            }
            else
            {
                srand(current_time + (counter++));

                if (Get_SecurityAccess() == SecurityAccess_LEVEL0)
                {
                    seed = rand();
                    flag = 1;
                }
                else
                {
                    seed = 0;
                }
            }

            Ar_u8RePDU_DATA[i++] =  p_u8PDU_Data[0] + POS_RESPOND_SID_MASK ;
            Ar_u8RePDU_DATA[i++] =  p_u8PDU_Data[1];
            Ar_u8RePDU_DATA[i++] = (uint8_t)(seed >> 24);
            Ar_u8RePDU_DATA[i++] = (uint8_t)(seed >> 16);
            Ar_u8RePDU_DATA[i++] = (uint8_t)(seed >> 8);
            Ar_u8RePDU_DATA[i++] = (uint8_t)seed;

            log_o(LOG_UDS, "seed = 0X%X, key1 = 0X%X", seed, saGetKey(seed, 2));
            log_o(LOG_UDS, "seed = 0X%X, key2 = 0X%X", seed, saGetKey(seed, 4));

            break;

        case SeedKey_Secrity_Level1:
            if (u16PDU_DLC != 6)
            {
                uds_negative_response(tUDS, p_u8PDU_Data[0], NRC_IncorrectMessageLengthOrInvailFormat);
                return;
            }

            if (flag == 0)
            {
                uds_negative_response(tUDS, p_u8PDU_Data[0], NRC_RequstSequenceError);
                return;
            }

            if (attempt >= 3)
            {
                flag = 0;
                uds_negative_response(tUDS, p_u8PDU_Data[0], NRC_ExceedNumberOfAttempts);
                return;
            }

            key1 = (p_u8PDU_Data[2] << 24) + (p_u8PDU_Data[3] << 16) + (p_u8PDU_Data[4] << 8) + p_u8PDU_Data[5];
            key2 = saGetKey(seed, 2);

            log_o(LOG_UDS, "SeedKey_Secrity_Level1 key1 = %X, key2 = %X\r\n", key1, key2);

            if (key1 == key2)
            {
                Ar_u8RePDU_DATA[i++] =  p_u8PDU_Data[0] + POS_RESPOND_SID_MASK ;
                Ar_u8RePDU_DATA[i++] =  p_u8PDU_Data[1];
                flag = 0;

                if (p_u8PDU_Data[1] == SeedKey_Secrity_Level1)
                {
                    Set_SecurityAccess_LEVEL1();
                    SecrityAccessFailCounter = 0;
                }
            }
            else
            {
                uds_negative_response(tUDS, p_u8PDU_Data[0], NRC_InvalidKey);
                SecrityAccessFailCounter++;

                if (SecrityAccessFailCounter == 3)
                {
                    time = current_time;
                }

                attempt++;
                return;
            }

            break;

        case SeedKey_Secrity_Level2:
            if (u16PDU_DLC != 6)
            {
                uds_negative_response(tUDS, p_u8PDU_Data[0], NRC_IncorrectMessageLengthOrInvailFormat);
                return;
            }

            if (flag == 0)
            {
                uds_negative_response(tUDS, p_u8PDU_Data[0], NRC_RequstSequenceError);
                return;
            }

            if (attempt >= 3)
            {
                flag = 0;
                uds_negative_response(tUDS, p_u8PDU_Data[0], NRC_ExceedNumberOfAttempts);
                return;
            }

            key1 = (p_u8PDU_Data[2] << 24) + (p_u8PDU_Data[3] << 16) + (p_u8PDU_Data[4] << 8) + p_u8PDU_Data[5];
            key2 = saGetKey(seed, 4);

            log_o(LOG_UDS, "SeedKey_Secrity_Level2 key1 = %X, key2 = %X\r\n", key1, key2);

            if (key1 == key2)
            {
                Ar_u8RePDU_DATA[i++] =  p_u8PDU_Data[0] + POS_RESPOND_SID_MASK ;
                Ar_u8RePDU_DATA[i++] =  p_u8PDU_Data[1];
                flag = 0;

                if (p_u8PDU_Data[1] == SeedKey_Secrity_Level3)
                {
                    Set_SecurityAccess_LEVEL2();
                    SecrityAccessFailCounter = 0;
                }
            }
            else
            {
                uds_negative_response(tUDS, p_u8PDU_Data[0], NRC_InvalidKey);
                SecrityAccessFailCounter++;

                if (SecrityAccessFailCounter == 3)
                {
                    time = current_time;
                }

                attempt++;
                return;
            }

            break;

        default:
            uds_negative_response(tUDS, p_u8PDU_Data[0], NRC_SubFuncationNotSupported);
            return;
    }

    if (p_u8PDU_Data[1] & suppressPosRspMsgIndicationBit)
    {
        g_u8suppressPosRspMsgIndicationFlag = 1;
    }

    uds_positive_response(tUDS, tUDS->can_id_res, i, Ar_u8RePDU_DATA);

}

