#include <iostream>

int main()
{
    int x {};
    const int* ptr {&x};  // assuming 4 byte ints

    // system is byte-addressible
    // however, we are using int* so adding by 1 is auto converted to adding by 1 int* which is
    // 4 bytes

    std::cout << ptr << ' ' << (ptr + 1) << ' ' << (ptr + 2) << '\n';  // addition
    std::cout << ptr << ' ' << (ptr - 1) << ' ' << (ptr - 2) << '\n';  // subtraction

    // within an array pointer arithmetic

    int arr[] {0, 1, 2, 3, 4, 5};
    ptr = &arr[2];  // ptr now points to index 2 of this array

    std::cout << ptr << ' ' << *ptr <<'\n';
    std::cout << ptr + 1 << ' ' << *(ptr + 1) << '\n';
    std::cout << ptr - 1 << ' ' << *(ptr - 1) << '\n';


    return 0;
}