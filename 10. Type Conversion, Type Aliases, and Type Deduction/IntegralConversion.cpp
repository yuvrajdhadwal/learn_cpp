#include <iostream>

void parseInt(int x)
{
    std::cout << x << '\n';
}

int main()
{
    parseInt(2);  // integer to integer -- normal

    short s {3};
    parseInt(s);  // short to integer -- compiler does numeric promotion

    parseInt('a');  // char to integer -- numeric promotion (prints ascii value)
    parseInt(true);  // bool to integer -- numeric promotion

    [[maybe_unused]] double d {3.0f};  // numeric promotion of float to double

    return 0;
}