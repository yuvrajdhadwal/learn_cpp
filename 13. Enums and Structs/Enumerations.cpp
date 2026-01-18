#include <iostream>
#include <string_view>
// enums are constexpr implicitly
// Example of Unscoped Enumeration: Enumerators are in same namespace as Enumeration
// Unscoped Enumerators implicitly convert to integral values
namespace Color  // using namespaces to not clutter the global namespace
{
    enum Color
    {
        // Best to keep enumeration 0 something nice and default
        red,  // value defaults to 0
        // enumerators can be assigned to same value, this is okay but not recommended
        green = -4,  // you can assign values to enums, can be negative
        orange,  // non-defined enumerators are defined as one greater than previous
        blue,  // trailing comma, optional but recommended
    };  // enum definition must end with semicolon    
}

std::string_view enumToStringExample(Color::Color color)
{
    switch (color)
    {
        case Color::red: return "red";
        case Color::green: return "green";
        case Color::orange: return "orange";
        case Color::blue: return "blue";
        default: return "????";
    }
}

int main()
{
    Color::Color apple {Color::red};
    Color::Color shirt {Color::green};
    Color::Color cup {Color::blue};
    Color::Color defaultColor {};  // defaults to enumerator 0, even if one doesn't exist

    Color::Color myFavColor {static_cast<Color::Color>(-2)};  // casting integer value to enum

    if (shirt == Color::green)
    {
        std::cout << "What the heck! A Green Shirt!!\n";
    } else if (shirt == Color::blue)
    {
        std::cout << "We are going blue!\n";
    } else
    {
        std::cout << "None of the above. Naurrr!!\n";
    }

    std::cout << enumToStringExample(myFavColor) << '\n';

    return 0;
}