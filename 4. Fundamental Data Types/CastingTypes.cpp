#include <iostream>

void print(int x)
{
    std::cout << x << '\n';
}

int main()
{
    // static cast does not effect the variable it is casting
    // returns a new casted variable
    print(static_cast<int>(5.5));  // manual casting removes compiler warning

    unsigned int u1 { 5 };
    int s1 {static_cast<int>(u1)};
    std::cout << s1 << '\n';

    int s2 { 5 };
    unsigned int u2 { static_cast<unsigned int>(s2) };
    std::cout << u2 << '\n';

    return 0;
}
