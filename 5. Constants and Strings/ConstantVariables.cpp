#include <iostream>

const int printInt(const int x)  // const function parameter
// No need to do const here since this is pass by value (copy) so avoid
// const parameters is much more important for pass by reference or address
{
    std::cout << x << '\n';
    return 5;  // return values can also be const, better for non local objects by value
}

int main()
{
    // variables that will not change in value should remain constant
    [[maybe_unused]] const double gravity { 9.8 };  // must be initialized when defined and cannot be altered

    std::cout << "Enter your age: ";
    int x{};
    std::cin >> x;

    // creating a const var from a non-const var
    [[maybe_unused]] const int age { x };

    // there is no standard naming convention for consts
    // all these are valid
    [[maybe_unused]] const int THIS_IS_A_CONST_VAR { 5 };  // Common in C
    [[maybe_unused]] const int kThisIsAConstVar { 5 };  // Common in C++
    [[maybe_unused]] const int this_is_a_const_var { 5 };  // regular
    [[maybe_unused]] const int thisIsAConstVar { 5 };  // regular

    printInt(kThisIsAConstVar);

    // The volatile qualifier is used to tell the compiler that an object
    // may have its value changed at any time. 

    return 0;
}
