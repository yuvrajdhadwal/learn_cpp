#include <iostream>

class Fraction
{
    public:
    // Regular Constructor
    // due to explicit keyword, cannot do copy initialization or copy list initialization
    // cannot do implicit conversions either
    // totally fine to do direct and direct list initialization
    // explicit best practice: if constructor can have 1 arg, make constructor explicit
    explicit Fraction(int numerator = 0, int denominator = 1)
        : m_numerator {numerator}
        , m_denominator {denominator}
    {
        std::cout << "Constructor Called!\n";
    }

    // Copy Constructor
    // Should do nothing beyond copying since compiler may optimize copy constructor out
    // Prefer default copy constructor over custom one
    // copy/move constructors should not be made explicit
    Fraction(const Fraction& o)  // use const lvalue reference for copy constructor
        : m_numerator {o.m_numerator}
        , m_denominator {o.m_denominator}
    {
        // bad practice
        std::cout << "Copy Constructor Called!\n";
    }

    // Could also do the Copy Constructor like this
    // Fraction(const Fraction& o)
    //     : Fraction {o.m_numerator, o.m_denominator}
    // {
    //     // Constructor Chains first then this is called
    //     std::cout << "Copy Constructor Chains with Main Constructor!\n";    
    // }

    // or this for explicit default copy constructor
    // Fraction(const Fraction& o) = default;

    // or this for ensuring there is no copy constructor (ensure no copying allowed)
    // Fraction(const Fraction& o) = delete;

    // rule of five
    // copy constructor, destructor, copy-assignment, move consturctor, move assignment operator
    // if one is user defined, all should be user defined
    

    void print() const
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }

    private:
    int m_numerator { 0 };
    int m_denominator { 1 };
};

void printFraction(Fraction f)  // pass by value, uses copy constructor
{
    f.print();
}

Fraction generateFraction(int n, int d)
{
    // creates temporary object with constructor
    Fraction f {n, d};
    return f;  // creates temp return value with copy constructor
    // this doesn't work as comments due to named return value optimizations / copy elision
}

int main()
{
    Fraction f {5, 3};  // Calls Fraction(int, int)
    Fraction fCopy {f};  // Copy Constructor!

    f.print();
    fCopy.print();

    printFraction(f);  // pass by value, needs to copy value

    Fraction z {generateFraction(1, 2)};
    printFraction(z);

    return 0;
}
