#include <iostream>

int main()
{
    // static_cast - performs compile-time conversions between related types (safe)
    // dynamic_cast - performes run-time conversions on pointers or references in polymorphic
    // inheirtance hierarchy (safe)

    // const_cast - adds or removes const (safe for adding const to var) avoid unless good reason
    // reinterpret_cast - reinterprets bit level representation of one type as if it were another
    // (unsafe) avoid unless good reason

    // c-style casts - unsafe


    int x {10};
    int y {4};


    // c style casting - very common; do not use
    // performs a wide array of casts: static_cast, const_cast, and reinterpretive cast
    // and never clear which one it is doing
    std::cout << x << " / " << y << " = " << x / y << '\n';
    std::cout << (double)x << " / " << y << " = " << (double)x / y << '\n';
    std::cout << double(x) << " / " << y << " = " << double(x) / y << '\n';

    // most common cast is static_cast<>()
    // returns a temp variable that is direct initialized with new value
    // provides compile time checks, prevents dangerous casts
    std::cout << x << " / " << y << " = " << static_cast<double>(x) / y << '\n';

    return 0;
}
