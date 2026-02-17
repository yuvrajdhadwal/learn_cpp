#include <iostream>
#include <array>
#include <algorithm>
#include <string_view>
#include <functional>  // also has many common lambdas like greater

/*

Lambdas are anonymous functions (they have no function name)

[capture clause] (parameters) -> return type
{
    statements;
}

every part of this is optional depending on the lambda
return type of lambda must always be the same return type or else lambda can't deduce type

*/

int main()
{
    [] {};  // lambda with ommitted return type (auto), no captures, and omitted parameters

    constexpr std::array<std::string_view, 4> arr {"appl", "banana", "walnut", "leon"};

    // lambda is great here since this function will never be used ever again
    auto found { std::find_if(arr.begin(), arr.end(),
                            [](std::string_view str)  // no capture clause lambda
                            {
                                return str.find("nut") != std::string_view::npos;
                            }) };

    if (found == arr.end()) { std::cout << "No nuts!\n"; }
    else { std::cout << "Found: " << *found << '\n'; }

    // we can also define labels for our lamda functions, this allows for multi-use
    // while also not polluting larger namespaces for functions only used in one block
    // this also makes lambdas more readable

    // best practice (preferred way to get type)
    // compiler generates unique type for lambda (class lambda [](std::string_view s)->bool)
    auto isEven  // best to keep lambdas multi-line so theyre easy to read
    {
        [](std::string_view s) -> bool  // return type can be omitted and compiler will deduce it
        {
            return (s.size() % 2) == 0;
        }
    };

    bool (*isEven2)(std::string_view)  // function pointers, no capture clause allowed
    {
        [](std::string_view s)
        {
            return (s.size() % 2) == 0;
        }
    };

    std::function isEven3  // using std::function, little overhead to convert from auto to this
    // accesses the heap
    {
        [](std::string_view s)
        {
            return (s.size() % 2) == 0;
        }
    };

    std::cout << isEven("hello") << '\n';  // calling lambda
    std::cout << std::all_of(arr.begin(), arr.end(), isEven) << '\n';  // using lambda var

    // generic lambdas, auto parameters allow for generic types in parameters c++14
    const auto sameLetter { std::adjacent_find(arr.begin(), arr.end(), 
                                [](const auto& a, const auto& b)  // notice the auto here
                                // could pass in anything really
                                {
                                    return a[0] == b[0];
                                })};

    // constexpr lambdas c++17
    // must have no captures, or all captures are constexpr
    // count_if made constexpr in c++20

    constexpr auto fiveLetter { std::count_if(arr.begin(), arr.end(),
                                [](auto& str)
                                {
                                    return str.size() == 5;
                                })};

    // generic lambdas and static variables
    // function templates that have static variables will create different ones for different types
    // this is because compiler makes multiple copies of each function for each type used

    auto print
    {
        [](auto p)  // two different prints for int, and char*
        {
            static int sint {0};
            std::cout << sint++ << ' ' << p << '\n';
        }
    };

    print(1);
    print(2);
    print("hello");
    print("wow");

    

    return 0;
}

// passing in lambdas into functions

// using std::function; requires overhead to turn lambda to std::function
// if not c++20, use this method
void repeat1(int n, const std::function<void(int)>& fn)
{
    for (int i {0}; i < n; ++i) { fn(i); }
}

// using function template with type template parameter
template <typename T>
void repeat2(int n, const T& fn)
{
    for (int i {0}; i < n; ++i) { fn(i); }
}

// using abbreviated function template syntax c++20
// if c++20, use this method (preferred)
void repeat3(int n, const auto& fn)
{
    for (int i {0}; i < n; ++i) { fn(i); }
}

// using function pointer (only works for lambdas with no capture)
void repeat4(int n, void(*fn)(int))
{
    for (int i {0}; i < n; ++i) { fn(i); }
}