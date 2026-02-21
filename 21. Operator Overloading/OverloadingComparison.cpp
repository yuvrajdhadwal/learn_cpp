#include <iostream>
#include <string>
#include <string_view>

class Car
{
    private:
    std::string m_make{};
    std::string m_model{};

    public:
    Car(std::string_view make, std::string_view model)
        : m_make {make}
        , m_model {model}
    {}

    friend bool operator== (const Car& c1, const Car& c2);
    friend bool operator!= (const Car& c1, const Car& c2);
};

bool operator==(const Car& c1, const Car& c2)
{
    return c1.m_make == c2.m_make && c1.m_model == c2.m_model;
}

bool operator!=(const Car& c1, const Car& c2)
{
    return c1.m_make != c2.m_make || c1.m_model != c2.m_model;
}

// only define operator overloads that make sense for your class (< or > dont make sense here)
// however heres another class that you can do it with

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents)
        : m_cents{ cents }
    {}

    // notice how we use ! to simplify the comparison logic
    friend bool operator== (const Cents& c1, const Cents& c2) { return c1.m_cents == c2.m_cents; }
    friend bool operator!= (const Cents& c1, const Cents& c2) { return !(operator==(c1, c2)); }

    friend bool operator< (const Cents& c1, const Cents& c2) { return c1.m_cents < c2.m_cents; }
    friend bool operator> (const Cents& c1, const Cents& c2) { return operator<(c2, c1); }

    friend bool operator<= (const Cents& c1, const Cents& c2) { return !(operator>(c1, c2)); }
    friend bool operator>= (const Cents& c1, const Cents& c2) { return !(operator<(c1, c2)); }

};