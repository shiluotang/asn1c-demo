#ifndef ASN1CXX_HPP_INCLUDED
#define ASN1CXX_HPP_INCLUDED

#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iosfwd>
#include <memory>
#include <utility>

#include <asn_application.h>
#include <asn_internal.h>

namespace asn1cxx {

    class memblock {
    public:
        typedef unsigned char byte;

        memblock()
            :_M_data(0),
            _M_size(_M_data.size())
        { }

        template <typename T, size_t N>
        memblock(T const (&a)[N])
            : _M_data(reinterpret_cast<byte const*>(&a[0]), reinterpret_cast<byte const*>(&a[0]) + sizeof(T) * N),
            _M_size(_M_data.size())
        {
        }

        memblock(std::string const &s)
            :_M_data(s.begin(), s.end()),
            _M_size(_M_data.size())
        {
        }

        memblock(void const* buffer, size_t buflen)
            :_M_data(reinterpret_cast<byte const*>(buffer), reinterpret_cast<byte const*>(buffer) + buflen),
            _M_size(_M_data.size())
        {
        }

        void* address() { return &_M_data[0]; }

        void const* address() const { return &_M_data[0]; }

        size_t size() const { return _M_size; }

        void assign(void const *buffer, size_t buflen) {
            if (_M_data.size() < buflen)
                _M_data.resize(buflen);
            byte const *p = reinterpret_cast<byte const*>(buffer);
            std::copy(p, p + buflen, _M_data.begin());
            _M_size = buflen;
        }
    private:
        std::vector<byte> _M_data;
        std::size_t _M_size;
    };

    std::ostream& operator << (std::ostream&, memblock const&);


    template <typename T> struct asn1c_ptr;
    template <typename T>
    struct asn1c_ptr_ref {
        typedef typename asn1c_ptr<T>::asn1c_struct value_type;
        typedef value_type *pointer;

        asn1c_ptr_ref(pointer ptr) :_M_ptr(ptr) { }

        pointer _M_ptr;
    };

    template <typename T>
    struct asn1c_ptr {

        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;

        struct asn1c_struct {
            explicit asn1c_struct(asn_TYPE_descriptor_t *td, T *struct_ptr)
                : _M_td(td),
                _M_struct_ptr(struct_ptr)
            {
            }

            ~asn1c_struct() {
                if (_M_struct_ptr && _M_td) {
                    ASN_STRUCT_FREE(*_M_td, _M_struct_ptr);
                    _M_struct_ptr = NULL;
                }
            }

            asn_TYPE_descriptor_t *_M_td;
            T *_M_struct_ptr;
        };

        asn1c_ptr(asn_TYPE_descriptor_t &td, T *p)
            : _M_ptr(new asn1c_struct(&td, p))
        {
        }

        asn1c_ptr(asn1c_ptr_ref<T> ref) :_M_ptr(ref._M_ptr) { }

        operator asn1c_ptr_ref<T> () {
            return asn1c_ptr_ref<T>(_M_ptr.release());
        }

        // pointer operation overload
        reference operator * () { return *_M_ptr.get()->_M_struct_ptr; }

        pointer operator -> () { return _M_ptr ? _M_ptr.get()->_M_struct_ptr : NULL; }

        pointer get() { return _M_ptr ? _M_ptr.get()->_M_struct_ptr : NULL; }

        std::auto_ptr<asn1c_struct> _M_ptr;
    };

    class uper_codec {
    private:
        struct asn1c_pointer_guard {
            asn1c_pointer_guard(void *ptr) :_M_ptr(ptr) { }
            ~asn1c_pointer_guard() {
                if (_M_ptr) {
                    FREEMEM(_M_ptr);
                    _M_ptr = NULL;
                }
            }
            void *_M_ptr;
        };

        static ssize_t encode0(asn_TYPE_descriptor_t&, void*, void**buffer);
        static void* decode0(asn_TYPE_descriptor_t&, memblock const&);
    public:
        template <typename T>
        static memblock encode(asn_TYPE_descriptor_t &td, T const &node) {
            void *buffer = NULL;
            ssize_t n = 0;

            T dup = node;
            n = encode0(td, &dup, &buffer);
            asn1c_pointer_guard guarder(buffer);
            return memblock(buffer, n);
        }

        template <typename T>
        static asn1c_ptr<T> decode(asn_TYPE_descriptor_t &td, memblock const &block) {
            T *p = reinterpret_cast<T*>(decode0(td, block));
            if (!p)
                throw std::runtime_error("Failed to decode uper data!");
            return asn1c_ptr<T>(td, p);
        }
    };

    class xer_codec {
    private:
        static std::string encode0(asn_TYPE_descriptor_t&, void*);
        static void* decode0(asn_TYPE_descriptor_t&, memblock const&);

    public:
        template <typename T>
        static std::string encode(asn_TYPE_descriptor_t &td, T const &node) {
            T dup = node;
            return encode0(td, &dup);
        }

        template <typename T>
        static asn1c_ptr<T> decode(asn_TYPE_descriptor_t &td, memblock const &node) {
            T *p = reinterpret_cast<T*>(decode0(td, node));
            if (!p)
                throw std::runtime_error("Failed decode xer data!");
            return asn1c_ptr<T>(td, p);
        }
    };
}

#endif // ASN1CXX_HPP_INCLUDED
