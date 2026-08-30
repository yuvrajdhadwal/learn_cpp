#include <cstdlib>  // for std::exit()
#include <iostream>

void example() { std::cout << "example was called!\n"; }

auto main() -> int {
    const bool isCrashing{true};
    std::atexit(example);  // at exit, call this function before exiting
    std::cout << 1 << '\n';
    int xyz{};
    std::cin >> xyz;

    if (isCrashing) {
        std::cout << 0 / xyz;
        std::abort();  // terminate abnormally
    }

    std::exit(0);  // this halts the program (calls exit) and cleans up static memory
    // since the proccess exits here the operating system will clean up any memory
    // but it will not call destructors so if theres any specific instructions in the destructor beyond
    // memory cleanup those won't be run (no destructor side effects)

    // the following code will never run due to the above std::exit
    std::cout << 2 << '\n';
    return 0;
}
