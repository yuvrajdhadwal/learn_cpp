#include <iostream>

int getValue()
{
    std::cout << "Enter an integer: ";

    int x{};
    std::cin >> x;
    return x;
}

void printCalculation(int x, int y, int z)
{
    std::cout << x + (y * z);
}


int main()
{
    [[maybe_unused]] int x {5};
    [[maybe_unused]] int y {++x};  // prefix increment is more efficient than postfix increment

    // ++x will increment x and then return it
    // x++ will copy x, increment x, then return the copy of x which is still the old value

    // function arguments can be evaluated in any order
    printCalculation(getValue(), getValue(), getValue()); // this line is ambiguous
    // you think this line will evaluate to 7 but its actually 5!

    // comma operator
    std::cout << (++x, ++y) << '\n';  // evaluates x and then y, returns value of y

    constexpr bool bigClass {true};
    [[maybe_unused]] constexpr int classSize {bigClass ? 30 : 20};  // using ternarary operator to initialize

    // for readability make sure to include parenthesis since it can be confusing
    [[maybe_unused]] int z { (x > y) ? x : y};  // <-- makes it clear that x > y is bool not y
    std::cout << ((x > y) ? x : y);  // <-- without parentheisis << would evaluate before ?

    // floating point comparisons for really similar numbers may not be accurate
    constexpr double d {100.0 - 99.9};  // 0.1 (theoretically) 0.099999999999994316 (actually)
    constexpr double e {10.0 - 9.9};  // 0.1 (theoretically) 0.099999999999999645 (actually)

    std::cout << (d == e ? "equal" : "not equal");  // this prints not equal

    // overloaded logical operators will not short circuit evaluate
    // && has higher precedence than ||

    // following code leads to warnings since its confusing
    [[maybe_unused]] bool hi {4 == 2 || x != y && true};  // same as this: 4 == 2 (x != y && true)
    [[maybe_unused]] bool bye {4 == 2 or x != y and true};  // works too

    // de morgans law
    // !(x && y) --> !x || !y
    

    // for bools != is same as logical xor (not a thing in cpp)

    return 0;
}