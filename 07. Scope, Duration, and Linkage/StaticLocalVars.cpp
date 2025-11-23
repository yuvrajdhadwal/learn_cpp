#include <iostream>

void incrementAndPrint()
{
    int value {1};  // local variable
    ++value;
    std::cout << value << '\n';
}  // value destoryed here

void incrementAndPrintStatic()
{
    static int s_value {1};  // static variable that is initialized at program start
    // and destoryed at program end (static duration)
    // initialized, and then skipped at subsequent definitions
    ++s_value;  // follows "s_" prefix to make clear it's static
    std::cout << s_value << '\n';
}

int main()
{
    incrementAndPrint();  // prints the same value always
    incrementAndPrint();
    incrementAndPrint();

    // A static local variable has block scope like a local variable, 
    // but its lifetime is until the end of the program like a global variable.

    // std::cout << s_value;   - can only be accessed in scope even if it exists

    incrementAndPrintStatic();  // keeps incrementing 
    incrementAndPrintStatic();
    incrementAndPrintStatic();

    // s_value is still not destroyed but not in scope either

    // generally not good to change state within functions, you should do it based on parameters
    // that way functions behave the same way everytime, and you can customize them at calltime

    return 0;
}