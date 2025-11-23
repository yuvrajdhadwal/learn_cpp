#include <iostream>

// Comment out the following line when not debugging
// Should put this in a header file included in all programs so that you only need to enable
// debugging in one file for debugging to be set for all files
#define ENABLE_DEBUG  // Use preprocessor directives to state whether program should be compiled
// in debug or executable version

int getUserInput()
{
#ifdef ENABLE_DEBUG  // Preprocessor conditional that allows debugging lines if in debug mode
std::cerr << "getUserInput() called\n";  // Unbuffered Print (better for debugging)
#endif  // Debugging print statements should not be indented so that easier to see
    std::cout << "Enter a Number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main()
{
#ifdef ENABLE_DEBUG
std::cerr << "main() called\n";
#endif
    int x{ getUserInput() };
    std::cout << "You entered: " << x << '\n';

    return 0;
}
