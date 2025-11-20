// Prefer .h suffix when naming header files
// This is a longstanding convention for C++ header files

// Prefer putting documentation on what something does or how to use it in the header.
// It’s more likely to be seen there. 
// Documentation describing how something works should remain in the source files.

#pragma once  // avoid a header file from being included multiple times, compiler specific

// Adds two integers and returns the sum
int add(int x, int y);
