#include <iostream>

int main()
{
    // we use copy initialization here since curly brace disallows some types of numeric conversion
    // numeric conversions from integer literal 3 to other numeric types
    short s = 3;
    long l = 3;
    char c = 3;
    unsigned int u = 3;

    // floating numeric conversions
    float f = 3.0;
    long double ld = 3.0;

    // int to floating
    double d = 3;
    
    // int/floating to bool
    bool b = 3;
    bool bb = 3.0;

    std::cout << s << l << c << u << f << ld << d << b << bb << '\n';

    // there are safe and unsafe numeric conversions
    // numeric conversions fall into three camps:
    // 1. value preserving through conversion (safe)
    // 2. conversions that don't lose data but new value may not be same as old
            // think signed to unsigned conversion (following code doesnt compile rip)
    // int x {-5};
    // unsigned int y = x;
    // std::cout << x << " should equal " << y << " right? NOPE LOL!" << '\n';
    // 3. lossy conversions (unsafe) (following code doesn't compile)
    // int i = 3.9;
    // float ff = 1.23456789;
    // std::cout << "some lossy conversions " << i << ' ' << ff << '\n';

    // overflow is well defined for unsigned values but undefined for signed values

    // narrowing conversions can only be done with explicit cast without warning
    double dd {3.3};
    int i {static_cast<int>(dd)};

    std::cout << dd << ' ' << i << '\n';

    // int j {d};
    // std::cout << j << " the above errors out since the compiler doesn't know this"
    // "conversion is safe\n";

    constexpr int n1 {3};
    unsigned int u1 {n1};
    std::cout << u1 << " this will work since ddd is a constexpr so the compiler knows no info is"
    " lost during this narrowing conversion\n";
    // constexpr int n2 {-3};
    // unsigned int u2 {n2};
    // this fails since info is lost during narrowing conversion and compiler knows it
    // constexpr doesnt work for floating point numbers

    // prints out the name of a type of a variable
    std::cout << typeid(n1).name() << '\n';  // i
    std::cout << typeid(5).name() << '\n';  // i
    std::cout << typeid(5.0).name() << '\n';  // d


    return 0;
}