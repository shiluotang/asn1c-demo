#include <iomanip>
#include <ostream>
#include <string>

#include "misc.hpp"
#include "bytes.hpp"

namespace asn1cxx {

    bytes::bytes() :_M_data(0) { }

    bytes::bytes(bytes const &other): _M_data(other._M_data) {}

    bytes::bytes(std::string const &s) :_M_data(s.begin(), s.end()) { }

    bytes::bytes(void const* buffer, size_t buflen)
        :_M_data(static_cast<byte const*>(buffer),
                static_cast<byte const*>(buffer) + buflen)
    {
    }

    void* bytes::address() { return &_M_data[0]; }

    void const* bytes::address() const { return &_M_data[0]; }

    size_t bytes::size() const { return _M_data.size(); }

    void bytes::assign(void const *buffer, size_t buflen) {
        if (_M_data.size() != buflen)
            _M_data.resize(buflen);
        byte const *p = static_cast<byte const*>(buffer);
        std::copy(p, p + buflen, _M_data.begin());
    }

    void bytes::append(void const *buffer, size_t buflen) {
        int pos = _M_data.size();
        _M_data.resize(_M_data.size() + buflen);
        byte const *p = static_cast<byte const*>(buffer);
        std::copy(p, p + buflen, &_M_data[pos]);
    }

    void bytes::append(bytes const &other) {
        this->append(other.address(), other.size());
    }

    bytes bytes::sub(size_t offset, size_t len) const {
        size_t n = this->size();
        if (offset >= n || len + offset > n)
            return bytes();
        std::vector<byte> b(len);
        std::copy_n(&_M_data[offset], len, &b[0]);
        return bytes(&b[0], b.size());
    }

    bytes bytes::sub(size_t offset) const {
        size_t n = this->size();
        return sub(offset, n - offset);
    }

    bytes& bytes::operator = (bytes const &other) {
        if (this == &other)
            return *this;
        this->assign(other.address(), other.size());
        return *this;
    }

    bytes& bytes::operator += (bytes const &other) {
        this->append(other);
        return *this;
    }

    bytes bytes::operator + (bytes const &other) const {
        bytes copy(*this);
        copy.append(other);
        return copy;
    }

    bool bytes::operator == (bytes const &other) const {
        return _M_data == other._M_data;
    }

    bool bytes::operator != (bytes const &other) const {
        return _M_data != other._M_data;
    }

    bool bytes::operator < (bytes const &other) const {
        return _M_data < other._M_data;
    }

    std::ostream& operator << (std::ostream &os, bytes const &b) {
        misc::ios_guarder::guard(os);
        typedef bytes::byte byte;
        os << std::hex << std::uppercase << std::setfill('0');
        for (byte const* p = static_cast<byte const*>(b.address()),
                *end = p + b.size(); p != end; ++p) {
            os << std::setw(2) << static_cast<unsigned int>(*p);
        }
        return os;
    }
}
