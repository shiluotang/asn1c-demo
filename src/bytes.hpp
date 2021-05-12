#ifndef BYTES_HPP_INCLUDED
#define BYTES_HPP_INCLUDED

#include <cstdlib>

#include <iosfwd>
#include <string>
#include <memory>
#include <utility>
#include <vector>
#include <algorithm>

namespace asn1cxx {

    class bytes {
    public:
        // typedefs
        typedef unsigned char byte;
    public:
        bytes();
        bytes(bytes const&);
        bytes(std::string const &s);
        bytes(void const*, size_t);

        template <typename T, size_t N>
        bytes(T const (&a)[N]);

        void* address();
        void const* address() const;
        size_t size() const;

        void assign(void const*, size_t);
        void append(void const*, size_t);
        void append(bytes const&);
        bytes sub(size_t, size_t) const;
        bytes sub(size_t) const;

        bytes& operator = (bytes const&);
        bytes& operator += (bytes const&);

        bytes operator + (bytes const&) const;

        bool operator == (bytes const&) const;
        bool operator != (bytes const&) const;
        bool operator < (bytes const&) const;
    private:
        std::vector<byte> _M_data;
    };

    template <typename T, size_t N>
    bytes::bytes(T const (&a)[N])
        : _M_data(static_cast<byte const*>(&a[0]),
                static_cast<byte const*>(&a[0]) + sizeof(T) * N)
    {
    }

    extern std::ostream& operator << (std::ostream&, bytes const&);
}

#endif // BYTES_HPP_INCLUDED
