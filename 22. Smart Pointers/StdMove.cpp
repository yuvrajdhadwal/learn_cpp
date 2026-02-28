#include <iostream>
#include <string>
#include <utility>  // for std::move
#include <vector>
// std::move is a hint to compiler that the moved obj is not needed anymore
template <typename T>
void mySwapCopy(T& a, T& b)  // switch from 3 copies to 3 moves
{
    // need to use std::move because a and b are lvalues but we want to use move which requires
    // rvalues
    T temp{std::move(a)};  // invokes move constructor
    // T temp {a};      // invokes copy constructor
    a = std::move(b);  // invokes move assignment
    // a = b;      // invokes copy assignment
    b = std::move(temp);  // invokes move assignment
    // b = temp;   // invokes copy assignment
}

auto main() -> int {
    std::string x{"abc"};
    std::string y{"de"};

    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';

    mySwapCopy(x, y);

    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';

    std::vector<std::string> v;

    // std::string is moveable whereas std::string_view is not
    std::string str{"Knock"};

    std::cout << "Copying str\n";
    v.push_back(str);  // calls lvalue version of pushback, which copies
                       //
    std::cout << "str: " << str << '\n';
    std::cout << "vector: " << v[0] << '\n';

    std::cout << "\nMoving str\n";

    // move semantics make this more efficient in cases where emplace is impossible and obj is no
    // longer necessary
    v.push_back(std::move(str));  // calls rvalue version of pushback which moves str into array

    std::cout << "str: " << str << '\n';
    std::cout << "vector: " << v[0] << ' ' << v[1] << '\n';

    return 0;
}
