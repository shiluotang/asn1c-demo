/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "Test"
 * 	found in "/Users/shengquangang/Documents/asn-xsd-test/asn/test.asn"
 * 	`asn1c -fcompound-names -gen-PER`
 */

#ifndef	_FTag_H_
#define	_FTag_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <NativeInteger.h>
#include <VisibleString.h>
#include <constr_SEQUENCE.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* FTag */
typedef struct FTag {
	A_SEQUENCE_OF(struct FTag__Member {
		long	 s1;
		VisibleString_t	 s2;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} ) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} FTag_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_FTag;

#ifdef __cplusplus
}
#endif

#endif	/* _FTag_H_ */
#include <asn_internal.h>