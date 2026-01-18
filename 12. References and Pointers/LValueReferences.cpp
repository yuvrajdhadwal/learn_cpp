#include <iostream>

int g_var {5};

int main()
{
    // Reference: Alias (not pointer) for existing object
        // Must be initialized, cannot be declared, usually should reference the same type
        // Cannot be reassigned either
    // L-Value Reference: Alias for existing L-Value
        // Two kinds of L-Value References: Const and Non-Const
        // Non-Const L-Value References must bind to Non-Const L-Values (excluding void)
        // Const L-Values can bind to L-Values, Const L-Values, and R-Values

        // There is also Constexpr L-Value references - these must bind to static duration L-Values

    int a {5};  // normal int type (not reference)
    // Attach & to the type when making L-Value references
    int& b {a};  // l-value reference to int object
    [[maybe_unused]] double c {5.0};  // normal double type
    [[maybe_unused]] double& d {c};  // l-valye reference to double object (type 1)
    
    [[maybe_unused]] const double e {5.0};  // normal const double type
    [[maybe_unused]] const double& f {e};  // l-value reference to const double object (type 2)
    [[maybe_unused]] const double& g {c};  // l-value const refernece to normal double
    
    // Temporary L-values created for both these references to bind to
    // This is important to know or else you may be creating temps when you didn't expect to
    [[maybe_unused]] const int& h {3};  // l-value const reference to r-value
    const int& i {'a'};  // l-value int const reference to char r-value

    [[maybe_unused]] constexpr int& ref {g_var};
    static const int j {6};  // constexpr can only bind to global or static local vars
    [[maybe_unused]] constexpr const int& ref2 {j};  // constexpr const to make const l-value ref

    std::cout << i << '\n';  // prints 97

    // prints value of a, and prints the value of a via reference
    std::cout << a << ' ' << b << '\n';

    a = 6;  // a now has new value of 6
    std::cout << a << ' ' << b << '\n';  // both change

    b = 7;  // the value of reference changes to 7 (a now has new value of 7)
    std::cout << a << ' ' << b << '\n';  // both change

    return 0;
}