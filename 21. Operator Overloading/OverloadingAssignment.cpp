#include <cassert>
#include <iostream>
#include <ostream>

// If new object has to be created before the copying can occur, copy constructor used 
//      (pass/return by value)
// IF new object does not have to be created before the copying can occur, assignment is used
class Fraction  // NOLINT(cppcoreguidelines-special-member-functions)
{
    private:
    int m_numerator {0};
    int m_denominator {1};

    public:
    // Default Constructor
    Fraction(int numerator = 0, int denominator = 1) // NOLINT(bugprone-easily-swappable-parameters)
        : m_numerator {numerator}
        , m_denominator {denominator}
    {
        assert(denominator != 0);
    }

    // Copy Constructor
    Fraction(const Fraction& copy)
        : m_numerator {copy.m_numerator}
        , m_denominator {copy.m_denominator}
    {
        // no need to worry about self assignment for copy constructors since we are making new obj
        std::cout << "Copy Constructor called!\n";
    }

    // overloaded assignment operator
    // the copy assignment operator is given by default
    auto operator= (const Fraction& fraction) -> Fraction&;
    
    // can disable copy assignment
    // auto operator= (const Fraction& fraction) -> Fraction& = delete;

    // overloaded << operator
    friend auto operator<< (std::ostream& out, const Fraction& frac) -> std::ostream&;
};

auto operator<< (std::ostream& out, const Fraction& frac) -> std::ostream&
{
    out << frac.m_numerator << '/' << frac.m_denominator << '\n';
    return out;
}

auto Fraction::operator=(const Fraction& fraction) -> Fraction&
{
    // handling self assignment
    if (this == &fraction) { return *this; }

    // do the copy
    m_numerator = fraction.m_numerator;
    m_denominator = fraction.m_denominator;

    // return existing object so we can chain operator
    return *this;
}

auto main() -> int
{
    Fraction frac {4, 3};
    Fraction frac2;
    frac2 = frac;  // overloads assignment
    std::cout << frac2;  // overloads print

    Fraction frac7 {2, 3};
    Fraction frac8 {1, 2};
    Fraction frac9 {0, 2};

    frac7 = frac8 = frac9;  // chained assignment
    // frac7 = frac7;  // self assignment

    return 0;
}