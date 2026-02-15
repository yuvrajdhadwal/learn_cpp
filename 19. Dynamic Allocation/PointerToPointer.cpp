#include <iostream>

int main()
{
    int* ptr;  // ptr to int
    int** ptrptr;  // ptr to ptr to int, can be nullptr too

    int value {5};
    ptr = &value;
    ptrptr = &ptr;

    std::cout << value << ' ' << *ptr << ' ' << **ptrptr << '\n';

    // array of pointers
    int** array {new int*[10]};  // creates decayed c-style array of int*

    // generally don't use ptrs to ptrs; theyre complex and can lead to many dangling ptrs
}