#include <iostream>

int main()
{
    int x {5};

    std::cout << x << '\n';
    std::cout << &x << '\n';  // unary & is address of, returns a pointer size is 32 bits or 64 bits
    std::cout << *(&x) << '\n';  // unary * is dereference

    int* dummy;  // uninitialized pointers (points to garbage) (dangling pointer)
    int* nptr {};  // nullptr
    int* ptr {&x};  // ptr initialized to with address of x, pointers should be same time as 
    // what they point to

    std::cout << dummy << '\n' << nptr << '\n' << ptr << '\n';

    int y {6};
    ptr = &y;  // reassigning what we point to

    std::cout << ptr << ' ' << *ptr << '\n';

    *ptr = 7;  // reassigning the value
    std::cout << ptr << ' ' << *ptr << '\n';

    // Pointers are very similar to L-Value References

    int a {1};
    int& b {a};
    int* c {&a};

    std::cout << a << ' ' << b << ' ' << *c << '\n';

    a++;
    std::cout << a << ' ' << b << ' ' << *c << '\n';

    b++;
    std::cout << a << ' ' << b << ' ' << *c << '\n';

    (*c)++;
    std::cout << a << ' ' << b << ' ' << *c << '\n';

    int g {5};
    int* h {&g};
    std::cout << *h << '\n';  // points to g

    {
        int k {4};
        h = &k;
        std::cout << *h << '\n';  // points to k
    }  // k out of scope, h is dangling (not nullptr, pointing to garbage now)

    std::cout << *h << '\n';  // undefined behavior

    int* t {};  // nullptr
    int* s {nullptr};  // also nullptr

    // std::cout << *t << '\n';  // undefined behavior to dereference nullptr

    // You can use conditional statements to protect against nullptrs
    std::cout << "Do we have a nullptr? " << (t == nullptr ? "Yes" : "No") << '\n';
    // Pointers also implictly convert to booleans
    if (!s)
    {
        std::cout << "Oops! Another nullptr!\n";
    }

    const int c_int {6};
    const int* c_ptr {&c_int};  // pointer to const

    const int c_int_y {7};
    c_ptr = &c_int_y;  // while we cannot edit the value since const, we can change what we point to

    int nc_int {8};
    c_ptr = &nc_int;  // pointers to const can also point to nonconsts, treats as if const

    int* const const_ptr {&nc_int};  // const after int* makes const pointer,
    // address cannot be changed. this is a const pointer pointing to nonconst value
    *const_ptr = 1;  // totally fine since pointing to non-const
    // const_ptr = 1;  // not fine, address cannot change

    // const pointer to const int. address cannot be changed, value cannot be changed
    const int* const omega_const_ptr {&c_int};


    return 0;
}