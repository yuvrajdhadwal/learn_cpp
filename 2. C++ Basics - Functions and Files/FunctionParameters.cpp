#include <iostream>

int printValues(int x, int y, int, int z);  // forward function declaration/prototype

int main()
{
    // Pass By Value: Value of Arguments are Copied into Matching Parameter
        // This uses copy initialization of the arguments
    printValues(6, 7, 1000, 69);
    
    return 0;
}

// Function parameter exists but is not needed, remove the name and leave type
// Optionally leave a comment with what it used to be
int printValues(int x, int y, int /* a */, int z)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
    std::cout << z << '\n';

    return x + y + z; // Return by value returns a temporary object 
    // (that holds a copy of the return value) to the caller.
}
