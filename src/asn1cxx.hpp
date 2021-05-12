#ifndef ASN1CXX_HPP_INCLUDED
#define ASN1CXX_HPP_INCLUDED

#include <vector>
#include <string>
#include <ostream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <iosfwd>
#include <memory>
#include <utility>

#include <asn_internal.h>
#include <asn_application.h>

#include "bytes.hpp"
#include "refcnt_ptr.hpp"

namespace asn1cxx {
    class asn1c_deleter: public deleter {
    public:
        asn1c_deleter(asn_TYPE_descriptor_t *td): _M_td(td) { }

        void operator() (void *p) {
            if (_M_td)
                ASN_STRUCT_FREE(*_M_td, p);
            else
                FREEMEM(p);
        }
    private:
        asn_TYPE_descriptor_t *_M_td;
    };

    class uper_codec {
    public:
        //typedef int (asn_app_consume_bytes_f)(const void *buffer, size_t size,
        //    void *application_specific_key);
        static int consume(void const*, size_t, void*);

        template <typename T>
        bytes
        encode(T const&, asn_TYPE_descriptor_t*);

        template <typename T>
        refcnt_ptr<T>
        decode(bytes const&, asn_TYPE_descriptor_t*);
    };

    template <typename T>
    bytes
    uper_codec::encode(T const &pdu, asn_TYPE_descriptor_t *td) {
        bytes b;
        asn_enc_rval_t rval = uper_encode(
                td,
                static_cast<void*>(const_cast<T*>(&pdu)),
                &uper_codec::consume,
                &b);
        if (rval.encoded == -1) {
            std::ostringstream es;
            es << "failed to encode " << rval.failed_type->name;
            throw std::runtime_error(es.str());
        }
        return b;
    }

    template <typename T>
    refcnt_ptr<T>
    uper_codec::decode(bytes const &uper, asn_TYPE_descriptor_t *td) {
        T *pdu = NULL;
        refcnt_ptr<T> p;
        asn_dec_rval_t rval = uper_decode_complete(
                NULL,
                td,
                reinterpret_cast<void**>(&pdu),
                uper.address(),
                uper.size());
        refcnt_ptr<T> pp(pdu, new asn1c_deleter(td));
        p.swap(pp);
        if (rval.code != RC_OK) {
            std::ostringstream es;
            es << "failed to decode " << td->name;
            throw std::runtime_error(es.str());
        }
        return p;
    }

    class xer_codec {
    public:
        xer_codec(xer_encoder_flags_e flags = XER_F_CANONICAL)
            :_M_flags(flags) {
        }

        //typedef int (asn_app_consume_bytes_f)(const void *buffer, size_t size,
        //    void *application_specific_key);
        static int consume(void const*, size_t, void*);

        template <typename T>
        std::string
        encode(T const&, asn_TYPE_descriptor_t*);

        template <typename T>
        refcnt_ptr<T>
        decode(std::string const&, asn_TYPE_descriptor_t*);
    private:
        xer_encoder_flags_e _M_flags;
    };

    template <typename T>
    std::string
    xer_codec::encode(T const &pdu, asn_TYPE_descriptor_t *td) {
        std::ostringstream oss;
        asn_enc_rval_t rval = xer_encode(
                td,
                const_cast<T*>(&pdu),
                _M_flags,
                &xer_codec::consume,
                &oss);
        if (rval.encoded == -1) {
            std::ostringstream es;
            es << "failed to encode " << rval.failed_type->name;
            throw std::runtime_error(es.str());
        }
        return oss.str();
    }

    template <typename T>
    refcnt_ptr<T>
    xer_codec::decode(std::string const &xer, asn_TYPE_descriptor_t *td) {
        refcnt_ptr<T> p;
        T *pdu = NULL;
        asn_dec_rval_t rval = xer_decode(
                NULL,
                td,
                reinterpret_cast<void**>(&pdu),
                xer.c_str(),
                xer.size());
        // FIXME use ASN_STRUCT_FREE deleter
        refcnt_ptr<T> pp(pdu, new asn1c_deleter(td));
        p.swap(pp);
        if (rval.code != RC_OK) {
            std::ostringstream es;
            es << "failed to decode " << td->name;
            throw std::runtime_error(es.str());
        }
        return p;
    }

    class asn_codec {
    public:
    };
}

#endif // ASN1CXX_HPP_INCLUDED
