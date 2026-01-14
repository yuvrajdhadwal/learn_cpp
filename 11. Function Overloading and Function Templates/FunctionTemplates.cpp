#include <iostream>

// The following code only works for ints, how to make it generic?
int max(int x, int y)
{
    return (x < y) ? y : x;
}

// primary template
// use single letter capitals for trivial types, if non trivial capitalize first letter of type
template <typename T>  // template parameter declaration of T as type template parameter
T max(T x, T y)  // function template definition for max<T>
{
    return (x < y) ? y : x;
}

template <typename T>
void printLine(T line)
{
    static int id {0};  // static local variables intialized when first called
    // they don't get popped off the stack until end of the program
    std::cout << ++id << ") " << line << '\n';
}

// multiple template types example
template <typename T, typename U>
auto multiply(T t, U u) -> decltype(t * u)  // decltype deduces the type
{
    return t * u;
}

// C++ 20 abbreviated function template
auto min(auto x, auto y)
{
    return (x > y) ? y : x;
}

// overloaded template functions (using both abbreviated and non abbreviated function templates)
auto print(auto x)
{
    std::cout << x << '\n';
}

template <typename T, typename U>
auto print(T x, U y)
{
    std::cout << x << ' ' << y << '\n';
}

auto print(auto x, auto y, auto z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

int main()
{
    std::cout << max(2, 3) << '\n';  // calls the regular function

    // function instance, only instantiated on first call
    std::cout << max<int>(2, 3) << '\n';  // calls the templated function, signifying type T is int
    std::cout << max<int>(3, 4) << '\n';  // calls the already instantiated max<int>(int, int)
    std::cout << max<double>(6.0, 7.0) << '\n';  // instantiates a new fucuntion instance for double

    std::cout << max<>(7, 6) << '\n';  // deduces max<int>(int, int) from arguments passed in

    printLine(1);  // local static variable instantiated (int)
    printLine(2);  // local static variable incremented
    printLine(2.2);  // local static variable instantiated (double)
    // this is because compiler makes new specialization of template for double

    // Note: Every specialization of a template is a new set of code that is created
    // this increases compile times and makes a much larger instruction set
    // however, if generics are used properly, this is much preferred to
    // manually writing many similar functions

    return 0;
}