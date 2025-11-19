#include <iostream>
#include <string>  // allows use of std::string
#include <string_view>  // allows use of std::string_view as of C++17

void printStringView(std::string_view str)
{
    // std::string_view is read only, thus no expensive string initialization here
    // will implicitly convert std::string and c-style strings into std::string_view
    // the opposite is not possible unless using static_cast
    std::cout << str << '\n';
    // string_view values are based of the object it is viewing
    // if the object it is viewing changes, it's undefined behavior
    // if the object it is viewing is destroyed, its' undefined behavior
}

int main()
{
    // avoid c-style strings in favor of std::string and std::string_view
    // c-style strings exist for duration of program (technically static)
    // std::string is dynamically allocated memory, expensive initialization (heap)
    // string data stored in heap but string pointer is stored in the stack
    // avoid pass by value in functions
    std::string this_is_an_empty_string{};  // empty string
    std::string name {"Yuvraj"};  // Initialization with value
    name = "Amy";  // Change the string, notice how its different lengths 
    // (not possible with C strings)

    std::string fav_color{};
    std::cout << "Enter your favorite color: ";
    std::cin >> fav_color;

    // to get full line (not just until first whitespace with cin)
    std::string full_name{};
    std::cout << "Enter your full name: ";
    // std::ws tells cin to ignore leading whitespace before extraction
    // this ignores the implict \n added from previous cin request
    // needs to be done for each std::getline() call since not preserved between calls
    std::getline(std::cin >> std::ws, full_name);  // full line of text into full_name
    std::cout << "Your full name is: " << full_name << " and your favorite color is: " << fav_color
                << '\n';
    
    // string length!
    std::cout << "The length of your name is: " << full_name.length() << '\n';
    [[maybe_unused]] int length {static_cast<int>(name.length())};

    using namespace std::string_literals;
    std::cout << "Test"s;
    // std::string suffix (s) turns c-style strings to std::string
    // need to be using the string_literals namespace though

    // string_view can be initialized from many types of strings
    [[maybe_unused]] std::string_view a {"Hello World!"};  // initailized from c-style string
    [[maybe_unused]] std::string_view b {full_name};  // initialized from std::string
    [[maybe_unused]] std::string_view c {a};  // initialized from std::string_view

    // you can pass in strings into a string_view paramater
    printStringView(full_name);

    [[maybe_unused]] constexpr std::string_view d {"Wow! Constexpr StringView! Can't be done"
        "with Strings"};

    // created a substring of std::string_view
    c.remove_prefix(3);
    c.remove_suffix(2);


    return 0;
}