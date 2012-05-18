#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT(crass, 0.0.5, c.skennerton@gmail.com)

AC_CONFIG_AUX_DIR(build)
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([Xml.h])
AC_CONFIG_HEADER([config.h])

AM_INIT_AUTOMAKE([foreign])
LT_INIT
LT_LANG([C++])


LIBTOOL_VERSION_STRING="0:0:0"
AC_SUBST([LIBTOOL_VERSION_STRING])
#check that graphviz is installed before defining RENDERING

if test x$rendering = xtrue; then
    AC_CHECK_PROGS([GV_PROGS], [neato fdp sfdp dot circo twopi], [no])

    if test x$GV_PROGS != xno; then
        
        AC_DEFINE([RENDERING],[1],[Defines to 1 if image rendering is to be performed])
        AC_DEFINE_UNQUOTED([DEFAULT_RENDERING_ALGORITHM],["${GV_PROGS}"],[Sets the Default Graphviz algorithm])
    else
        echo "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"
        echo "None of the Graphviz executables could"
        echo "be found in your PATH!"
        echo "Your installation will not conatin"
        echo "rendering options!"
        echo "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*"
    fi
fi


# Checks for different libs, headers, functions & programs
#
#

# Checks for compilers.


AC_PROG_CXX
AC_PROG_CC

AX_LIB_XERCES

if test $HAVE_XERCES = no; then
AC_MSG_ERROR([Cannot find Xerces-c])
else
AM_CONDITIONAL([XERCES_FOUND], [test $HAVE_XERCES = yes])
fi


# Checks for header files.
AC_HEADER_STDC



AC_OUTPUT(Makefile)
