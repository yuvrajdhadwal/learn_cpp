#include <iostream>

// constexpr function all arguments must be constexpr
constexpr int max(int x, int y)
{
    if (x > y)
    {
        return x;
    } else {
        return y;
    }
}

int main()
{
    // As-if rule discussed in CompilerOptimizations.cpp is compiler dependent
    // if you want to force compile time evaluation
    // you must do "compile-time programming"

    // -> makes code more performant and higher quality - better security and less buggy

    // must always be evaluated at any point in code during compile time
    constexpr int x { 3 + 3 };  // constexpr forces expression to be evaluateable at compile-time

    [[maybe_unused]] constexpr double grav {9.8};
    constexpr int y {x};

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    // Differences between const and constexpr with runtime constant

    // const means that the value of an object cannot be changed after initialization. 
    // The value of the initializer may be known at compile-time or runtime. 
    // The const object can be evaluated at runtime.
    const int age_now {age};  // Constant value that cannot change later

    // constexpr means that the object can be used in a constant expression. 
    // The value of the initializer must be known at compile-time. 
    // The constexpr object can be evaluated at runtime or compile-time.
    // Implicitly const
    // constexpr int age_now2 {age};  // Cannot be evaluated at compile time

    std::cout << "Your age is " << age_now;

    // Function parameters cannot be constexpr since they can only be determined at runtime
    // unless you call constexpr function with constexpr parameters

    [[maybe_unused]] constexpr int max_v {max(x, y)};
    
    return 0;
}