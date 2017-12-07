#ifndef TESTKIT_HPP_INLCUDED
#define TESTKIT_HPP_INLCUDED

#include <iomanip>
#include <sstream>
#include <stdexcept>

#ifndef TEST_ASSERT
#   define TEST_ASSERT(CONDITION)  \
    do { \
        if (!(CONDITION)) { \
            std::stringstream ss; \
            ss << "Assert failed at " << __FILE__ << ':' << __LINE__ << " " #CONDITION; \
            throw std::runtime_error(ss.str()); \
        } \
    } while (0)
#endif

#define TEST_EQUAL(A, B) TEST_ASSERT((A) == (B))

#define TEST_NEQUAL(A, B) TEST_ASSERT(!((A) == (B)))

#define DUMP_EXP(os, EXP)  os << #EXP << " = " << (EXP) << std::endl

#define TEST_START \
    int main(int argc, char* argv[]) try {
#define TEST_STOP \
        return EXIT_SUCCESS; \
    } catch (std::exception const &e) { \
        std::cerr << "[C++ exception] " << e.what() << std::endl; \
        return EXIT_FAILURE; \
    } catch (...) { \
        std::cerr << "[C++ exception] <UNKNOWN CAUSE>" << std::endl; \
        return EXIT_FAILURE; \
    }

#endif // TESTKIT_HPP_INLCUDED
