#include <iostream>

// the main drawback of normal overloading over friends is that you need to forward 
// declare them in header files outside of the class declaration
// friend functions are auto declared so no need for explicit

Cents operator+(const Cents& c1, const Cents& c2);  // forward declare example

// prefer normal overloading over friend overloading this way we don't access
// the private member variables directly

class Cents
{
    private:
    int m_cents{};

    public:
    Cents(int cents) : m_cents {cents} {}
    int getCents() const { return m_cents; }
};

// instead of using friend functions, just use regular function
Cents operator+(const Cents& c1, const Cents& c2)
{
    return Cents { c1.getCents() + c2.getCents() };
}

int main()
{
    Cents c1 {5};
    Cents c2 {3};
    Cents c3 {c1 + c2};

    std::cout << c3.getCents() << " cents!\n";

    return 0;
}