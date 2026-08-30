#include <iostream>
#include <string>

int return5() { return 5; }

int main() {
    // L-Value expressions evaulate to an identifiable object
    // L-Values generally persist past an expression
    // L-Values will implicitly convert to R-Values, L-Values can be used anywhere R-Values are
    // R-Value expressions evaluate to a value
    // R-Values are temporary objects that do not persist past an expression
    // R-Value cannot implicitly convert to L-Values

    [[maybe_unused]] int x{5};             // 5 is a R-Value expression
    [[maybe_unused]] const double d{1.2};  // 1.2 is a R-Value expression

    [[maybe_unused]] int y{x};           // x is a L-Value expression
    [[maybe_unused]] const double e{d};  // d is a non-modifiable L-Value expression
    [[maybe_unused]] int z{return5()};   // return5() is R-Value expression since it returns value 5

    [[maybe_unused]] int w{x + 1};                // x + 1 is R-Value expression
    [[maybe_unused]] int q{static_cast<int>(d)};  // result of static cast is R-Value expression

    std::cout << std::string{"Hello"} << '\n';  // std::string is R-Value expression

    [[maybe_unused]] std::string a{"Hello"};  // C-Style Strings are L-Value expressions

    [[maybe_unused]] int b{++x};  // ++x is L-Value expression
    [[maybe_unused]] int c{x++};  // x++ is R-Value expression, it creates a copy that does not
                                  // persist past the increment

    return 0;
}
