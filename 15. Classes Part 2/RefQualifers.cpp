#include <iostream>
#include <string>
#include <string_view>

class Employee {
   private:
    std::string m_name{};

   public:
    Employee(std::string_view name) : m_name{name} {}

    const std::string& getName() const& { return m_name; }  // & qualifier overloads function to
    // only handle lvalue implicit objects

    std::string getName() const&& { return m_name; }  // && qualifer overloads function to only
    // handle rvalue implicit objects

    // non ref qualified overloads cannot be done if refqualified overloads exist for a function
    // lvalue overload takes rvalue if no rvalue overload
    // you can delete either oveload with "= delete"
};

// returns by value (rvalue)
Employee createEmployee(std::string_view name) {
    Employee e{name};
    return e;
}

int main() {
    Employee joe{"joe"};
    // getName returns reference
    std::cout << joe.getName() << '\n';  // joe is lvalue ref, so this calls getName() &

    // getName returns copy of string
    std::cout << createEmployee("bob").getName() << '\n';  // bob is rvalue, so calls getName() &&

    return 0;
}
