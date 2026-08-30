#include <iostream>

void printDigit(int xxx)
// with switch statement this is clean and readable
{
    {
        [[maybe_unused]] int yyy{2};   // this variable is in scope for all cases
        switch (xxx)  // only works for integral or enumerated types (implemented as a jump table)
        // jump tables are very performant
        // no case matches? then switch is skipped
        {
            case 1: {
                std::cout << "One";
                [[maybe_unused]] int zzz{4};  // this variable is only initialized in
                           // this case, this is done through the scope braces that only exist for
                           // this case and not the rest
                return;    // could use break keyword here instead if return not possible. return just allows us to exit this switch and function, but break works too
            }
            case 2:
                std::cout << "Two";
                break;  // without these return/break statements
                // cases would fall through after first match
            case 3:
                std::cout << "Three";
                [[fallthrough]];  // compiler note to let it know this is intentional fallthrough
                // note the null statement after the compiler attribute
            default:
                std::cout << "Unknown";
                return;
        }
    }
}

auto main() -> int {
    printDigit(2);
    std::cout << '\n';

    return 0;
}
