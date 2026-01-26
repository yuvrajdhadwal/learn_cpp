#include <iostream>
#include <string>

struct Employee
{
    int id;  // member variables of the struct, no initialization (bad)
    // always provide default members
    int age {20};  // default member initializer
    // should be `double wage {0.0};` however, we want to show value initialization here
    double wage {};  // empty curly braces ensure value initialization when Employee initialized
    // if you later choose to add more members to a struct, it's best practice to add them to end
    bool is_manager {false};
};

// in most cases, structs and classes should be owners
// this means data members shouldn't be viewer, pointers, or references
struct Company
{
    int numOfEmployees{};
    Employee CEO{};  // Employee is struct within Company Struct
    std::string companyName{};  // notice this is not std::string_viewer
};

void printEmployee(const Employee& employee)  // note pass by reference of struct
{
    std::cout << "ID: " << employee.id << '\n';
    std::cout << "Age: " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
    // std::boolalpha makes booleans true/false instead of 0/1
    std::cout << "Is_Manager: " << std::boolalpha << employee.is_manager << '\n';
}

Employee getDefaultEmployee()  // return struct of type employee
{
    return {};  // type deduced, default value initialized
}

int main()
{
    Employee joe {};  // value initialize all members, id is value initialized, etc (prefer)
    Employee frank;  // declaring struct, id uninitialized, age = 20, wage = 0.0, is_manager=false

    joe.age = 32;

    // explicit values take precedence over defaults
    Employee yuvraj {1, 19, 48};  // list initialization using braced list (preferred)
    Employee amy = {2, 21, 0};  // copy-list initialization using braced list
    Employee anik (3, 20, 0); // direct initialization with parenthesized list(c++20)(not preferred)

    Employee pareen {4};  // uses default for age, value initializes wage to 0.0

    constexpr Employee admin {-1};  // const and constexpr treated same as regular

    Employee test { .id{9999}, .wage{-1}};  // designated initializer for structs, must be in 
    // order of declaration, skipped values will be value initialized

    // reassign with initializer list
    yuvraj = {yuvraj.id, 20, 54};
    amy = {.id = amy.id, .age = 22, .wage = 25};

    Employee yuvraj_2 {yuvraj};  // initializing struct with struct

    Company databricks {13000, {1}};  // nested initialization

    std::cout << databricks.CEO.wage << '\n';  // print member's member

    std::cout << joe.age << '\n';
    printEmployee(yuvraj);
    printEmployee(amy);
    printEmployee(Employee {10});  // construct temp employee struct, type specified (preferred)
    printEmployee({11});  // construct temp employee struct, type deduced
    printEmployee(getDefaultEmployee());

    // Notice how size of struct is larger than members combined, this is due to padding
    // minimize padding by reordering in descending order of size
    std::cout << "Size of Company: " << sizeof(Company) << '\n';
    std::cout << "Size of Members of Company: "
        << sizeof(std::string) + sizeof(int) + sizeof(Employee) << '\n';

    return 0;
}