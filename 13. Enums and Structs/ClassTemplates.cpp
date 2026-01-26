#include <iostream>

template <typename T=int>  // default type T to int
struct Pair
{
    T first{};  // templated member
    T second{};
    bool my_bool {};  // not templated member
};

template <typename T, typename U>
struct MyPair
{
    T first{0};  // keeping explicit defaults
    U second{0};  // two different templated types for members 
};

template <typename T>
constexpr T max(Pair<T> p)  // not pass by reference/pointer since supposed to be lightweight
{
    return (p.first < p.second ? p.second : p.first);
}

template <typename T, typename U>
constexpr void print(MyPair<T, U> p)
{
    std::cout << p.first << ' ' << p.second << '\n';
}

template <typename T>
constexpr void printGeneric(T p)  // templated type for objs
{
    std::cout << p.first << ' ' << p.second << '\n';  // will only compile if called on objs with
    // first and second as members
}

int main()
{
    Pair<int> p1 {5, 6};  // instantiates pair<int> and creates obj
    std::cout << p1.first << ' ' << p1.second << '\n';

    Pair<double> p2 {1.2, 3.4};  // instantiates pair<double> and creates obj
    std::cout << p2.first << ' ' << p2.second << '\n';

    Pair<double> p3 {7.8, 9.0};  // creates obj
    std::cout << p3.first << ' ' << p3.second << '\n';

    // uses template argument deduction (preferred)
    std::cout << max(p1) << ' ' << max(p3) << '\n';

    MyPair<int, int> p4 {1, 2};  // has two types, they're the same
    MyPair test1 {4, 5};  // 4, 5, uses CTAD

    MyPair<int, double> test2 {};  // 0, 0

    print(p4);
    print(test1);
    print(test2);

    printGeneric(p1);  // printGeneric(Pair<int>)
    printGeneric(p4);  // printGeneric(MyPair<int, int>)

    return 0;
}