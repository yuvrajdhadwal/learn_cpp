#include <iostream>
#include <optional> // for std::optional (C++17)

// Our function now optionally returns an int value
std::optional<int> doIntDivision(int x, int y)
// Return a std::optional (instead of a sentinel value) for functions that may fail, 
// unless your function needs to return additional information about why it failed.
{
    if (y == 0)
        return {}; // or return std::nullopt
    return x / y;
}

int main()
{
    /*
    std::optional<int> o1 { 5 };            // initialize with a value
    std::optional<int> o2 {};               // initialize with no value
    std::optional<int> o3 { std::nullopt }; // initialize with no value
    if (o1.has_value()) // call has_value() to check if o1 has a value
    if (o2)             // use implicit conversion to bool to check if o2 has a value
    std::cout << *o1;             // dereference to get value stored in o1 (undefined 
    behavior if o1 does not have a value)
    std::cout << o2.value();      // call value() to get value stored in o2 (throws 
    std::bad_optional_access exception if o2 does not have a value)
    std::cout << o3.value_or(42); // call value_or() to get value stored in o3 
    (or value `42` if o3 doesn't have a value)
    */
    std::optional<int> result1 { doIntDivision(20, 5) };
    if (result1) // if the function returned a value
        std::cout << "Result 1: " << *result1 << '\n'; // get the value
    else
        std::cout << "Result 1: failed\n";

    std::optional<int> result2 { doIntDivision(5, 0) };

    if (result2)
        std::cout << "Result 2: " << *result2 << '\n';
    else
        std::cout << "Result 2: failed\n";

    return 0;
}