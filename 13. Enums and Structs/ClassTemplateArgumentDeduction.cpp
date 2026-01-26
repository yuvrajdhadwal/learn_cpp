#include <iostream>
#include <utility>  // for std::pair
#include <typeinfo>  // for typeid
    
// CTAD doesn't work for function parameters, must explicitly state or use generics
template <typename T, typename U>
constexpr void print(const std::pair<T, U>& p)
{
    std::cout << p.first << ' ' << p.second << '\n';
    std::cout << "Type of p.first: " << typeid(p.first).name() << '\n';
    std::cout << "Type of p.second: " << typeid(p.second).name() << "\n\n";
}

int main()
{
    std::pair<int, int> p1 {1, 2};  // explicitly specify class template 
    std::pair p2 {1, 2};  // CTAD used to deduce std::pair<int, int> from initializers
    std::pair p3 {1, 2.0};  // C++20 onwards, deduces std::pair<int, double>
    std::pair p4 {1.0f, 2u};  // using literal suffixes for type deduction

    print(p1); print(p2); print(p3); print(p4);

    return 0;
}