#include <iostream>

class Digit
{
    private:
    int m_digit{};

    public:
    Digit(int digit = 0) : m_digit {digit} {}

    // prefix increment and decrement
    Digit& operator++();
    Digit& operator--();

    // postfix increment and decrement
    Digit operator++(int);
    Digit operator--(int);

    friend std::ostream& operator<< (std::ostream& out, const Digit& d);
};

Digit& Digit::operator++()
{
    if (m_digit == 9) { m_digit = 0; }  // handling wrap around
    else { ++m_digit; }

    return *this;  // reference to current object
}

Digit& Digit::operator--()
{
    if (m_digit == 0) { m_digit = 9; }  // handling wrap around
    else { --m_digit; }

    return *this; // this is so that we can chain multiple operators together
}

Digit Digit::operator++(int)  // postfix
{
    Digit temp{*this};  // temp var of current object
    ++(*this);  // using prefix operator to update current object
    return temp;  // return the saved temp state
}

Digit Digit::operator--(int)  // dummy parameter (no name means compiler wont warn)
{
    Digit temp{*this};  // temp copy
    --(*this);  // calling pre decrement
    return temp;
}

std::ostream& operator<< (std::ostream& out, const Digit& d)
{
    out << d.m_digit;
    return out;
}

int main()
{
    Digit d {8};

    std::cout << d << '\n';
    std::cout << ++d << '\n';
    std::cout << d++ << '\n';
    std::cout << ++d << '\n';
    std::cout << --d << '\n';
    std::cout << d-- << '\n';
    std::cout << --d << '\n';

    return 0;
}