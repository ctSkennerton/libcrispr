libcrispr
=========

A small library for dealing with .crispr files

Currently libcrispr implements an XML parsing interface for crispr files as well
as an exception class for handling errors.

#Installation
On most UXIX type systems the following commands should surfice:
`
./autogen.sh
./configure
[sudo] make install
`

#Usage
programs using libcrispr should include the relevent header files with:
`#include <libcrispr/Xml.h>` 
etc...
and then add:
`-lcrispr`
to the program's LDFLAGS 