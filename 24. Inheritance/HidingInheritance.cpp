#include <iostream>

class Base
{
    private:
    int m_value{};

    public:
    Base(int value)
        : m_value {value}
    {}
    
    int m_pubVal{};
    void printValue(int) const {}
    void printValue(double) const { std::cout << m_value; }

    protected:
    void printValue() const { std::cout << m_value; }
};

class Derived : public Base
{
    private:
    using Base::m_pubVal; // makes public value from parent into a private variable
                   
    public:
    Derived(int value)
        : Base { value }
    {}

    // Base::printValue was inherited as protected, so the public has no access
    // But we're changing it to public via a using declaration
    // Brings all printValues from Base into Derived
    using Base::printValue;
    void printValue(double) const = delete;  // marks this as inaccessible
};

auto main() -> int
{
    // just cause inaccessible doesn't mean the parent is inaccessible
    Derived derived{333};
    derived.Base::printValue(123.3);
    static_cast<Base&>(derived).printValue(4.5);
}
