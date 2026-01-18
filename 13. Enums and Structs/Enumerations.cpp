#include <iostream>
// enums are constexpr implicitly
// Example of Unscoped Enumeration: Enumerators are in same namespace as Enumeration
namespace Color  // using namespaces to not clutter the global namespace
{
    enum Color
    {
        red,
        green,
        blue,  // trailing comma, optional but recommended
    };  // enum definition must end with semicolon    
}

int main()
{
    Color::Color apple {Color::red};
    Color::Color shirt {Color::green};
    Color::Color cup {Color::blue};

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
}