#include <iostream>

class Something
{
    public:
    static inline int x {0};  // make static members inline or constexpr to define in class def
    static inline auto y {5.0};  // member values can only be auto or CTAD if static

    static int getValue() { return z; }  // static member function
    // this allows us to easily get the private member

    static int getTheValueTwo();  // static function forward declared

    private:
    // ensure inline if declared in same header file, usually defined in source code if forward
    static inline int z;  // cannot access this outside class without helper function
    // forward declared member variable
};

// note: since this is definition we can access private/protected values
int Something::z{2};  // definition of forward declared object

int Something::getTheValueTwo()  // static function definition; Note: no need to say static
{
    // static functions have no this pointer and thus cannot access non static 
    // member functions or variables
    return 2;
}

int main()
{
    std::cout << Something::x << '\n';  // you can access static members before obj is ever made
    // this makes sense since static is created at start of program and destoryed at end of program

    Something::x = 5;  // change value of static member
    std::cout << Something::x << '\n';

    Something s {};
    s.x = 3;  // also possible to access in member operation; prefer :: tho
    // :: makes it obvious that this is static member and also that its obj independent

    std::cout << Something::x << '\n';

    std::cout << Something::getValue() << '\n';

    return 0;
}

