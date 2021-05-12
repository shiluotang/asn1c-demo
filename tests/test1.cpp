#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <locale>

#include "../src/misc.hpp"
#include "../src/asn1cxx.hpp"

#include <asn_internal.h>
#include <asn_application.h>
#include <BIT_STRING.h>

#include "testkit.hpp"

struct asn1c_deleter {
public:
    void operator() (void *p) {
        if (!p)
            return;
        if (_M_td)
            ASN_STRUCT_FREE(*_M_td, p);
        else
            FREEMEM(p);
    }
private:
    asn_TYPE_descriptor_t *_M_td;
};

template <typename T>
struct asn1c {
    asn1c(T *p, asn_TYPE_descriptor_t *td)
        : _M_ptr(p)
        , _M_td(td)
    {
    }

    T *_M_ptr;
    asn_TYPE_descriptor_t *_M_td;
};

TEST_START {
    using namespace std;
    using namespace asn1cxx;
    using namespace misc;

    uper_codec uper;
    xer_codec xer;

    unsigned char buffer[] = {0xa, 0x0, 0xb, 0x0, 0x0, 0xc, 0x0, 0x0, 0x0, 0xd};

    BIT_STRING_t bits = {0};
    bits.buf = &buffer[0];
    bits.size = sizeof(buffer);

    bytes uper_bytes = uper.encode(bits, &asn_DEF_BIT_STRING);
    cout << uper_bytes << endl;
    refcnt_ptr<BIT_STRING_t> bitstr_ptr = uper.decode<BIT_STRING_t>(uper_bytes, &asn_DEF_BIT_STRING);
    cout << uper.encode(*bitstr_ptr, &asn_DEF_BIT_STRING) << endl;

    for (int i = 0; i < 40; ++i) {
        bits.bits_unused = i;
        string const &xmlstr = xer.encode(bits, &asn_DEF_BIT_STRING);
        cout << "unused bits = " << i << ", " << xmlstr << endl;
        refcnt_ptr<BIT_STRING_t> ptr = xer.decode<BIT_STRING_t>(xmlstr, &asn_DEF_BIT_STRING);
        string const &xmlstr2 = xer.encode(*ptr, &asn_DEF_BIT_STRING);
        cout << "unused bits = " << i << ", " << xmlstr2 << endl;
    }

} TEST_STOP
