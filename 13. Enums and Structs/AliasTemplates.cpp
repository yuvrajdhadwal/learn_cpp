#include <iostream>

template <typename T>
struct Pair
{
    T first{};
    T second{};
};

// Alias template
// Alias Templates must be defined in global scope (as should all templates)
template<typename T>
using Coord = Pair<T>;  // Coord is alias for Pair<T>

template <typename T>
void print(const Coord<T>& p)  // using the alias now
{
    std::cout << p.first << ' ' << p.second << '\n';
}

int main()
{
    // aliases can be defined anywhere
    using Point = Pair<int>;  // creating normal type alias
    Point p {1, 2};  // using normal alias Point -> Pair<int>
    print(p);  // this works since underneath both Point<int> and Coord<T> are Pair<T>

    Coord<int> p2 {1, 2};
    Coord p3 {3, 4};  // post c++20 class template argument deduction works for alias templates

    print(p2); print(p3);

    return 0;
}