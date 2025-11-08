#include <iostream>

int main()
{
    // Best Practice: output new line whenever line of output is complete
    std::cout << "Hi!" << std::endl;
    std::cout << "My name is Yuvraj!" << std::endl; // technically this endl is unneccessary

    // cout is buffered, which means sometimes it won't flush if program crashes before flush
    // endl starts a new line and also flushes the buffer (may be inefficient)

    // When outputting text to the console, we typically don’t need to explicitly 
    // flush the buffer ourselves. C++’s output system is designed to self-flush periodically,
    // and it’s both simpler and more efficient to let it flush itself.

    int x{ 5 };                                     // direct initializer list

    std::cout << "x is equal to " << x << '\n';     // single quote new-line (conventional)
    std::cout << "Yep" << "\n";                     // double quote new-line (unconventional)
    std::cout << "That's it\n";                     // within text (conventional)

    // Best Practice: Prefer \n over std::endl when outputting text to the console.

    std::cout << "Enter two numbers seperated by any kind of whitespace: ";

    int a{};
    int b{};
    std::cin >> a >> b;                             // store multiple variables with one cin
    
    // Each line of input data in the input buffer is terminated by a '\n' character.
    // input is buffered so that multiple extractions can be called from one input
    
    std::cout << "You "         // quotes seperated by only whitespace will be concatenated
        "entered " << a << " and " << b << '\n';

    return 0;
}
