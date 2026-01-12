#include <iostream>

int add(const int x, const int y)
{
    return x + y;
}

// overloaded functions can be differentiated by number and type of parameters
// type defs/aliases don't count as different types or consts
// const/volatile or ref-qualifiers can be used for overloading (unless pass by value)
double add(double x, double y)
{
    return x + y;
}

using Age = int;
/*
Example of Type Aliases, and Overloading won't work here
int add(Age x, Age y)
{
    return x + y;
}
*/

// ambigious if you call foo();
void foo(int x = 0)
{}

void foo(double x = 0.0)
{}

// ambigious if you call zee(2);
void zee(int x, int y = 10)
{}

void zee(int x, double z = 12.0)
{}


int main()
{
    const int x {1};
    const int y {2};

    // Step 1:
    std::cout << add(x, y) << '\n';  // calls add(const int, const int) (exact match)

    // Step 2:
    std::cout << add(1, 2) << '\n'; // calls add(const int, const int) (trivial conversion 
    // from int to const int)
    // code line above is considered and exact match, if there were two overloaded functions
    // one func(int, int) and func(const int, const int) then it would be ambigious since trivial
    // conversion would count as exact matches - ambigious is compilation error
    // ambigiouty errors can occur on any step

    // Step 3:
    // if exact matches are not found, then will implicitly type convert to a valid signature
    std::cout << add(true, false) << '\n'; // calls add(const int, const int)

    // Step 4:
    // if no type conversions work, then numeric conversions are attempted
    // Step 5:
    // if no numeric conversions work, then compiler attempts user defined conversions
    // Step 6: 
    // if no user defined conversions work, then compiler will attempt to find overloaded function
    // with ellipses (...)
    // Step 7: compiler error :/

    std::cout << add(1.2, 2.3) << '\n';  // calls add(double, double)

    return 0;

    // How to Deal with Ambigiouty Errors:
    // Define a new overloaded function with that exact type as arguments
    // Explicitly cast ambigious arguments to exact arguments of the function
    // Use literal suffixes to ensure correct type
}