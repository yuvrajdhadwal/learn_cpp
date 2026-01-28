#include <iostream>

class Foo
{
    public:
    // first matching constructor is found, then memory is allocated, then constructor is called
    // can have default values
    Foo(int x, int y = 5)  // Foo Constructor, should not be const
    // initialized in order of definition in class not order in list
    // in this case m_x then m_y, even though the list is other way
    // member variables should be listed in order that they are declared
        : m_y {y}  // direct member initializer list (cant use copy for this)
        , m_x {x != 0 ? x : 0}  // throw error here 
        // use this format for initializer list (easier to read since aligned)
    {
        std::cout << "Foo (" << x << ", " << y << ") constructed\n";
        // m_y = y  this is assignment not initialization
    }

    // overloaded constructor! make sure constructors are disambigious
    // won't zero initialize; default/implicit will zero initialize
    // may be faster than default/implicit in high freq loops
    Foo() : Foo {2, 4}  // constructor chaining
    {
        std::cout << "Default Constructor!\n";
        print();  // you can call member functions from constructors
    }

    // implicit default constructor is given if no constructor is defined
    // if we want it but already have a defined constructor we can specify with
    // Foo() = default;  // note this is commented to disambiguate 

    void print() const
    {
        std::cout << "Foo (" << m_x << ", " << m_y << ")\n";
    }

    Foo getNewFoo()
    {
        return Foo {};  // creates new temporary object Foo{}, initializes another Foo{} and returns
    }

    private:
    int m_x {};  // default value of 0,
    int m_y {2};  // default value of 2, 
};

int main()
{
    Foo foo {6, 7};  // Calling Foo Constructor
    Foo bar {1, false};  // false is converted from bool to int
    Foo test {3};  // calls Foo(int, int)

    Foo def {};
    Foo def2;  // equivalent to above, prefer value initialization though

    foo.print();
    bar.print();
    def.print();
    test.print();

    return 0;
}