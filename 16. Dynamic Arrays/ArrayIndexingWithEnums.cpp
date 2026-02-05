#include <iostream>
#include <vector>

namespace Students
{
    enum Names
    {
        kenny,  // 0
        kyle,  // 1
        stan,  // 2
        butters,  // 3
        cartman,  // 4
        max_students  // 5
    };

    enum NamesPt2 : unsigned int
    {
        ke,  // 0
        ky,  // 1
        s,  // 2
        b,  // 3
        c,  // 4
    };
}

int main()
{
    std::vector testScores {78, 92, 100, 54, 99};
    // this works since enums are constexpr, thus not narrowing converstion to std::size_t
    testScores[Students::stan] = 76;  // we know this index refers to stan now, no magic numbers

    Students::NamesPt2 name {Students::ke};  // no longer constexpr
    testScores[name] = 62;  // this works since enum is specified as type unsigned int

    testScores[Students::c] = 14;  // this works too!

    return 0;
}