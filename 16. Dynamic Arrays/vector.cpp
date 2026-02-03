#include <iostream>
#include <vector>

struct Foo
{
    // creates a member vector of initial size 8
    // uses copy constructor since direct initialization not allowed for member variables
    std::vector<int> v{std::vector<int>(8)};
};

int main()
{
    // value initialization; uses default constructor
    std::vector<int> empty{};  // vector containing 0 int elements

    // list initialization with vector
    std::vector<int> primes {2, 3, 5, 7, 11};
    std::vector vowels {'a', 'e', 'i', 'o', 'u'};  // CTAD deduces the type here (preferred)

    // operator[] does no bounds checking
    std::cout << "First Prime: " << primes[0] << '\n';  // random access for vector
    std::cout << "Third Vowel: " << vowels[2] << '\n';
    // .at() does runtime bounds checking (more inefficient than operator[])
    // throws exception if out of bounds (std::out_of_range)
    std::cout << "Fourth Prime: " << primes.at(3) << '\n';

    // indexing and casting
    std::cout << primes[3] << '\n';  // int converted to std::size_t; not narrowing
    // constexpr index implicitly converted to std::size_t; not narrowing
    constexpr int i {3};
    std::cout << primes[i] << '\n';

    std::size_t i2 {3};
    std::cout << primes[i2] << '\n';  // std::size_t already; no conversion

    // int to std::size_t; possible warning for narrowing conversion
    // even though size_t larger than int since size_t doesn't contain negatives this is considered
    // narrowing converions. opposite conversion is also considered narrowing
    int i3 {3};
    std::cout << primes[i3] << '\n';  
    // no warning; c-style arrays are fine with signed index; no overhead to call .data()
    std::cout << primes.data()[i3] << '\n';  


    // must use direct initialization here; list initialization will default if {}
    std::vector<int> data(10);  // vector containing 10 elements; value initialized to 0

    const std::vector<int> c_v(5);  // vector cannot be modified; nor the elements within
    // std::vector cannot be made constexpr during runtime

    // size_type is nested typedef in containers used as type for length and indices
    // size_type usually defaults to std::size_t

    std::cout << "Size of Vowels: " << vowels.size() << '\n';  // returns size_type (std::size_t)
    std::cout << "Size of Vowels: " << std::size(vowels) << '\n';  // the same thing

    // casting size_type (std::size_t) into signed numbers
    int length {static_cast<int>(vowels.size())};
    std::cout << "Size of Vowels: " << length << '\n';  // now with type int!

    std::cout << "Size of Vowels: " << std::ssize(vowels) << '\n';  // returns signed equivalent
    int llength {static_cast<int>(std::ssize(vowels))};  // still need to cast due to narrowing
    auto lllength {std::ssize(vowels)};  // or use auto!

    return 0;
}