#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT([asn1c-demo], [0.1], [shengquangang2015@163.com])

AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AC_CONFIG_SRCDIR([src])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([foreign subdir-objects -Wall -Werror])

# Checks for programs.
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
AC_PROG_CXX
AC_PROG_CC
m4_ifdef([AM_PROG_AR], [AM_PROG_AR])
LT_INIT

# Checks for libraries.

# Checks for header files.
AC_FUNC_ALLOCA
AC_CHECK_HEADERS([float.h inttypes.h limits.h malloc.h netinet/in.h stddef.h stdint.h stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT8_T
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T
AC_CHECK_TYPES([ptrdiff_t])


# Checks for library functions.
AC_FUNC_MKTIME
AC_FUNC_STRTOD
AC_CHECK_FUNCS([localtime_r memchr memmove memset pow setenv strerror tzset])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
