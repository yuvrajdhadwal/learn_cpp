#include <iostream>
// favor scoped enums over unscoped enums

enum class Color  // scoped enum, doesn't have to be in global namespace
{
    red,  // part of color scope, don't implictly convert to ints but hold values the same way
    blue,
};

std::string_view enumToStringExample(Color color)
{
    using enum Color;  // brings all Color enums to current scope, no need for Color::

    switch (color)
    {
        case red: return "red";
        case blue: return "blue";
        default: return "????";
    }
}

int main()
{
    Color color {Color::red};  // Have to use Color:: to access even though its not in namespace
    Color color2 {1};  // You can specify the enum with an integer without static cast

    std::cout << static_cast<int>(color) << '\n';  // convert scoped enum to int
    return 0;
}
