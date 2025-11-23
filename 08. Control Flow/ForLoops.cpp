#include <iostream>

int main()
{
    for (int x {5}, y {4}; x < 10; ++x, --y)  // multiple var initialization and end-expression
    {
        std::cout << x << ' ' << y << '\n';
    }

    return 0;
}