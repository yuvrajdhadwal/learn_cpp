#include <iostream>

class Base
{
    public:
    int m_id{};

    Base(int id = 0)
        : m_id {id}
    {
        std::cout << "Base!\n";
    }

    [[nodiscard]] auto getId() const -> int { return m_id; }
};

class Derived : public Base
{
    public: 
    double m_cost{};

    Derived(double cost = 0)
        : m_cost {cost}
    {
        std::cout << "Derived!\n";
    }

    [[nodiscard]] auto getCost() const -> double { return m_cost; }
};

// constructors are always called first in the most base class then down till the most
// child class
auto main() -> int
{
    std::cout << "Instantiating Base\n";
    Base base;

    std::cout << "Instantiating Derived\n";
    Derived derived;

    return 0;
}
