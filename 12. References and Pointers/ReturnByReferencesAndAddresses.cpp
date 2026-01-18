#include <iostream>
#include <string>

// returning by value, returns a copy, which can be expensive
std::string returnByValue()
{
    return std::string {"Wow this will be expensive to copy over when returned!"};
}

// returning by reference is cheaper, can even return const references
// However, the catch is the object being referred to must exist after the function is over
// Don't return references to non-const objects
const std::string& returnByReference()
{
    // static keyword means that s will be initialized when first called but will outlive function
    static const std::string s {"Wow, it's a good thing this is returning a reference so it's cheap!"};
    return s;
}

// totally safe to return by reference a parameter that was passed by reference
// this is because it has to exist outside this scope for it to be passed by reference
const std::string& firstAlpha(const std::string& a, const std::string& b)
{
    return a < b ? a : b;
}

int& max(int& a, int& b)
{
    return a < b ? b : a;
}

int main()
{
    std::cout << returnByValue() << '\n';
    std::cout << returnByReference() << '\n';

    std::string s {returnByReference()};  // Oops, this created an expensive copy anyway
    // since we are converting from reference to object

    // caller can modify values through reference
    int a {6};
    int b {7};

    max(a, b) = 10;

    std::cout << a << ' ' << b << '\n';

    // Note: reference lifetime extension does not work across function boundaries
    // Note: Return by reference and return by pointer are very similar, just keep in mind nullptr

    return 0;
}