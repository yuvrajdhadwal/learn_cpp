#include <iostream>

int main()
{
    double x{};
    double y{};
    char op{};

    std::cout << "Enter a double value: ";
    std::cin >> x;
    std::cout << "Enter a double value: ";
    std::cin >> y;
    std::cout << "Enter +, -, *, or /: ";
    std::cin >> op;

    if (op == '+')
    {
        std::cout << x << ' ' << op << ' ' << y << " is " << x + y << '\n';
    } else if (op == '-')
    {
        std::cout << x << ' ' << op << ' ' << y << " is " << x - y << '\n';
    } else if (op == '*')
    {
        std::cout << x << ' ' << op << ' ' << y << " is " << x * y << '\n';
    } else if (op == '/')
    {
        if (y == 0.0) {
            return 0;
        }
        std::cout << x << ' ' << op << ' ' << y << " is " << x / y << '\n';
    }
    
    return 0;
}
