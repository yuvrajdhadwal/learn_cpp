#include <iostream>
#include <vector>

std::vector<int> generate() {
    // using named object so mandatory copy elision doesn't apply
    std::vector v{1, 2, 3, 4, 5};  // copies {1,2,3,4,5} into vec1 with list initialization
    return v;
}

std::vector<int> func(std::vector<int> v2) {
    std::vector v3{v2[0] + v2[0]};  // Step 3: Construct value to be sent back to caller (3)
    return v3;                      // Step 4: Return value to caller (4)
    // this makes 4 copies of vector without move.
    // First is v1, then passing in v1, then creating v3, then returning v3
    // Technically last copy can be elidied if compiler is really good and aggressive
    // but we should not bet on it, this is called NVRO
}

/*
Move Semantics: Optimization that sometimes allows for inexpensive transfer of ownership
of data members from one object to another; rather than making expensive copy
Data members that cannot be moved are copied instead

Invoked When: Type of object supports move semantics, Object is being initialized with rval of
same type; and the move isn't elided.

This means you can return by value move-capable objects as it is inexpensive. Should be passed
in my const reference

Not many objects support move semantics. However, vector and strings do.
*/

std::vector<int> funcv2(const std::vector<int>& vv2)  // still same vector
{
    std::vector vv3{vv2[0] + vv2[0]};  // Step 3: Constructs new value
    return vv3;                        // Step 4: thanks to move semantics, this is not copied
    // compilers treat local variables in return statements are r values
}

int main() {
    std::vector vec1{1, 2, 3, 4, 5};  // copies {1,2,3,4,5} into vec1 with list initialization
    std::vector<int> vec2{vec1};      // copy constructor called vec1 into vec2 (deep copy)

    vec1[0] = 6;
    vec2[0] = 7;

    // notice how both are different
    std::cout << vec1[0] << ' ' << vec2[0] << '\n';

    std::vector v1{5};  // Step 1: - Construct value passed into caller (1 constructor)
    std::cout << func(v1)[0] << '\n';  // Step 2: - Actually pass in the value (2 constructor)

    std::vector vv1{5};  // Step 1: Construct value passed into caller (1 constructor)
    std::cout << funcv2(vv1)[0] << '\n';  // Step 2: Pass by Const Reference (1 constructor)

    std::cout << v1[0] << '\n';

    return 0;
}
