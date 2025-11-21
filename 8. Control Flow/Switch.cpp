#include <iostream>

void printDigit(int x)
// with switch statement this is clean and readable
{
    switch (x)  // only works for integral or enumerated types (implemented as a jump table)
    // jump tables are very performant
    // no case matches? then switch is skipped
    {
        int y {5}; // this variable is in scope for all cases
    case 1:
        std::cout << "One";
        int z {5};  // this variable is in scope for all cases, but is only initialized in this case
        return;  // could use break keyword here instead if return not possible
    case 2:
        std::cout << "Two";
        return;  // without these return/break statements
        // cases would fall through after first match
    case 3:
        std::cout << "Three";
        [[fall_through]];  // compiler note to let it know this is intentional fallthrough
        // note the null statement after the compiler attribute
    default:
        std::cout << "Unknown";
        return;
    }
}

int main()
{
    printDigit(2);
    std::cout << '\n';

    return 0;
}