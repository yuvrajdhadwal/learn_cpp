#include <iostream>

class Foo
{
    public:

    // Default Constructor (User Defined)
    Foo()
    {
        std::cout << "Foo()\n";
    }

    // Constructor
    Foo(int x)
    {
        std::cout << "Foo(int) " << x << '\n';
    }

    // Copy Constructor
    Foo(const Foo& o)
    {
        std::cout << "Foo(const Foo&)\n";
    }
};

void print(Foo x)
{
    std::cout << "wow\n";
}

int main()
{
    // List Initialization disallows narrowing conversion
    // Copy Initialization only considers non-explicit constructors/conversions
    // List Initialization prefers List Constructors over any others (bad for vectors)

    // Default Constructor Calls
    Foo f1;  // default initialization
    Foo f2 {};  // value initialization (preferred)

    // Normal Constructor Call
    Foo f3 = 3;  // copy-initialization (non explicit constructors only)
    Foo f4(4);  // direct initialization
    Foo f5 {5};  // direct list initialization (preferred)
    Foo f6 = {6};  // copy list initialization (non explicit constructors only)

    // Copy Constructor
    Foo f7 = f3;  // copy initialization
    Foo f8(f3);  // direct initialization
    Foo f9 {f3};  // direct list initialization (preferred)
    Foo f10 = {f3};  // copy list initialization

    // Theoretically should call Foo(int) and then Foo(const Foo&)
    // Thanks to Copy Elision / Return Value Optimizations it doesn't
    Foo badFoo {Foo {3}};
    // While compiling the code, Copy Elision rewrites the above code to
    // goal is to remove unnecessary copy constructors
    // this is why we don't want side effects in our copy constructors
    // it can be called when passed in by value for parameter or returned by value from a function
    // mandatory copy elision in c++17 or later
    Foo optimizedBadFoo {3};  // explicitly converting value 3 to Foo

    print(2);  // implicitly converting 2 to Foo since Foo is pass by value argument
    // copy elision ensures this only creates temp variable and doesnt copy as well
    // these are called converting constructors, by default all constructors are converting

    return 0;
}