#include <iostream>

int main()
{
    std::cout << "Hello World!";  // const char[13] c-style string literal
    // c-style string literals end with null terminator '\0'
    // C-style string literals are const objects that are created at the start of the program 
    // and are guaranteed to exist for the entirety of the program.

    [[maybe_unused]] double d {5.5};  // double
    [[maybe_unused]] float f {5.5f};  // float thanks to suffix
    [[maybe_unused]] int i {5};  // type int
    [[maybe_unused]] long l {5L};  // type long, use capital L per convention
    [[maybe_unused]] unsigned int ui {5u};  // type unsigned int

    [[maybe_unused]] unsigned int a { 5 };  // int literal passed in and then 
    // implicit cast to unsigned int

    [[maybe_unused]] long b { 5 };  // int literal passed in and then implicit cast to long

    return 0;
}
