#include <iostream>

int main()
{
    int nValue{};
    float fValue{};

    struct Something { int n; float f; };
    Something sValue{};

    // void ptrs are generic ptrs, 
    // special type of pointer that can be pointed at objects of any data type
    void* ptr {};  // ptr is void ptr

    // can point to anything!
    ptr = &nValue;
    ptr = &fValue;
    ptr = &sValue;

    // since we don't know what type the ptr is pointing to, cannot dereference unless 
    // casting to a type

    ptr = &nValue;
    std::cout << *(static_cast<int*>(ptr)) << '\n';

    // deleting void pointers is undefined behavior, must convert it to type first to delete it
    // generally void pointers can be replaced by good design (overloaded funcs, templates)
    // but sometimes still useful

    return 0;
}
