#include <algorithm>  // for std::copy
#include <iostream>
#include <iterator>  // for std::size and std::ssize

int main()
{
    // array length must be constexpr, cant use auto or ctad
    int testScores[30] {};  // defines C-Style array containing 30 value init ints
    int c_arr[4] {1, 2, 3, 4};  // list init for arrays
    int c_arr_better[] {1, 2, 3, 4};  // list init with compiler deduced length (preferred)
    int c_arr_small[100] {1, 2, 3};  // remaining elements in array are value init to 0

    const int carr[] {1, 2, 3, 4};  // const and constexpr must be initialized
    constexpr int cearr[] {1, 2, 3, 4};  // and values cannot be changed afterwards

    testScores[1] = 45;

    std::cout << testScores[1] << '\n';

    // unlike containers, c-style arrays can be indexed with signed/unsigned integrals
    int signed_int {2};
    std::cout << testScores[signed_int] << '\n';
    unsigned int unsigned_int {2};
    std::cout << testScores[unsigned_int] << '\n';

    std::cout << sizeof(testScores) << '\n';  // gives sizeof c-style array in bytes
    std::cout << sizeof(testScores) / sizeof(testScores[0]) << '\n';  // length of array with math
    std::cout << std::size(testScores) << '\n';  // gives size c-style array in elements (unsigned)
    std::cout << std::ssize(testScores) << '\n';  // signed version

    // if we want to reassign a c-style array
    int orig[] {1, 2, 3};
    int newVer[] {4, 5, 6};
    std::copy(std::begin(newVer), std::end(newVer), std::begin(orig));  // copy new into orig


    // Note: cstyle arrays can decay into pointers when used in expressions
    // generally they are only used as constexpr global variables or static local functions
    // since these don't get passed around

    // can also be used as parameters in functions for non-constexpr c-style string arguments
    // this is because converting to std::string_view requires traversing string to get length
    // O(n) if this is performance critical code, then best to just take the c-style string
    // which is really a c-style array of chars or a char* with a null terminator


    return 0;
}