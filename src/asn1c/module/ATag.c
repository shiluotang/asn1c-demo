/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "Test"
 * 	found in "/Users/shengquangang/Documents/asn-xsd-test/asn/test.asn"
 * 	`asn1c -fcompound-names -gen-PER`
 */

#include "ATag.h"

static int
a5_13_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	/* Replace with underlying type checker */
	td->check_constraints = asn_DEF_NativeEnumerated.check_constraints;
	return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static void
a5_13_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
	td->free_struct    = asn_DEF_NativeEnumerated.free_struct;
	td->print_struct   = asn_DEF_NativeEnumerated.print_struct;
	td->check_constraints = asn_DEF_NativeEnumerated.check_constraints;
	td->ber_decoder    = asn_DEF_NativeEnumerated.ber_decoder;
	td->der_encoder    = asn_DEF_NativeEnumerated.der_encoder;
	td->xer_decoder    = asn_DEF_NativeEnumerated.xer_decoder;
	td->xer_encoder    = asn_DEF_NativeEnumerated.xer_encoder;
	td->uper_decoder   = asn_DEF_NativeEnumerated.uper_decoder;
	td->uper_encoder   = asn_DEF_NativeEnumerated.uper_encoder;
	if(!td->per_constraints)
		td->per_constraints = asn_DEF_NativeEnumerated.per_constraints;
	td->elements       = asn_DEF_NativeEnumerated.elements;
	td->elements_count = asn_DEF_NativeEnumerated.elements_count;
     /* td->specifics      = asn_DEF_NativeEnumerated.specifics;	// Defined explicitly */
}

static void
a5_13_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	a5_13_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
a5_13_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	a5_13_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
a5_13_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	a5_13_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
a5_13_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	a5_13_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
a5_13_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	a5_13_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
a5_13_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	a5_13_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
a5_13_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	a5_13_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
a5_13_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	a5_13_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static asn_per_constraints_t asn_PER_type_a5_constr_13 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  3 }	/* (0..3) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_aa3_5[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ATag__a1__aa3, aaa1),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"aaa1"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ATag__a1__aa3, aaa2),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_VisibleString,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"aaa2"
		},
};
static ber_tlv_tag_t asn_DEF_aa3_tags_5[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_aa3_tag2el_5[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* aaa1 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* aaa2 */
};
static asn_SEQUENCE_specifics_t asn_SPC_aa3_specs_5 = {
	sizeof(struct ATag__a1__aa3),
	offsetof(struct ATag__a1__aa3, _asn_ctx),
	asn_MAP_aa3_tag2el_5,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_aa3_5 = {
	"aa3",
	"aa3",
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
	asn_DEF_aa3_tags_5,
	sizeof(asn_DEF_aa3_tags_5)
		/sizeof(asn_DEF_aa3_tags_5[0]) - 1, /* 1 */
	asn_DEF_aa3_tags_5,	/* Same as above */
	sizeof(asn_DEF_aa3_tags_5)
		/sizeof(asn_DEF_aa3_tags_5[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_aa3_5,
	2,	/* Elements count */
	&asn_SPC_aa3_specs_5	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_a1_2[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ATag__a1, aa1),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_VisibleString,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"aa1"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ATag__a1, aa2),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"aa2"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ATag__a1, aa3),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		0,
		&asn_DEF_aa3_5,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"aa3"
		},
};
static ber_tlv_tag_t asn_DEF_a1_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_a1_tag2el_2[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* aa1 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* aa2 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* aa3 */
};
static asn_SEQUENCE_specifics_t asn_SPC_a1_specs_2 = {
	sizeof(struct ATag__a1),
	offsetof(struct ATag__a1, _asn_ctx),
	asn_MAP_a1_tag2el_2,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_a1_2 = {
	"a1",
	"a1",
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
	asn_DEF_a1_tags_2,
	sizeof(asn_DEF_a1_tags_2)
		/sizeof(asn_DEF_a1_tags_2[0]) - 1, /* 1 */
	asn_DEF_a1_tags_2,	/* Same as above */
	sizeof(asn_DEF_a1_tags_2)
		/sizeof(asn_DEF_a1_tags_2[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_a1_2,
	3,	/* Elements count */
	&asn_SPC_a1_specs_2	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_Member_11[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (26 << 2)),
		0,
		&asn_DEF_VisibleString,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		""
		},
};
static ber_tlv_tag_t asn_DEF_Member_tags_11[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (17 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_Member_specs_11 = {
	sizeof(struct ATag__a4__Member),
	offsetof(struct ATag__a4__Member, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_Member_11 = {
	"SET OF",
	"SET_OF",
	SET_OF_free,
	SET_OF_print,
	SET_OF_constraint,
	SET_OF_decode_ber,
	SET_OF_encode_der,
	SET_OF_decode_xer,
	SET_OF_encode_xer,
	SET_OF_decode_uper,
	SET_OF_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_Member_tags_11,
	sizeof(asn_DEF_Member_tags_11)
		/sizeof(asn_DEF_Member_tags_11[0]), /* 1 */
	asn_DEF_Member_tags_11,	/* Same as above */
	sizeof(asn_DEF_Member_tags_11)
		/sizeof(asn_DEF_Member_tags_11[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_Member_11,
	1,	/* Single element */
	&asn_SPC_Member_specs_11	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_a4_10[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (17 << 2)),
		0,
		&asn_DEF_Member_11,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		""
		},
};
static ber_tlv_tag_t asn_DEF_a4_tags_10[] = {
	(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_a4_specs_10 = {
	sizeof(struct ATag__a4),
	offsetof(struct ATag__a4, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_a4_10 = {
	"a4",
	"a4",
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
	asn_DEF_a4_tags_10,
	sizeof(asn_DEF_a4_tags_10)
		/sizeof(asn_DEF_a4_tags_10[0]) - 1, /* 1 */
	asn_DEF_a4_tags_10,	/* Same as above */
	sizeof(asn_DEF_a4_tags_10)
		/sizeof(asn_DEF_a4_tags_10[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_a4_10,
	1,	/* Single element */
	&asn_SPC_a4_specs_10	/* Additional specs */
};

static asn_INTEGER_enum_map_t asn_MAP_a5_value2enum_13[] = {
	{ 0,	4,	"val1" },
	{ 1,	4,	"val2" },
	{ 2,	4,	"val3" },
	{ 3,	4,	"val4" }
};
static unsigned int asn_MAP_a5_enum2value_13[] = {
	0,	/* val1(0) */
	1,	/* val2(1) */
	2,	/* val3(2) */
	3	/* val4(3) */
};
static asn_INTEGER_specifics_t asn_SPC_a5_specs_13 = {
	asn_MAP_a5_value2enum_13,	/* "tag" => N; sorted by tag */
	asn_MAP_a5_enum2value_13,	/* N => "tag"; sorted by N */
	4,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_a5_tags_13[] = {
	(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_a5_13 = {
	"a5",
	"a5",
	a5_13_free,
	a5_13_print,
	a5_13_constraint,
	a5_13_decode_ber,
	a5_13_encode_der,
	a5_13_decode_xer,
	a5_13_encode_xer,
	a5_13_decode_uper,
	a5_13_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_a5_tags_13,
	sizeof(asn_DEF_a5_tags_13)
		/sizeof(asn_DEF_a5_tags_13[0]) - 1, /* 1 */
	asn_DEF_a5_tags_13,	/* Same as above */
	sizeof(asn_DEF_a5_tags_13)
		/sizeof(asn_DEF_a5_tags_13[0]), /* 2 */
	&asn_PER_type_a5_constr_13,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_a5_specs_13	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ATag_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ATag, a1),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		0,
		&asn_DEF_a1_2,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"a1"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ATag, a2),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_VisibleString,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"a2"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ATag, a3),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BTag,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"a3"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ATag, a4),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		0,
		&asn_DEF_a4_10,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"a4"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ATag, a5),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_a5_13,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"a5"
		},
};
static ber_tlv_tag_t asn_DEF_ATag_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ATag_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* a1 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* a2 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* a3 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* a4 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* a5 */
};
static asn_SEQUENCE_specifics_t asn_SPC_ATag_specs_1 = {
	sizeof(struct ATag),
	offsetof(struct ATag, _asn_ctx),
	asn_MAP_ATag_tag2el_1,
	5,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_ATag = {
	"ATag",
	"ATag",
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
	asn_DEF_ATag_tags_1,
	sizeof(asn_DEF_ATag_tags_1)
		/sizeof(asn_DEF_ATag_tags_1[0]), /* 1 */
	asn_DEF_ATag_tags_1,	/* Same as above */
	sizeof(asn_DEF_ATag_tags_1)
		/sizeof(asn_DEF_ATag_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_ATag_1,
	5,	/* Elements count */
	&asn_SPC_ATag_specs_1	/* Additional specs */
};

