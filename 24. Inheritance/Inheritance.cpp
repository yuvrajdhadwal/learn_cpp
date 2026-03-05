#include <iostream>
#include <string>
#include <string_view>

/* *
 * Inheritance: "is a" relationship
 * parent/base/superclass -> child/derived/subclass
 *
 * Inheritance ensures we don't need to keep redefining things; reduces bugs
 * */

class Person
{
    public:
    std::string m_name{};
    int m_age{};

    Person(std::string_view name = "", int age = 0)
        : m_name {name}
        , m_age {age}
    {}

    [[nodiscard]] auto getName() const -> const std::string& { return m_name; }
    [[nodiscard]] auto getAge() const -> int { return m_age; }
};

// BaseballPlayer publically inheriting Person
class BaseballPlayer : public Person
{
    public:
    double m_battingAverage{};
    int m_homeRuns{};

    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
        : m_battingAverage{battingAverage}
        , m_homeRuns{homeRuns}
    {}
};

class Employee : public Person
{
    public:
    double m_hourlySalary{};
    long m_employeeID{};

    Employee(double hourlySalary = 0.0, long employeeID = 0)
        : m_hourlySalary{hourlySalary}
        , m_employeeID{employeeID}
    {}

    void printNameAndSalary() const
    {
        std::cout << m_name << ": " << m_hourlySalary << '\n';
    }
};

class Supervisor : public Employee
{
    public:
    long m_overseesIDs[5]{};  // supervisor can oversee 5 employees
};

// Superivsor -> Employee -> Person
// BaseballPlayer -> Person

auto main() -> int
{
    BaseballPlayer joe{};
    joe.m_name = "Joe";  // BaseballPlayer inherits from Person; so we can access Person members
    std::cout << joe.getName() << '\n';

    Employee frank{};
    frank.m_name = "Frank";
    frank.printNameAndSalary();

    return 0;
}
