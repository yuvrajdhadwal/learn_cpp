#include <array>
#include <functional>
#include <iostream>
#include <vector>

// fixed length array reference
void passByReference(const std::array<int, 5>& arr)  // explicitly need to define type and size
{
    std::cout << arr[0] << '\n';
}

// variable length and type array reference
template <typename T, std::size_t N>  // this matches std::array (NOTE: std::size_t)
auto passByReferenceTemplate(const std::array<T, N>& arr) -> std::array<T, N>  // returns by value
{
    static_assert(N != 0);  // fails if empty array

    std::cout << std::get<3>(arr) << '\n';  // compile time check of index 3, works since 
    // template types are compile time (can also use static assert like the check above)

    return arr;
}

template <std::size_t N>  // can also be `template <auto N>` for all if in C++20
void variableLengthArray(const std::array<int, N>& arr)  // variable array length
{
    static_assert(N != 0);
    std::cout << arr[0] << '\n';
}

template <typename T, auto N>
void outParameter(std::array<T, N> arr)  // notice no const
{
    arr[0] = 5;  // make changes to input array that is also technically the output array
    // generally if you are returning array by value its not constexpr and use vector instead
}

template <typename T, auto N>
constexpr void printArray(std::array<T, N> arr)
{
    std::cout << "The array: (";

    for (auto iter {arr.begin()}; iter != arr.end(); ++iter)
    {
        if (iter == arr.end() - 1)
        {
            std::cout << *iter;
        } else
        {
            std::cout << *iter << ", ";
        }
    }

    std::cout << ") has length " << N << '\n';
}

struct House
{
    int number{};
    int stories{};
    int roomPerStory{};
};

int main()
{
    // prefer std::array for constexpr and std::vector for runtime
    
    std::array<int, 5> a{};  // array of 5 ints
    std::vector<int> b(5);  // vector of 5 ints

    // lengths of arrays must be constexpr
    constexpr int len {10};
    std::array<int, len> c{};

    // arrays can be length zero
    std::array<int, 0> zero{};
    std::cout << zero.empty();  // will print 1 (true), would return 0 for any other case of array

    std::array<int, 6> fib = {0, 1, 1, 2, 3, 5};  // copy init using braced list
    std::array<int, 6> better_fib {0, 1, 1, 2, 3, 5};  // list init (preferred)

    std::array<int, 10> another_array {0, 1};  // first two elements init, the rest are value init

    const std::array<int, 3> c_arr {0, 1, 2};  // const array
    constexpr std::array<int, 3> ce_arr {0, 1, 2};  // constexpr array (preferred) (else use vector)

    constexpr std::array ctad {1.2, 4.6};  // using ctad to determine type <double, 2>

    std::cout << fib[0] << ' ' << fib[1] << '\n';  // indexing into std::array

    // std::array indexing/size is always std::size_t 

    std::cout << "Length: " << ctad.size() << '\n';  // returns length as std::size_t
    std::cout << "Length: " << std::size(ctad) << '\n';  // returns std::size_t
    std::cout << "Length: " << std::ssize(ctad) << '\n';  // returns signed std::size_t

    std::array arr {9, 7, 5, 3, 1};  // notice not constexpr
    constexpr int length {std::size(arr)};  // return value is constexpr size_t, which is converted
    // to int implicitly at compile time (constexpr)

    std::cout << "Length: " << length << '\n';

    std::cout << std::get<2>(arr) << ' ' << arr[2] << '\n';  // get does compile time bounds check

    constexpr std::array quizArr1 {1, 4, 9, 16};
    constexpr std::array quizArr2 {'h', 'e', 'l', 'l', 'o'};
    printArray(quizArr1);
    printArray(quizArr2);

    constexpr std::array houses {House {1,2,3}, House {2,3,4}, House {3,4,6}};  // ctad, <House, 3>
    constexpr std::array<House, 3> houses2 {{
            {1, 2, 3},
            {2, 3, 4},
            {3, 4, 5}
    }};

    // cant have array of references
    // this can be fixed with std::reference_wrapper<T>

    int x {0};
    int y {1};
    int z {2};
    std::array<std::reference_wrapper<int>, 3> ref_arr {x, y, z};  // converts to int& implicitly
    ref_arr[1].get() = 5;  // correct syntax to convert the referenced value

    std::cout << y << ' ' << ref_arr[1] << '\n';

    int xx {5};
    std::reference_wrapper ref1 {x};  // uses c++17 ctad else would have to add <int>
    auto ref2 {std::reference_wrapper{x}};  // uses ctad for ref_wrap

    auto ref {std::ref(x)};  // more concise syntax; deduces the kind of type instead of ctad
    auto cref {std::cref(x)};  // deduces to <const int>


    return 0;
}