#ifndef REFCNT_PTR_HPP_INCLUDED
#define REFCNT_PTR_HPP_INCLUDED

#include <cstdlib>
#include <cstddef>

#include <utility>

namespace asn1cxx {
    struct deleter {
    public:
        virtual ~deleter() {}
    public:
        virtual void operator() (void *p) {
            if (p)
                std::free(p);
        };
    };

    template <typename T>
    struct typed_deleter :deleter {
    public:
        virtual void operator() (void *p) {
            deallocate(static_cast<T*>(p));
        }

        void deallocate(T *p) {
            if (p)
                delete p;
        }
    };

    template <typename T>
    struct typed_deleter<T[]> :deleter {
    public:
        void deallocate(T *p) {
            if (p)
                delete[] p;
        }
    };

    template <typename T>
    class refcnt_ptr {
    public:
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;
        typedef T const *const_pointer;
        typedef T const &const_reference;
    public:
        explicit refcnt_ptr(pointer = NULL, deleter* = new typed_deleter<T>());
        refcnt_ptr(refcnt_ptr<T> const&);
        virtual ~refcnt_ptr();

        pointer get() const;
        size_t use_count() const;
        void reset();
        void reset(pointer);
        void swap(refcnt_ptr<T>&);

        refcnt_ptr<T>& operator=(refcnt_ptr<T> const&);
        refcnt_ptr<T>& operator=(pointer);
        pointer operator->() const;
        reference operator*() const;
        operator bool() const;
        bool operator==(refcnt_ptr<T> const&) const;
        std::ptrdiff_t operator-(refcnt_ptr<T> const&) const;
        std::ptrdiff_t operator-(pointer) const;

    protected:
        void increase_count();
        void decrease_count();
    private:
        T *_M_ptr;
        size_t *_M_count;
        deleter *_M_deleter;
    };

    template <typename T>
    refcnt_ptr<T>::refcnt_ptr(T *p, deleter *d)
        : _M_ptr(p)
        , _M_count(new size_t(1))
        , _M_deleter(d)
    { }

    template <typename T>
    refcnt_ptr<T>::refcnt_ptr(refcnt_ptr<T> const &other)
        : _M_ptr(other._M_ptr)
        , _M_count(other._M_count)
        , _M_deleter(other._M_deleter)
    {
        increase_count();
    }

    template <typename T>
    refcnt_ptr<T>::~refcnt_ptr() {
        decrease_count();
        if (*_M_count == 0) {
            delete _M_count;
            _M_count = NULL;
        }
        if (_M_deleter) {
            delete _M_deleter;
            _M_deleter = NULL;
        }
    }

    template <typename T>
    void
    refcnt_ptr<T>::increase_count() {
        ++*_M_count;
    }

    template <typename T>
    void
    refcnt_ptr<T>::decrease_count() {
        if (_M_count) {
            size_t &count = *_M_count;
            if (--count == 0) {
                if (_M_ptr) {
                    (*_M_deleter)(_M_ptr);
                    _M_ptr = NULL;
                }
            }
        }
    }

    template <typename T>
    typename refcnt_ptr<T>::pointer
    refcnt_ptr<T>::get() const {
        return _M_ptr;
    }

    template <typename T>
    size_t
    refcnt_ptr<T>::use_count() const {
        return _M_ptr;
    }

    template <typename T>
    void
    refcnt_ptr<T>::reset() {
        refcnt_ptr<T> p(NULL);
        this->swap(p);
    }

    template <typename T>
    void
    refcnt_ptr<T>::reset(typename refcnt_ptr<T>::pointer p) {
        refcnt_ptr<T> pp(p);
        this->swap(pp);
    }

    template <typename T>
    void
    refcnt_ptr<T>::swap(refcnt_ptr<T> &other) {
        std::swap(this->_M_ptr, other._M_ptr);
        std::swap(this->_M_count, other._M_count);
        std::swap(this->_M_deleter, other._M_deleter);
    }

    template <typename T>
    refcnt_ptr<T>&
    refcnt_ptr<T>::operator = (refcnt_ptr<T> const &other) {
        refcnt_ptr<T> p(other);
        this->swap(p);
        return *this;
    }

    template <typename T>
    refcnt_ptr<T>&
    refcnt_ptr<T>::operator = (refcnt_ptr<T>::pointer ptr) {
        refcnt_ptr<T> p(ptr);
        this->swap(p);
        return *this;
    }

    template <typename T>
    typename refcnt_ptr<T>::pointer
    refcnt_ptr<T>::operator -> () const {
        return _M_ptr;
    }

    template <typename T>
    typename refcnt_ptr<T>::reference
    refcnt_ptr<T>::operator * () const {
        return *_M_ptr;
    }

    template <typename T>
    refcnt_ptr<T>::operator bool() const {
        return _M_ptr
            && _M_count
            && *_M_count > 0;
    }

    template <typename T>
    bool
    refcnt_ptr<T>::operator == (refcnt_ptr<T> const &other) const {
        if (this == &other)
            return true;
        if (this->_M_ptr == other._M_ptr)
            return true;
        return false;
    }

    template <typename T>
    std::ptrdiff_t
    refcnt_ptr<T>::operator - (refcnt_ptr<T> const &other) const {
        return _M_ptr - other._M_ptr;
    }

    template <typename T>
    std::ptrdiff_t
    refcnt_ptr<T>::operator - (refcnt_ptr<T>::pointer p) const {
        return _M_ptr - p;
    }
}

#endif // REFCNT_PTR_HPP_INCLUDED
