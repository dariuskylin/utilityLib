INCLUDES = -I$(top_srcdir)/include -I/usr/local/share/db/include
#include_HEADERS = 

noinst_PROGRAMS = ../bin/xcom
___bin_xcom_SOURCES = main.cc xcom.cc

noinst_LIBRARIES = ../../lib/libxcom.a
______lib_libxcom_a_SOURCES = xcom.cc
#SharedLibrary.cc

# NOTE: link against to local generated lib, MUST use LDADD
___bin_xcom_LDADD =  -ldb -lpthread
#___bin_xcom_LDFLAGS = -static   
#$(top_builddir)/lib/libxcom.a
#EXTRA_DIST = 
#___bin_xcom_CXXFLAGS = 