#include <iostream>

int main()
{
    // only have the scope of the block it is in
    using Distance = double;  // type alias for double as distance
    using Liberals = double;
    typedef double DSA;  // also a type alias but the C version

    {
        // if you want type alias in different files, put them in header files and include them
        using Conservatives = double;
        [[maybe_unused]] Conservatives Kirk {15};
    }

    Distance d {3.4};
    Liberals l {1.2};
    // Conservatives Kirked {15.5};  - not possible (out of scope)

    // the following is not best coding practice even if legal, keep semantically different types
    // semantically different.
    std::cout << d + l << '\n';  // totally fine even though its two alias since theyre both doubles

    return 0;
}