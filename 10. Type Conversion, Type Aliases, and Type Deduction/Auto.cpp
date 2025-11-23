#include <iostream>

// dont use auto for function parameters as this calls function templates
auto add(int x, int y)  // example of return type deduction, generally avoid due to forward
// declaration issues, described in the other function.
{
    return x + y;  // compiler knows this is int + int, so it knows to return int
    // type deduction return ensures that all return values are the same type (no conversions)
}

void test(){}

auto forward_declaration_of_auto_not_allowed();

// more readable since return type is at the back of the declaration
// used for lambdas, fixes the problem of forward declaration issues
auto check_out_trailing_return_type() -> int
{
    return 5;
}

// working forward declaration with trailing return type
auto forward_declaration_works_now_wooooo() -> void;

int main()
{
    auto d {5.0};  // double literal so the type of d is now double
    auto i {6 + 7};  // evaluates to int, so type of i is int
    auto x {i};  // type of i is int so type of x will be int

    auto y {add(x, i)};

    auto f {5.0f};
    const auto ca {5.0};
    constexpr auto cea {5.0};

    // this will not save const or constexpr, need to add that type identifier here too if wanted
    auto non_const {cea};

    // type deduces c-style array not std::string
    auto sl {"This is a string literal that is C-Style"};

    std::cout << d << i << x << y << f << ca << cea << non_const << sl << '\n';

    // the following code does not work since auto cannot deduce type
    // auto a;
    // auto b{};
    // auto c {foo()};

    /*
        Use type deduction for your variables when the type of the object doesn’t matter.

        Favor an explicit type when you require a specific type that differs from the type
        of the initializer, or when your object is used in a context where making the type
        obvious is useful.
    */

    // forward_declaration_of_auto_not_allowed();
    // not allowed since return type not deduced at this time yet
    // error: use of 'auto forward_declaration_of_auto_not_allowed()' before deduction of 'auto'
    std::cout << check_out_trailing_return_type() << '\n';
    forward_declaration_works_now_wooooo();

    return 0;
}

auto forward_declaration_of_auto_not_allowed()
{
    std::cout << "this will never work lol";
    return 5;  // int so returns int
}

auto forward_declaration_works_now_wooooo() -> void
{
    std::cout << "if this prints it works\n";
}