#include <algorithm>
#include <functional>  // for std::function
#include <iostream>
#include <vector>

int foo() { return 5; }
int goo() { return 6; }
int hoo(int x) { return x; }
// basic comparison functions
bool ascending(int x, int y) { return x < y; }
bool descending(int x, int y) { return x > y; }
void printVector(std::vector<int>& v) { for (int e : v) { std::cout << e << ' '; }}
void sort(std::vector<int>& v, bool (*fnptr)(int, int) = descending);  // default fn ptrs

int main()
{
    // func ptrs are resolved at runtime - not compile time like most function calls
    // thus func ptrs do not utilize default parameters
    int (*fcnPtr)() {nullptr};  // this creates a pointer to a function; no arguments, returns int
    int (*const fcnPtrr)() { &goo };  // this creates a const function pointer to goo
    fcnPtr = &foo;
    int (*hooPtr)(int) { &hoo };
    auto hooPtr { &hoo };  // can also use auto

    int (*funcPtr)() {foo};  // cpp will deduce this to be func ptr and change foo to &foo auto

    std::cout << (*fcnPtr)() << '\n';  // calls the function that fcnPtr points to
    std::cout << fcnPtrr() << '\n';  // implicit dereference
    std::cout << hooPtr(1000) << '\n';  // you can add input into functions; implicit dereference

    if (fcnPtr) { fcnPtr(); }  // make sure func ptrs are not nullptr

    // one of the coolest parts of function pointers is passing functions as arguments into other
    // functions! think of comparison functions

    std::vector v {1, 5, 6,8, 2, 7, 10, 22,4};
    std::sort(v.begin(), v.end(), ascending);
    printVector(v); std::cout << '\n';
    std::sort(v.begin(), v.end(), descending);
    printVector(v); std::cout << '\n';

    sort(v, ascending);
    printVector(v); std::cout << '\n';
    sort(v);  // default fn ptrs
    printVector(v); std::cout << '\n';

    // do everything you want with function pointers with std::function
    std::function<int()> fnPtr { &foo };
    fnPtr = &goo;
    std::cout << fnPtr() << '\n';  // note: std::function cannot be dereferenced

    return 0;
}

// we can even make our own functions take function pointers
using cmp = bool (*)(int, int);  // type alias away gross fn ptr syntax
void sort(std::vector<int>& v, cmp fnptr)
{
    std::sort(v.begin(), v.end(), fnptr);
}