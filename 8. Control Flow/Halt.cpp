#include <cstdlib>  // for std::exit()
#include <iostream>

void example()
{
    std::cout << "example was called!\n";
}

int main()
{
    std::atexit(example);  // at exit, call this function before exiting
    std::cout << 1 << '\n';
    int x{};
    std::cin >> x;
    if (true)
    {
        std::cout << 0 / x;
        std::abort();  // terminate abnormally (vscode will highlight the line)
    }
    std::exit(0);  // this halts the program (calls exit) - does not clean up local vars

    std::cout << 2 << '\n';  // this and following code will never run

    return 0;
}