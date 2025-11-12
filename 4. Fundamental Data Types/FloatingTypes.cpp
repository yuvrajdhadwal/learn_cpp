#include <iostream>
#include <limits>
#include <cmath>

int main()
{
    // Scientific Notation in CPP for floating types
    double x {1.2e4};
    double y {5e-2};

    std::cout << x << ' ' << y << '\n';

    std::cout << std::boolalpha; // print bool as true or false rather than 1 or 0
    std::cout << "float: " << std::numeric_limits<float>::is_iec559 << '\n';
    std::cout << "double: " << std::numeric_limits<double>::is_iec559 << '\n';
    std::cout << "long double: " << std::numeric_limits<long double>::is_iec559 << '\n';

    [[maybe_unused]] int a { 5 };  // 5 means integer
    // favor doubles over floats since doubles offer more precision
    // there can be rounding errors if not as precise as you think
    [[maybe_unused]] double b { 5.0 };  // 5.0 is floating point literal, double by default
    [[maybe_unused]] float c { 5.0f };  // 5.0 is floating point literal, f suffix means float type
    // cout only has 6 digits of precision for floating point types

    double infi { INFINITY };
    std::cout << infi << '\n';

    return 0;
}
