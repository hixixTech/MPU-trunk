/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "HOZON"
 * 	found in "HOZON_PRIV_v1.0.asn"
 * 	`asn1c -gen-PER`
 */

#include "RmtCtrlStRespInfo.h"

static int
memb_rvcReqType_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 65535)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_rvcReqStatus_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 255)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_rvcFailureType_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 255)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_gpsPosition_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size == 1)) {
		/* Perform validation of the inner elements */
		return td->check_constraints(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_basicVehicleStatus_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size == 1)) {
		/* Perform validation of the inner elements */
		return td->check_constraints(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_gpsPosition_constr_5 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  1,  1 }	/* (SIZE(1..1)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_basicVehicleStatus_constr_7 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  1,  1 }	/* (SIZE(1..1)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_rvcReqType_constr_2 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 16,  16,  0,  65535 }	/* (0..65535) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_rvcReqStatus_constr_3 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 8,  8,  0,  255 }	/* (0..255) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_rvcFailureType_constr_4 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 8,  8,  0,  255 }	/* (0..255) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_gpsPosition_constr_5 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  1,  1 }	/* (SIZE(1..1)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_basicVehicleStatus_constr_7 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  1,  1 }	/* (SIZE(1..1)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_gpsPosition_5[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_RmtRvsposInfo,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		""
		},
};
static const ber_tlv_tag_t asn_DEF_gpsPosition_tags_5[] = {
	(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_gpsPosition_specs_5 = {
	sizeof(struct gpsPosition),
	offsetof(struct gpsPosition, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_gpsPosition_5 = {
	"gpsPosition",
	"gpsPosition",
	SEQUENCE_OF_free,
	SEQUENCE_OF_print,
	SEQUENCE_OF_constraint,
	SEQUENCE_OF_decode_ber,
	SEQUENCE_OF_encode_der,
	SEQUENCE_OF_decode_xer,
	SEQUENCE_OF_encode_xer,
	SEQUENCE_OF_decode_uper,
	SEQUENCE_OF_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_gpsPosition_tags_5,
	sizeof(asn_DEF_gpsPosition_tags_5)
		/sizeof(asn_DEF_gpsPosition_tags_5[0]) - 1, /* 1 */
	asn_DEF_gpsPosition_tags_5,	/* Same as above */
	sizeof(asn_DEF_gpsPosition_tags_5)
		/sizeof(asn_DEF_gpsPosition_tags_5[0]), /* 2 */
	&asn_PER_type_gpsPosition_constr_5,
	asn_MBR_gpsPosition_5,
	1,	/* Single element */
	&asn_SPC_gpsPosition_specs_5	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_basicVehicleStatus_7[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_RvsBasicStatus,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		""
		},
};
static const ber_tlv_tag_t asn_DEF_basicVehicleStatus_tags_7[] = {
	(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_basicVehicleStatus_specs_7 = {
	sizeof(struct basicVehicleStatus),
	offsetof(struct basicVehicleStatus, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_basicVehicleStatus_7 = {
	"basicVehicleStatus",
	"basicVehicleStatus",
	SEQUENCE_OF_free,
	SEQUENCE_OF_print,
	SEQUENCE_OF_constraint,
	SEQUENCE_OF_decode_ber,
	SEQUENCE_OF_encode_der,
	SEQUENCE_OF_decode_xer,
	SEQUENCE_OF_encode_xer,
	SEQUENCE_OF_decode_uper,
	SEQUENCE_OF_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_basicVehicleStatus_tags_7,
	sizeof(asn_DEF_basicVehicleStatus_tags_7)
		/sizeof(asn_DEF_basicVehicleStatus_tags_7[0]) - 1, /* 1 */
	asn_DEF_basicVehicleStatus_tags_7,	/* Same as above */
	sizeof(asn_DEF_basicVehicleStatus_tags_7)
		/sizeof(asn_DEF_basicVehicleStatus_tags_7[0]), /* 2 */
	&asn_PER_type_basicVehicleStatus_constr_7,
	asn_MBR_basicVehicleStatus_7,
	1,	/* Single element */
	&asn_SPC_basicVehicleStatus_specs_7	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_RmtCtrlStRespInfo_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RmtCtrlStRespInfo, rvcReqType),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_rvcReqType_constraint_1,
		&asn_PER_memb_rvcReqType_constr_2,
		0,
		"rvcReqType"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RmtCtrlStRespInfo, rvcReqStatus),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_rvcReqStatus_constraint_1,
		&asn_PER_memb_rvcReqStatus_constr_3,
		0,
		"rvcReqStatus"
		},
	{ ATF_POINTER, 1, offsetof(struct RmtCtrlStRespInfo, rvcFailureType),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_rvcFailureType_constraint_1,
		&asn_PER_memb_rvcFailureType_constr_4,
		0,
		"rvcFailureType"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RmtCtrlStRespInfo, gpsPosition),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		0,
		&asn_DEF_gpsPosition_5,
		memb_gpsPosition_constraint_1,
		&asn_PER_memb_gpsPosition_constr_5,
		0,
		"gpsPosition"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RmtCtrlStRespInfo, basicVehicleStatus),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		0,
		&asn_DEF_basicVehicleStatus_7,
		memb_basicVehicleStatus_constraint_1,
		&asn_PER_memb_basicVehicleStatus_constr_7,
		0,
		"basicVehicleStatus"
		},
};
static const int asn_MAP_RmtCtrlStRespInfo_oms_1[] = { 2 };
static const ber_tlv_tag_t asn_DEF_RmtCtrlStRespInfo_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_RmtCtrlStRespInfo_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* rvcReqType */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* rvcReqStatus */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* rvcFailureType */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* gpsPosition */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* basicVehicleStatus */
};
static asn_SEQUENCE_specifics_t asn_SPC_RmtCtrlStRespInfo_specs_1 = {
	sizeof(struct RmtCtrlStRespInfo),
	offsetof(struct RmtCtrlStRespInfo, _asn_ctx),
	asn_MAP_RmtCtrlStRespInfo_tag2el_1,
	5,	/* Count of tags in the map */
	asn_MAP_RmtCtrlStRespInfo_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_RmtCtrlStRespInfo = {
	"RmtCtrlStRespInfo",
	"RmtCtrlStRespInfo",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_RmtCtrlStRespInfo_tags_1,
	sizeof(asn_DEF_RmtCtrlStRespInfo_tags_1)
		/sizeof(asn_DEF_RmtCtrlStRespInfo_tags_1[0]), /* 1 */
	asn_DEF_RmtCtrlStRespInfo_tags_1,	/* Same as above */
	sizeof(asn_DEF_RmtCtrlStRespInfo_tags_1)
		/sizeof(asn_DEF_RmtCtrlStRespInfo_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_RmtCtrlStRespInfo_1,
	5,	/* Elements count */
	&asn_SPC_RmtCtrlStRespInfo_specs_1	/* Additional specs */
};
