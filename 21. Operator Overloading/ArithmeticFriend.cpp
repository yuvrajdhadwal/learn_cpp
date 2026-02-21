#include <iostream>

class Cents
{
    private:
    int m_cents{};

    public:
    explicit Cents(int cents) : m_cents {cents} {}
    int getCents() const { return m_cents; }

    // add Cents + Cents with friend function
    friend Cents operator+(const Cents& c1, const Cents& c2);
    friend Cents operator-(const Cents& c1, const Cents& c2);

    // friend functions can be defined within classes (preferred for trivial cases)
    friend Cents operator*(const Cents& c1, const Cents& c2)
    {
        return Cents {c1.m_cents * c2.m_cents};
    }

    // binary operands of the same type can take x + y and y + x
    // but if they are different types then they need two seperate functions
    friend Cents operator+(const Cents& c1, int v);
    friend Cents operator+(int v, const Cents& c1);
};


// this is a friend function
Cents operator+(const Cents& c1, const Cents& c2)
{
    return Cents {c1.m_cents + c2.m_cents};  // can use private members since its a friend
}

Cents operator-(const Cents& c1, const Cents& c2)
{
    return Cents {c1.m_cents - c2.m_cents};
}

Cents operator+(const Cents& c1, int v)
{
    return Cents {c1.m_cents + v};
}

// this only works since + is commutitive 
Cents operator+(int v, const Cents& c1) { return c1 + v; }  // calling other operator overload

int main()
{
    Cents c1 {6};
    Cents c2 {8};
    Cents c3 {c1 + c2};  // this uses operator+ and copy constructor
    Cents c4 {c3 - c2};
    Cents c5 {c3 * c4};
    Cents c6 {c5 + 5};
    Cents c7 {10 + c6};

    std::cout << "I have " << c3.getCents() << " cents!\n";
    std::cout << "Now, I have " << c4.getCents() << " cents!\n";
    std::cout << "Now, I have " << c5.getCents() << " cents!\n";

    return 0;
}