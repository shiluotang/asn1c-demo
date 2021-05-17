#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
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

class properties {
public:
    template <typename V>
    void put(std::string const &key, V const &value) {
        using namespace std;
        using namespace misc;
        _M_values[key] = sstream_cast<string>(value);
    }

    template <typename V>
    V get(std::string const &key, V const &defaultValue) const {
        using namespace std;
        using namespace misc;
        values::const_iterator it = _M_values.find(key);
        if (it == _M_values.cend())
            return defaultValue;
        return sstream_cast<V>(it->second);
    }

    bool has(std::string const &key) const {
        return _M_values.find(key) == _M_values.cend();
    }

    void save(std::ostream &os) const {
        for (values::const_iterator it = _M_values.cbegin();
                it != _M_values.cend(); ++it)
            os << it->first << "=" << it->second << std::endl;
    }

    void load(std::istream &is) {
        using namespace std;
        std::string line;
        while (std::getline(is, line)) {
            string::size_type pos = line.find("=", 0);
            if (pos != string::npos) {
                std::string key = line.substr(0, pos);
                std::string value = line.substr(pos + 1);
                _M_values[key] = value;
            }
        }
    }
private:
    typedef std::map<std::string, std::string> values;
    values _M_values;
};

std::ostream& operator << (std::ostream &os, properties const &p) {
    p.save(os);
    return os;
}

std::istream& operator >> (std::istream &is, properties &p) {
    p.load(is);
    return is;
}

TEST_START {
    using namespace std;
    using namespace asn1cxx;
    using namespace misc;

    uper_codec uper;
    xer_codec xer;
    asn_codec asn;

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
        cout << "unused bits = " << i << ", [XER] " << xmlstr << endl;
        refcnt_ptr<BIT_STRING_t> ptr = xer.decode<BIT_STRING_t>(xmlstr, &asn_DEF_BIT_STRING);
        string const &xmlstr2 = xer.encode(*ptr, &asn_DEF_BIT_STRING);
        cout << "unused bits = " << i << ", [XER] " << xmlstr2 << endl;
        cout << "unused bits = " << i << ", [ASN] " << asn.encode(*ptr, &asn_DEF_BIT_STRING) << endl;
    }

    properties props;
    cout << props.get("key", 100) << endl;
    props.put("key", 105);
    cout << props.get("key", 100) << endl;

    std::fstream iofile("application.properties");
    if (!iofile)
        throw std::runtime_error("application.properties can't be open");
    iofile << props;

} TEST_STOP
