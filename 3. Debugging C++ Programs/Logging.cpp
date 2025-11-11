#include <plog/Log.h>  // Step 1. Include Logger Headers
#include <plog/Initializers/RollingFileInitializer.h>

#include <iostream>

int getUserInput()
{
    PLOGD  << "getUserInput() called";  // PLOGD is defined by the plog library

    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main()
{
    plog::init(plog::debug, "LogFile.txt");  // Step 2. Initialize the Logger

    PLOGD << "main() called";  // Step 3. Output to Log File

    int x{ getUserInput() };
    std::cout << "You Entered: " << x << '\n';

    return 0;
}
