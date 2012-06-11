#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([xcom], [0.1], [xiaowen.nie.cn@gmail.com])
AC_CONFIG_SRCDIR([])
AM_INIT_AUTOMAKE(xcom, 0.1)
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_RANLIB
AC_PROG_LIBTOOL
AC_ARG_ENABLE(debug, [  --enable-debug	Enable DEBUG output. ],
	[ CXXFLAGS="-g -O0 -DDEBUG -Wall -Werror -fno-strict-aliasing -std=c++0x" ],
	[ CXXFLAGS="-O3 -Wall -Werror -fno-strict-aliasing -std=c++0x" ])

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile src/Makefile test/Makefile])
AC_OUTPUT
