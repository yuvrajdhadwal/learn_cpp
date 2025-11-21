#include <iostream>
#include <cassert>

void printDivision(int x, int y)
{
    /*
    if (y == 0)  // example of function precondition
    {
        std::abort();  // allows programmer to see call stack
        // abort does no cleanup so ensure there is no memory leaks etc
    }
    */

    // easier to simply use assert statements, will still call abort
    // is technically a preprocessor macro
    assert(y != 0 && "Denominator of Division cannot be 0!");
    // logical and with string literal adds better description for this assert to help debugging
    // assert macro does cost some performance, however if you define NDEBUG, then the macro does
    // nothing (make sure to do this in production code)
    // you can use liberally since there is no performance cost in production code

    /*
        Here is what the macro is:
        #define assert(_Expression) \
        (void) \
        ((!!(_Expression)) || \
        (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))

        if NDEBUG then:
        #define assert(_Expression) ((void)0)
    */

    std::cout << static_cast<double>(x) / y;
}

int main()
{
    // static asserts evaluated at compile time, thus must be constexpr condition
    // no performance cost of static assert
    // when you can use static assert or assert, choose static assert
    static_assert(sizeof(int) >= 4, "int must be at least 4 bytes");

    printDivision(1, 0);

    return 0;
}