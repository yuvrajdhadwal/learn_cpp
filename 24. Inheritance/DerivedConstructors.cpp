/* *
 * When a constructor is called:
 *      1. Memory for the new object is set aside
 *      2. Appropriate constructor is called
 *      3. Member initializer list initializes variables
 *      4. Body of constructor executes
 *      5. Control is returned to the caller
 *
 * When a derived class's constructor is called:
 *      1. Memory for the derived object is set aside (enough for both base and derived portions)
 *      2. Appropriate derived constructor is called
 *      3. Base object is constructed first using Appropriate base constructor
 *          3a. If no base constructor specified, default constructor will be used
 *      4. Member initializer list initializes variables
 *      5. Body of the constructor is executed
 *      6. Control returned to the caller
 * */
#include <iostream>

class Base
{
    int m_id{};  // member variables are back to being private
    public:

    Base(int id = 0)
        : m_id {id}
    {}

    [[nodiscard]] auto getId() const -> int { return m_id; }
};

class Derived : public Base
{
    double m_cost{};
    public:

    Derived(double cost = 0.0, int id = 0)
        : Base {id}  // this is how to call the parent class constructor
        , m_cost {cost}
    {}

    [[nodiscard]] auto getCost() const -> double { return m_cost; }
};

auto main() -> int
{
    Derived derived {1.3, 4};
    std::cout << "Id: " << derived.getId() << '\n';
    std::cout << "Cost: " << derived.getCost() << '\n';

    /* *
     *      1. Memory for Derived is being allocated
     *      2. Derived(double, int) is called with args {cost = 1.3, id = 5}
     *      3. Base(int) with arg {id = 5} is called
     *      4. Base constructor member initializer is called setting m_id to 5
     *      5. Base constructor body is executed (nothing happens)
     *      6. Base constructor call returns back to Derived
     *      7. Derived initializer list is called setting m_cost to 1.3
     *      8. Derived Constructor body is executed (does nothing)
     *      9. Derived constructor call returns
     *
     *      Same logic is chained for multiple levels of subclasses
     *      They can only go sequentially up chain (can't skip parent constructor for grandparent)
     *
     *      When derived class is destroyed, they are destoryed in reverse order of constuction
     *      in this case that means Derived destroyed then Base destoryed
     * */

    return 0;
}
