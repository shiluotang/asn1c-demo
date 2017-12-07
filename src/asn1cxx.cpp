#include <iomanip>
#include <iostream>
#include <sstream>
#include <ios>
#include <ostream>
#include <string>

#include "asn1cxx.hpp"

namespace {
    template <typename CharT>
    struct basic_ios_guard {
        typedef std::basic_ios<CharT> xios;

        basic_ios_guard(xios &stream)
            :_M_stream_ref(stream),
            _M_flags(stream.flags()),
            _M_fillchar(stream.fill()),
            _M_precision(stream.precision())
        {
        }

        ~basic_ios_guard() {
            _M_stream_ref.flags(_M_flags);
            _M_stream_ref.fill(_M_fillchar);
            _M_stream_ref.precision(_M_precision);
        }

        xios &_M_stream_ref;
        typename xios::fmtflags _M_flags;
        typename xios::char_type _M_fillchar;
        std::streamsize _M_precision;
    };

    typedef basic_ios_guard<char> ios_guard;
    typedef basic_ios_guard<wchar_t> wios_guard;

    int xer_encode_callback(const void *buffer, size_t size, void *application_specific_key) {
        std::stringstream &ss = *reinterpret_cast<std::stringstream*>(application_specific_key);
        ss << std::string(reinterpret_cast<char const*>(buffer), size);
        return ss ? 0 : -1;
    }
}

namespace asn1cxx {

    std::ostream& operator << (std::ostream &os, memblock const &block) {
        ios_guard guarder(os);
        os << std::hex << std::setfill('0');

        for (memblock::byte const* p = reinterpret_cast<memblock::byte const*>(block.address()),
                *end = p + block.size(); p != end; ++p) {
            os << std::setw(2) << static_cast<unsigned int>(*p);
        }
        return os;
    }

    std::string xer_codec::encode0(asn_TYPE_descriptor_t &td, void *node) {
        std::stringstream ss;
        asn_enc_rval_t rval = ::xer_encode(&td, node, XER_F_CANONICAL, &xer_encode_callback, &ss);
        if (rval.encoded == -1) {
            std::stringstream es;
            es << "Failed to encode " << rval.failed_type->name;
            throw std::runtime_error(es.str());
        }
        return ss.str();
    }

    void* xer_codec::decode0(asn_TYPE_descriptor_t &td, memblock const &block) {
        void *buffer = NULL;
        asn_dec_rval_t rval = ::xer_decode(NULL, &td, &buffer, block.address(), block.size());
        if (rval.code != RC_OK) {
            if (buffer) {
                ASN_STRUCT_FREE(td, buffer);
                buffer = NULL;
            }
        }
        return buffer;
    }

    ssize_t uper_codec::encode0(asn_TYPE_descriptor_t &td, void *node, void **buffer) {
        char errbuf[0xff];
        size_t errlen = sizeof(errbuf);
        void *buffer_r = NULL;

        if (::asn_check_constraints(&td, node, &errbuf[0], &errlen) != 0)
            throw std::runtime_error(std::string(&errbuf[0], errlen));
        ssize_t n = ::uper_encode_to_new_buffer(&td, NULL, node, &buffer_r);
        if (n == -1) {
            if (buffer_r) {
                FREEMEM(buffer_r);
                buffer_r = NULL;
            }
        }
        *buffer = buffer_r;
        return n;
    }

    void* uper_codec::decode0(asn_TYPE_descriptor_t &td, memblock const &block) {
        void *node = NULL;
        asn_dec_rval_t rval = ::uper_decode_complete(NULL, &td, &node, block.address(), block.size());
        if (rval.code != RC_OK) {
            if (node) {
                ASN_STRUCT_FREE(td, node);
                node = NULL;
            }
        }
        return node;
    }
}
