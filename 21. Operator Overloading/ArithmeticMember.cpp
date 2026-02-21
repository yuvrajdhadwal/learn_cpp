#include <iostream>

// you can overload with friends, normally, or even member functions!

class Cents
{
    private:
    int m_cents {};

    public:
    Cents(int cents) : m_cents {cents} {}
    
    // member function overloading Cents + int
    Cents operator+(int v) const;
    int getCents() const { return m_cents; }
};

// member function with implict *this parameter
Cents Cents::operator+(int v) const
{
    return Cents { this->m_cents + v };
}

int main()
{
    const Cents c1 {6};
    const Cents c2 {c1 + 16};
    std::cout << "I have " << c2.getCents() << " cents!\n";

    return 0;
}
