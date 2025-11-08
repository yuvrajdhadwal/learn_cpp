#include <iostream>

int main() {
    // modern, recommended to do
    [[maybe_unused]] int x;     // default-initialization (no initializer) - garbage value
    // [[maybe_unused]] attribute tells the compiler a variable is unused and it is fine. 
    // The compiler will not generate unused variable warnings for such variables.

    // Best Practice: Prefer direct-list-initialization or value-initialization 
    // to initialize your variables. Initialize your variables upon creation.

    int y { 5 };                // direct-list-initialization (initial value in braces)
    // forbids narrowing conversions 4.5 causes error instead of turning into 4
    int e {};                   // value-initialization (empty braces) - defaults to 0

    // traditional, do not do
    [[maybe_unused]] int b = 5;      // copy-initialization (initial value after equals sign)
    // also used when pass by value into functions
    [[maybe_unused]] int c ( 6 );    // direct-initialization (initial value in parenthesis)

    std::cout << y;
    std::cout << e;

    return 0;
}
