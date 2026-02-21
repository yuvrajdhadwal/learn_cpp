#include <iostream>

class Cents
{
    private:
    int m_cents{};

    public:
    Cents(int cents) : m_cents {cents} {}

    // overload -Cents as a member function
    Cents operator-() const;
    bool operator!() const;  // returns true if m_cents is 0
    int getCents() const { return m_cents; }
};

Cents Cents::operator-() const
{
    return -m_cents;  // will infer that return type is Cents and will convert to Cents
}

bool Cents::operator!() const
{
    return m_cents == 0;
}

int main()
{
    const Cents nickle{5};
    std::cout << "A nickle is " << nickle.getCents() << " not " << (-nickle).getCents() << '\n';
    std::cout << !nickle << '\n';

    return 0;
}