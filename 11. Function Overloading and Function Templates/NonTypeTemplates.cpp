#include <iostream>

/*
Non-type template parameters are used primarily when we need to pass constexpr values to
functions (or class types) so they can be used in contexts that require a constant expression.
*/
template <int N>  // integral template parameter
void printMany() {
    for (int i{0}; i < N; ++i) {
        std::cout << "Hello World!\n";
    }
}

template <auto N>  // deduce non type template parameter type
void print() {
    std::cout << N << '\n';
}

template <int N>
constexpr int factorial() {
    // static assert since constexpr function and non-type template
    // this means everything can be evaluated at compile time
    static_assert(N >= 0, "Factorial Parameters must be Non-Negative");
    int out{1};

    for (int i{1}; i <= N; ++i) {
        out *= i;
    }

    return out;
}

int main() {
    printMany<5>();

    print<5>();
    print<'c'>();
    print<5.6>();

    // static assert since constexpr function and non-type template
    // this means everything can be evaluated at compile time
    static_assert(N >= 0, "Factorial Parameters must be Non-Negative");
    static_assert(factorial<0>() == 1);
    static_assert(factorial<3>() == 6);
    static_assert(factorial<5>() == 120);

    // factorial<-3>(); // should fail to compile

    return 0;
}
