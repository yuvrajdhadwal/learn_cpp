#include <string>
#include <string_view>
#incldue <iostream>

class Person
{
    private:
    std::string m_name{};
    int m_age{};

    public:
    Person(std::string_view name, int age)
        : m_name {name}
        , m_age {age}
    {}

    [[nodiscard]] auto getName() const -> const std::string& { return m_name; }
    [[nodiscard]] auto getAge() const -> int { return m_age; }
};

class Employee
{
    private:
    std::string m_employer{};
    double m_wage{};

    public:
    Employee(std::string_view employer, double wage)
        : m_employer { employer }
        , m_wage { wage }
    {}

    [[nodiscard]] auto getEmployer() const -> const std::string& { return m_employer; }
    [[nodiscard]] auto getWage() const -> double { return m_wage; }
};

class Teacher : public Person, public Employee  // multiple inheritance
                                                // note: if either of these classes had functions
                                                // with same signature, there would be ambiguoity
                                                // Concern: Diamond Problem don't have multiple
                                                // inheritance of classes that inherit from the
                                                // same class
                                                //
                                                // Generally: Avoid multiple inheritance unless
                                                // alternatives lead to increased complexity
{
    private:
    int m_teachesGrade{};

    public:
    Teacher(std::string_view name, int age, std::string_view employer, double wage, int teachesGrade)
        : Person {name, age}  // constructing multiple parent objects
        , Employee {employer, wage}
        , m_teachesGrade {teachesGrade}
    {}
};
