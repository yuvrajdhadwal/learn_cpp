// Use double quotes to include header files that you’ve written
// or are expected to be found in the current directory. 
// Use angled brackets to include headers that come with your compiler, OS,
// or third-party libraries you’ve installed elsewhere on your system.

/*
To maximize the chance that missing includes will be flagged by compiler, 
order your #includes as follows (skipping any that are not relevant):

1. The paired header file for this code file (e.g. add.cpp should #include "add.h")
2. Other headers from the same project (e.g. #include "mymath.h")
3. 3rd party library headers (e.g. #include <boost/tuple/tuple.hpp>)
4. Standard library headers (e.g. #include <iostream>)

The headers for each grouping should be sorted alphabetically
(unless the documentation for a 3rd party library instructs you to do otherwise).
*/

#include <iostream>
#include "add.h"  // inserts contents of add.h at this point

// Redundant Forward Declaration since Forward Declaration is also in add.h which is included
int add(int x, int y);  // Forward Declaration allows compilation and linker will link
// declaration to the definition in the other file since no definition in this file

int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
    return 0;
}

// A namespace may only contain declarations and definitions.
// Executable statements are only allowed as part of a definition (e.g. of a function).
