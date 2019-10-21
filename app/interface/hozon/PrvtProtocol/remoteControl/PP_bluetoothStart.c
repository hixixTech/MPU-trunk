
/******************************************************
文件名：	PP_bluetoothstart.c

描述：	企业私有协议（浙江合众）
Data			Vasion			author
2018/1/10		V1.0			liujian
*******************************************************/

/*******************************************************
description： include the header file
*******************************************************/

#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include  <errno.h>
#include <sys/times.h>
#include <sys/time.h>
#include "timer.h"
#include <sys/prctl.h>

#include <sys/types.h>
#include <sysexits.h>	/* for EX_* exit codes */
#include <assert.h>	/* for assert(3) */
#include "constr_TYPE.h"
#include "asn_codecs.h"
#include "asn_application.h"
#include "asn_internal.h"	/* for _ASN_DEFAULT_STACK_MAX */
#include "Bodyinfo.h"
#include "per_encoder.h"
#include "per_decoder.h"
#include "tcom_api.h"
#include "ble.h"

#include "init.h"
#include "log.h"
#include "list.h"
#include "../../support/protocol.h"
#include "gb32960_api.h"
#include "hozon_SP_api.h"
#include "hozon_PP_api.h"
#include "shell_api.h"
#include "../PrvtProt_shell.h"
#include "../PrvtProt_EcDc.h"
#include "../PrvtProt.h"
#include "../PrvtProt_cfg.h"
#include "PP_rmtCtrl.h"
#include "../../../gb32960/gb32960.h"
#include "PP_canSend.h"
#include "PPrmtCtrl_cfg.h"
#include "../PrvtProt_SigParse.h"

#include "PP_bluetoothStart.h"

typedef struct
{
	PrvtProt_pack_Header_t	Header;
	PrvtProt_DisptrBody_t	DisBody;
}__attribute__((packed))  PP_bluetoothStart_pack_t; /**/

typedef struct
{
	PP_bluetoothStart_pack_t 	pack;
	PP_bluetoothStart_t		state;
}__attribute__((packed))  PrvtProt_bluetoothStart_t; 

static PrvtProt_bluetoothStart_t PP_bluetoothstart;
static int blue_start_stage = PP_BLUETOOTHSTART_IDLE;
static int bluestart_success_flag = 0;
static unsigned long long PP_Respwaittime = 0;

void PP_bluetoothstart_init(void)
{
	memset(&PP_bluetoothstart,0,sizeof(PrvtProt_bluetoothStart_t));
	memcpy(PP_bluetoothstart.pack.Header.sign,"**",2);
	PP_bluetoothstart.pack.Header.ver.Byte = 0x30;
	PP_bluetoothstart.pack.Header.commtype.Byte = 0xe1;
	PP_bluetoothstart.pack.Header.opera = 0x02;
	PP_bluetoothstart.pack.Header.tboxid = 27;
	memcpy(PP_bluetoothstart.pack.DisBody.aID,"110",3);
	PP_bluetoothstart.pack.DisBody.eventId = PP_AID_RMTCTRL + PP_MID_RMTCTRL_RESP;
	PP_bluetoothstart.pack.DisBody.appDataProVer = 256;
	PP_bluetoothstart.pack.DisBody.testFlag = 1;
	PP_bluetoothstart.state.req = 0;
}
int PP_bluetoothstart_mainfunction(void *task)
{
	int res = 0;
	switch(blue_start_stage)
	{
		case PP_BLUETOOTHSTART_IDLE:
		{			
			if(PP_bluetoothstart.state.req == 1)  //是否有请求
			{
				if(((PP_rmtCtrl_cfg_vehicleSOC()>15) && (PP_rmtCtrl_cfg_vehicleState() == 0))||(PP_rmtCtrl_gettestflag()))
				{   //有请求判断是否满足远控条件
					bluestart_success_flag = 0;
					blue_start_stage = PP_BLUETOOTHSTART_REQSTART;
					PP_bluetoothstart.state.req = 0;
				}
				else
				{
					log_o(LOG_HOZON," low power or power state on");
					PP_bluetoothstart.state.req = 0;
					bluestart_success_flag = 0;
					blue_start_stage = PP_BLUETOOTHSTARTL_END;
				}	
			}
		}
		break;
		case PP_BLUETOOTHSTART_REQSTART:
		{
			if(PP_bluetoothstart.state.cmd == 1) //下发蓝牙一键启动
			{
				PP_can_send_data(PP_CAN_BLUESTART,CAN_BLUESTART,0);
			}
			blue_start_stage = PP_BLUETOOTHSTART_RESPWAIT;
			PP_Respwaittime = tm_get_time();
		}
		break;
		case PP_BLUETOOTHSTART_RESPWAIT://执行等待车控响应
		{
			if((tm_get_time() - PP_Respwaittime) > 200)
			{
				if((tm_get_time() - PP_Respwaittime) < 2000)
				{
					if(PP_bluetoothstart.state.cmd == 2) // 等待一键启动结果
					{
						if(PP_rmtCtrl_cfg_bluestartSt() == 2) //一键启动成功
						{
							log_o(LOG_HOZON,"bluestart open successed!");
							PP_can_send_data(PP_CAN_BLUESTART,CAN_BLUECLEAN,0);
							bluestart_success_flag = 1;
							blue_start_stage = PP_BLUETOOTHSTARTL_END;
						}
					}
				}
				else//响应超时
				{
					log_o(LOG_HOZON,"timeout");
					PP_can_send_data(PP_CAN_BLUESTART,CAN_BLUECLEAN,0);
					bluestart_success_flag = 0;
					blue_start_stage = PP_BLUETOOTHSTARTL_END;
				}
			}
		}
		break;
		case PP_BLUETOOTHSTARTL_END:
		{
			PP_rmtCtrl_inform_tb(BT_POWER_CONTROL_RESP,PP_bluetoothstart.state.cmd,bluestart_success_flag);
			#if 0
			TCOM_MSG_HEADER msghdr;
			PrvtProt_respbt_t respbt;
			respbt.msg_type = BT_POWER_CONTROL_RESP;
			respbt.cmd = PP_bluetoothstart.state.cmd; 
			if(1 == bluestart_success_flag)
			{
				respbt.cmd_state.execution_result = bluestart_success_flag;  //ִ执行成功
				respbt.failtype = 0;	
			}
			else
			{
				respbt.cmd_state.execution_result = BT_FAIL;  //ִ执行失败
				respbt.failtype = 0;
			}
			msghdr.sender    = MPU_MID_HOZON_PP;
			msghdr.receiver  = MPU_MID_BLE;
			msghdr.msgid     = BLE_MSG_CONTROL;
			msghdr.msglen    = sizeof(PrvtProt_respbt_t);
			tcom_send_msg(&msghdr, &respbt);
			#endif
			blue_start_stage = PP_BLUETOOTHSTART_IDLE;
		}
		break;
		default:
		break;
	}
	return res;
}
void SetPP_bluetoothstart_Request(char ctrlstyle,void *appdatarmtCtrl,void *disptrBody)
{
	switch(ctrlstyle)
	{
		case RMTCTRL_TSP:
		{
			//TSP没有一键启动
		}
		break;
		case RMTCTRL_BLUETOOTH:
		{
			unsigned char cmd = *(unsigned char *)appdatarmtCtrl;
			if(cmd == 2 )//蓝牙一键启动
			{
				PP_bluetoothstart.state.cmd = 2;
			}
			else
			{
			}
			PP_bluetoothstart.state.req = 1;
			PP_bluetoothstart.state.style = RMTCTRL_BLUETOOTH;		 
		}
		break;
		default:
		break;
	}
}

int PP_bluetoothstart_start(void)
{
	if((PP_bluetoothstart.state.req == 1)&&(GetPP_rmtCtrl_fotaUpgrade() == 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int PP_bluetoothstart_end(void)
{
	if((blue_start_stage == PP_BLUETOOTHSTART_IDLE) &&(PP_bluetoothstart.state.req == 0))
	{
		return 1;
	}
	else
	{
		return 0;
		
	}
}

void PP_bluetoothstart_ClearStatus(void)
{
	PP_bluetoothstart.state.req = 0;
}

/************************shell命令测试使用**************************/
void PP_bluetoothstart_SetCtrlReq(unsigned char req,uint16_t reqType)
{
	PP_bluetoothstart.state.cmd = 2;
	PP_bluetoothstart.state.req = 1;
	PP_bluetoothstart.state.style = RMTCTRL_BLUETOOTH;
}

/************************shell命令测试使用**************************/






