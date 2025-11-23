//  When you #include a file, the preprocessor replaces the #include directive with
//  the contents of the included file. The included contents are then preprocessed
//  (which may result in additional #includes being preprocessed recursively),
//  then the rest of the file is preprocessed.

#include <iostream>

//  Object-like Macro with substitution text - avoid since legacy
#define MY_NAME "Yuvraj"
#define PRINT_JOE  // Object-like Macro without substition text - generally acceptable

int main()
{
    std::cout << "Hello World!\n";
    std::cout << "My name is " << MY_NAME << '\n';

    #ifdef PRINT_JOE  // check whether an identifier has been previously defined via #define
        std::cout << "Joe\n";  // will be compiled
    #endif

    #ifdef PRINT_BOB
        std::cout << "Bob\n";  // will not be compiled
    #endif

    #ifndef PRINT_BOB  // opposite of ifdef
        std::cout << "Bob does not exist\n";  // will be compiled
    #endif

    #if 0  // if 0, then all code within block wont be compiled. if if want to be compiled
        std::cout << "We are in 1 if this is printed!"
    #endif

    return 0;
}
