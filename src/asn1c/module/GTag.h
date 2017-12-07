/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "Test"
 * 	found in "/Users/shengquangang/Documents/asn-xsd-test/asn/test.asn"
 * 	`asn1c -fcompound-names -gen-PER`
 */

#ifndef	_GTag_H_
#define	_GTag_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <NativeEnumerated.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Member {
	Member_val1	= 0,
	Member_val2	= 1,
	Member_val3	= 2,
	Member_val4	= 3
} e_Member;

/* GTag */
typedef struct GTag {
	A_SEQUENCE_OF(struct GTag__Member {
		A_SEQUENCE_OF(long) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} ) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GTag_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_Member_3;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_GTag;

#ifdef __cplusplus
}
#endif

#endif	/* _GTag_H_ */
#include <asn_internal.h>
