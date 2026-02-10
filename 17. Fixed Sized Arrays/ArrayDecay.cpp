#include <iomanip>  // for std::boolalpha
#include <iostream>

void foo(int arr[])
{
    std::cout << sizeof(arr) << '\n';
}  // due to array decay this is the same as int*, but this is more obvious
// that we are expecting int[] not int*, even tho theyre the same thing under the hood
// this is still a decayed array even if the syntax doesn't look like it

int main()
{
    // Array Decay: When C-Style Array is used in expression, array is implicitly converted to
    // pointer to element type initialized to fist element

    // decayed arrays don't know how long the array is!

    int arr[5] {9, 7, 5, 3, 1};  // int[]

    // proving decay happens
    auto ptr {arr};  // expression causes arr to decay to pointer to int
    std::cout << std::boolalpha << (typeid(ptr) == typeid(int*)) << '\n';

    // proving that it points to first value
    std::cout << std::boolalpha << (&arr[0] == ptr) << '\n';

    std::cout << arr[2] << '\n';  // this is actually subscripting decayed array (ptr)
    std::cout << ptr[2] << '\n';  // see this prints the same thing

    std::cout << sizeof(arr) << '\n';
    foo(arr);

    return 0;
}