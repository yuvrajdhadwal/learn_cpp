#include <iostream>

// Best Practice: Put defaults in the forward declarations (which should be in header files)
void print(int x, int y = 4);  // default arguments cannot be redeclared, must use = syntax
void printMany(int x, int y = 40, int z = 57); // explicit arguments are declared left to right
// if you choose to use a default argument, all arguments to right will also be default

void print(int x, int y)  // this means that default arguments cannot come here
{
    std::cout << x << ' ' << y << '\n';
}

void printMany(int x, int y, int z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

int main()
{
    print(4);  // defualt arguments are placed at function call
    printMany(2);

    /*
        1. In a function call, any explicitly provided arguments must be the leftmost arguments 
        (arguments with defaults cannot be skipped).

        2. If a parameter is given a default argument, all subsequent parameters (to the right) 
        must also be given default arguments.

        3. If more than one parameter has a default argument, the leftmost parameter should be 
        the one most likely to be explicitly set by the user.
    */

    return 0;
}