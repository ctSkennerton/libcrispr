AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4
lib_LTLIBRARIES = libcrispr.la
libcrispr_la_CXXFLAGS = @XERCES_CPPFLAGS@ -Werror -Wall -pedantic
libcrispr_la_LDFLAGS = @XERCES_LIBS@ -version-info @LIBTOOL_VERSION_STRING@
libcrispr_la_SOURCES = \
Xml.cpp \
Xml.h \
Exception.h \ 
StlExt.h 
