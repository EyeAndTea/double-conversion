-----------------------------------------------------------------------------
-----------------------------------------------------------------------------
-----------------------------------------------------------------------------
(WARNING: ABOUT THIS FORK)

This fork was for getting the library to work under Visual Studio 6 primarily, but
likely to improve compatibility with compilers in general. The changes here
are likely to damage the accuracy of the official implementation. If you wish
to deduce how this might, or might not, affect you, note the following for
pertaining changes:

- File "double-conversion/string-to-double.cc": Search for
		::std::tolower(ch, ::std::locale(""));
- File "double-conversion/string-to-double.cc": The functions 
		StringToDoubleConverter::StringTo() were disabled. Examine 
- File "double-conversion/strtod.cc": The private function 
		convertUnsignedInt64ToDouble(unsigned __int64) introduced to be used
		instead of static_cast<double>(unsigned __int64 t). This might 
		slightly affect performance on newer compilers. On Visual Studio 6, 
		in particular, this might give incorrect results.

Finally, note that tests were not updated to reflect the changes.

-----------------------------------------------------------------------------
-----------------------------------------------------------------------------
-----------------------------------------------------------------------------



https://github.com/google/double-conversion

This project (double-conversion) provides binary-decimal and decimal-binary
routines for IEEE doubles.

The library consists of efficient conversion routines that have been extracted
from the V8 JavaScript engine. The code has been refactored and improved so that
it can be used more easily in other projects.

There is extensive documentation in `double-conversion/string-to-double.h` and
`double-conversion/double-to-string.h`. Other examples can be found in
`test/cctest/test-conversions.cc`.


Building
========

This library can be built with [scons][0] or [cmake][1].
The checked-in Makefile simply forwards to scons, and provides a
shortcut to run all tests:

    make
    make test

Scons
-----

The easiest way to install this library is to use `scons`. It builds
the static and shared library, and is set up to install those at the
correct locations:

    scons install

Use the `DESTDIR` option to change the target directory:

    scons DESTDIR=alternative_directory install

Cmake
-----

To use cmake run `cmake .` in the root directory. This overwrites the
existing Makefile.

Use `-DBUILD_SHARED_LIBS=ON` to enable the compilation of shared libraries.
Note that this disables static libraries. There is currently no way to
build both libraries at the same time with cmake.

Use `-DBUILD_TESTING=ON` to build the test executable.

    cmake . -DBUILD_TESTING=ON
    make
    test/cctest/cctest

[0]: http://www.scons.org/
[1]: https://cmake.org/
