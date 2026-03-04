#include <iostream>
#include <string>
#include <string_view>
#include <functional>
#include <vector>

/* *
 * Compositions are:
 *      1: member part of object
 *      2: member can only be part of one class at a time
 *      3: member has existence managed by object - death relationship
 *      4: member does not know of existence of object - unidirectional relationship
 *
 * Compositions may lazily instantiate members, may take in members, or allow something else
 * to handle cleanup of members 
 *
 * Classes are built to do one task, and do it well
 * Have member objects that do subtasks ; responsible for creation and deletion
 *
 * Aggregations are:
 *      1: member is part of object
 *      2: member can (if desired) belong to more than one object at a time
 *      3: member does not have its existence managed by the object
 *      4: member does not know of the existence of the object
 *
 * Typically references or pointers ; not responsible for creation or deletion
 */

class Point2D
{
    private:
    int m_x;  // Compositions
    int m_y;  // Compositions

    public:
    Point2D()
        : m_x {0}
        , m_y {0}
    {}

    Point2D(int coord_x, int coord_y)
        : m_x {coord_x}
        , m_y {coord_y}
    {}

    friend auto operator<< (std::ostream& out, const Point2D& other) -> std::ostream&
    {
        out << '(' << other.m_x << ", " << other.m_y << ')';
        return out;
    }

    void setPoint(int coord_x, int coord_y)
    {
        m_x = coord_x;
        m_y = coord_y;
    }
};

class Creature
{
    private:
    std::string m_name;  // Compositions
    Point2D m_location;  // Compositions

    public:
    Creature(std::string_view name, const Point2D& location)
        : m_name {name}
        , m_location {location}
    {}

    friend auto operator<< (std::ostream& out, const Creature& other) -> std::ostream&
    {
        out << other.m_name << " is at " << other.m_location;
        return out;
    }

    void moveTo(int coord_x, int coord_y)
    {
        m_location.setPoint(coord_x, coord_y);
    }
};

class Teacher
{
    private:
    std::string m_name{};

    public:
    Teacher(std::string_view name)
        : m_name {name}
    {}

    [[nodiscard]] auto getName() const -> const std::string& { return m_name; }
};

class Department
{
    private:
    const Teacher& m_teacher;  // Aggregations

    public:
    Department(const Teacher& teacher)
        : m_teacher {teacher}
    {}

    [[nodiscard]] auto getTeacher() -> const std::string& { return m_teacher.getName(); }
};

auto main() -> int
{
    std::string tom {"Tom"};
    std::string ada {"Ada"};
    
    // references can't be stored because theyre not assignable, we could use pointers
    // but pointers can be null
    std::vector<std::reference_wrapper<std::string>> names { tom, ada };  // ref wrap is wrapper
                                                                          // class for references
    std::string jim {"Jim"};

    names.emplace_back(jim);

    for (auto name : names)
    {
        name.get() += " Beam";  // use .get() to access the variable
    }

    std::cout << jim << '\n';  // prints out Jim Bean
}
