#include <iostream>
#include <string>
#include <sstream>  // for string stream

// command line arguments are strings that are similar to function parameters
// just for an executable instead of a function

// command line statement to run main.exe with command line args 'myfile.txt' and 'yourfile.txt'
// ./main myfile.txt yourfile.txt

// use double quotes to have spaces in your arguments
// use \" to have double quotes in your arguments

// sometimes written as:
// int main(int argc, char** argv)
int main(int argc, char* argv[])  // preferred way
// argc is argument count; executable is first argument, each argument increments this
// argv is c-style array of pointers to c-style strings
{
    std::cout << "There are: " << argc << " arguments:\n";

    for (int count {0}; count < argc; ++count)
    {
        std::cout << "\t-" << count << ". " << argv[count] << '\n';
    }

    std::stringstream convert {argv[1]};
    int myint{};
    if (!(convert >> myint)) { myint = 0; std::cout << "conversion failed\n"; }
    std::cout << "got int: " << myint << '\n';

    return 0;
}