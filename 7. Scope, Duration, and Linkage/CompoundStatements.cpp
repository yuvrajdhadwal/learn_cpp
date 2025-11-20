#include <iostream>

constexpr int x {15};  // we should really have the "g_" prefix here or put it in a namespace

int main()
{  // Block start
    // Compound Statements (Blocks) are multiple statements treated as one
    int x {5};  // local var x in scope (shadows global x)
    {  // inner block start
        // Cpp compilers should support 256 levels of blocking

        // always keep variables in most inner scope possible (reduces program complexity)
        [[maybe_unused]] int y {6};  // local var y in scope
        std::cout << x << '\n';  // x is still in scope in inner block

        int x {7};  // no local var linkage, thus this is allowed (will shadow outer scope x)
        std::cout << x << '\n';
        std::cout << "Wow! We printed x two times and got two different results!\n";

        // now global x is being shadowed but we can still refer to it
        std::cout << ::x << '\n';
        std::cout << "Wow! What the Heck! x has a different value again??\n";

    }  // inner block end and local var y out of scope

    [[maybe_unused]] int y {5};  // totally fine since the earlier y is now out of scope

    return 0;
}  // Block end