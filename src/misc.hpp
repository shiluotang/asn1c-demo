#ifndef MISC_HPP_INCLUDED
#define MISC_HPP_INCLUDED

#include <ios>
#include <sstream>
#include <locale>

namespace misc {
    template <typename CharT>
    struct basic_ios_guarder {
        typedef CharT char_type;
        typedef std::basic_ios<CharT> xios;

        explicit basic_ios_guarder(xios &stream)
            : _M_stream_ref(stream)
            , _M_flags(stream.flags())
            , _M_fillchar(stream.fill())
            , _M_precision(stream.precision())
            , _M_width(stream.width())
            , _M_locale(stream.getloc())
        {
        }

        ~basic_ios_guarder() {
            _M_stream_ref.flags(_M_flags);
            _M_stream_ref.fill(_M_fillchar);
            _M_stream_ref.precision(_M_precision);
            _M_stream_ref.width(_M_width);
            _M_stream_ref.imbue(_M_locale);
        }

        template <typename T>
        static basic_ios_guarder<T>
        guard(std::basic_ios<T> &ios) {
            return basic_ios_guarder<T>(ios);
        }

        xios &_M_stream_ref;
        typename xios::fmtflags _M_flags;
        typename xios::char_type _M_fillchar;
        std::streamsize _M_precision;
        std::streamsize _M_width;
        std::locale _M_locale;
    };

    typedef basic_ios_guarder<char> ios_guarder;
    typedef basic_ios_guarder<wchar_t> wios_guarder;

    template <typename U, typename V>
    U sstream_cast(V const &val) {
        U u;
        std::stringstream ss;
        ss << val;
        ss >> u;
        return u;
    }

    template <typename T, size_t N> size_t countof(T (&a)[N]) { return N; }
}

#endif // MISC_HPP_INCLUDED
