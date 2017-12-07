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

#include "testkit.hpp"

#include "../src/asn1cxx.hpp"

#include <BIT_STRING.h>

TEST_START {
    using namespace std;
    using namespace asn1cxx;

    unsigned char buffer[] = {0xa, 0x0, 0xb, 0x0, 0x0, 0xc, 0x0, 0x0, 0x0, 0xd};

    BIT_STRING_t bits = {0};
    bits.buf = &buffer[0];
    bits.size = sizeof(buffer) / sizeof(buffer[0]);

    memblock uper_bytes = uper_codec::encode(asn_DEF_BIT_STRING, bits);
    cout << uper_bytes << endl;
    asn1c_ptr<BIT_STRING_t> bitstr_ptr = uper_codec::decode<BIT_STRING_t>(asn_DEF_BIT_STRING, uper_bytes);
    cout << uper_codec::encode(asn_DEF_BIT_STRING, *bitstr_ptr) << endl;

    for (int i = 0; i < 40; ++i) {
        bits.bits_unused = i;
        string const &xmlstr = xer_codec::encode(asn_DEF_BIT_STRING, bits);
        cout << "unused bits = " << i << ", " << xmlstr << endl;
        asn1c_ptr<BIT_STRING_t> ptr = xer_codec::decode<BIT_STRING_t>(asn_DEF_BIT_STRING, xmlstr);
        string const &xmlstr2 = xer_codec::encode(asn_DEF_BIT_STRING, *ptr);
        cout << "unused bits = " << i << ", " << xmlstr2 << endl;
    }

} TEST_STOP
