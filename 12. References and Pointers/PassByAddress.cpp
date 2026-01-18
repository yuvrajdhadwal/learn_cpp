#include <cassert>
#include <iostream>
#include <string>
#include <cstddef>  // nullptr is of type std::nullptr_t which is in this header

// prefer pointer to const as this includes const pointers and non const pointers, unless necessary
// prefer to not make const pointers
void printByAddress(const std::string* ptr)
{
    // need to check for null pointers
    assert(ptr);  // fail program in debug mode if null pointer is passed
    
    if (!ptr)
    {
        return;  // exit out in case nullptr in production (asserts get compiled out)
    }

    std::cout << *ptr << '\n';  // dereference the pointer
}

void nullify([[maybe_unused]] std::string*& ptr)  // pointer reference
{
    ptr = nullptr;
}

int main()
{
    std::string s {"Hello World!"};

    // Generally pass by reference is better than pass by address
    printByAddress(&s);  // creates pointer to s, copies temp ptr into parameter of printByAddress

    std::string* s_ptr {&s};

    std::cout << (s_ptr == nullptr ? "Null" : "Non-Null") << '\n';
    nullify(s_ptr);  // since it is ptr, ptr is copied, however reference ensures you can still edit
    // original value, without reference this nullify would nullify a copy of the pointer
    std::cout << (s_ptr == nullptr ? "Null" : "Non-Null") << '\n';

    return 0;
}