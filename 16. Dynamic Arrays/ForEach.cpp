#include <iostream>
#include <string>
#include <ranges>  // for reverse
#include <vector>

int main()
{
    std::vector fib {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};  // ctad deduces type
    std::vector words {"Hello", "my", "name", "is", "Yuvraj"};

    // to avoid unnecessary type conversions, ensure type is same as type of array
    // num is copy of array element (can be expensive)
    for (int num : fib) { std::cout << num << '\n'; }

    // to easily avoid unnecessary type conversion, use auto keyword!
    for (auto num : fib) { std::cout << num << '\n'; }  // compiler deduces type!

    // avoid expensive copies with const references!
    for (const auto& word : words) { std::cout << word << ' '; }
    std::cout << '\n';

    // for best practices: always default to const auto&, if you need to edit a value
    // then use auto&, and if you want to edit a copy then use auto
    // this is because if you change code later, its very restrictive otherwise auto will just
    // update and this can cause massive performance issues or program breaking bugs!

    // you can reverse for each loops
    for (const auto& word : std::views::reverse(words)) { std::cout << word << ' '; }
    std::cout << '\n';

    return 0;
}