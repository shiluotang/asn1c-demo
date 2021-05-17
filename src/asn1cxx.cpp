#include <iomanip>
#include <iostream>
#include <sstream>
#include <ios>
#include <ostream>
#include <string>

#include "asn1cxx.hpp"

namespace asn1cxx {
    int uper_codec::consume(
            void const *buffer,
            size_t size,
            void *key) {
        bytes &b = *static_cast<bytes*>(key);
        // allow runtime exception?
        b.append(buffer, size);
        return 0;
    }

    int xer_codec::consume(
            void const *buffer,
            size_t size,
            void *key) {
        std::ostringstream &oss = *static_cast<std::ostringstream*>(key);
        oss.write(static_cast<char const*>(buffer), size);
        return !!oss ? 0 : -1;
    }

    int asn_codec::consume(
            void const *buffer,
            size_t size,
            void *key) {
        std::ostringstream &oss = *static_cast<std::ostringstream*>(key);
        oss.write(static_cast<char const*>(buffer), size);
        return !!oss ? 0 : -1;
    }
}
