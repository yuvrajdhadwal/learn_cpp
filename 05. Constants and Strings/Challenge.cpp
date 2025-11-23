#include <iostream>
#include <string>
#include <string_view>

void printName(std::string_view name_1, int age_1, std::string_view name_2, int age_2)
{
    std::cout << name_1 << " (age " << age_1 << ") is older than " << name_2
        << " (age " << age_2 << ").\n";
}

int main()
{
    std::cout << "Enter name of person #1: ";
    std::string person_1{};
    std::getline(std::cin >> std::ws, person_1);

    std::cout << "Enter age of " << person_1 << ": ";
    std::string person_1_age{};
    std::getline(std::cin >> std::ws, person_1_age);

    std::cout << "Enter name of person #2: ";
    std::string person_2{};
    std::getline(std::cin >> std::ws, person_2);

    std::cout << "Enter age of " << person_2 << ": ";
    std::string person_2_age{};
    std::getline(std::cin >> std::ws, person_2_age);

    int person1_age {std::stoi(person_1_age)};
    int person2_age {std::stoi(person_2_age)};

    if (person1_age > person2_age)
    {
        printName(person_1, person1_age, person_2, person2_age);
    } else if (person1_age < person2_age)
    {
        printName(person_2, person2_age, person_1, person1_age);
    } else
    {
        std::cout << person_1 << " (age " << person1_age << ") is the same age as " << person_2
            << " (age " << person2_age << ").\n";
    }
    
    return 0;
}