INCLUDES = -I$(top_srcdir)/include

# libtest.so is resident in test/.libs/libtest.so
lib_LTLIBRARIES = libtest.la
libtest_la_SOURCES = dll.cc
libtest_la_LDFLAGS = -fPIC -shared

noinst_PROGRAMS = ../bin/test
___bin_test_SOURCES = test.cc
___bin_test_LDFLAGS = -lboost_unit_test_framework
___bin_test_LDADD = $(top_srcdir)/lib/libxcom.a -ldl -ldb -ltest \
				-lboost_system

#___bin_test_CXXFLAGS = 
#EXTRA_DIST = 
# NOTE: link against to local generated lib, MUST use LDADD
