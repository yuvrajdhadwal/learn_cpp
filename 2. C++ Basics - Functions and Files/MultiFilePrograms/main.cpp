#include <iostream>

int add(int x, int y);  // Forward Declaration allows compilation and linker will link
// declaration to the definition in the other file since no definition in this file

int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
    return 0;
}

// A namespace may only contain declarations and definitions.
// Executable statements are only allowed as part of a definition (e.g. of a function).
