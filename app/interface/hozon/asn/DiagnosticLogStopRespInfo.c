/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "HOZON"
 * 	found in "HOZON_PRIV_v1.0.asn"
 * 	`asn1c -gen-PER`
 */

#include "DiagnosticLogStopRespInfo.h"

static int
memb_ecuType_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
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
memb_failureType_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
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

static asn_per_constraints_t asn_PER_memb_ecuType_constr_2 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 8,  8,  0,  255 }	/* (0..255) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_failureType_constr_4 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 8,  8,  0,  255 }	/* (0..255) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_DiagnosticLogStopRespInfo_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct DiagnosticLogStopRespInfo, ecuType),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_ecuType_constraint_1,
		&asn_PER_memb_ecuType_constr_2,
		0,
		"ecuType"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct DiagnosticLogStopRespInfo, result),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"result"
		},
	{ ATF_POINTER, 1, offsetof(struct DiagnosticLogStopRespInfo, failureType),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_failureType_constraint_1,
		&asn_PER_memb_failureType_constr_4,
		0,
		"failureType"
		},
};
static const int asn_MAP_DiagnosticLogStopRespInfo_oms_1[] = { 2 };
static const ber_tlv_tag_t asn_DEF_DiagnosticLogStopRespInfo_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_DiagnosticLogStopRespInfo_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ecuType */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* result */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* failureType */
};
static asn_SEQUENCE_specifics_t asn_SPC_DiagnosticLogStopRespInfo_specs_1 = {
	sizeof(struct DiagnosticLogStopRespInfo),
	offsetof(struct DiagnosticLogStopRespInfo, _asn_ctx),
	asn_MAP_DiagnosticLogStopRespInfo_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_DiagnosticLogStopRespInfo_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_DiagnosticLogStopRespInfo = {
	"DiagnosticLogStopRespInfo",
	"DiagnosticLogStopRespInfo",
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
	asn_DEF_DiagnosticLogStopRespInfo_tags_1,
	sizeof(asn_DEF_DiagnosticLogStopRespInfo_tags_1)
		/sizeof(asn_DEF_DiagnosticLogStopRespInfo_tags_1[0]), /* 1 */
	asn_DEF_DiagnosticLogStopRespInfo_tags_1,	/* Same as above */
	sizeof(asn_DEF_DiagnosticLogStopRespInfo_tags_1)
		/sizeof(asn_DEF_DiagnosticLogStopRespInfo_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_DiagnosticLogStopRespInfo_1,
	3,	/* Elements count */
	&asn_SPC_DiagnosticLogStopRespInfo_specs_1	/* Additional specs */
};

