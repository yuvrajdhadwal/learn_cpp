#include <iostream>

// The following code only works for ints, how to make it generic?
int max(int x, int y)
{
    return (x < y) ? y : x;
}

// use single letter capitals for trivial types, if non trivial capitalize first letter of type
template <typename T>  // template parameter declaration of T as type template parameter
T max(T x, T y)  // function template definition for max<T>
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max(2, 3) << '\n';
    std::cout << max<int>(2, 3) << '\n';

    return 0;
}