#include <iostream>
#include <string>
#include <string_view>
#include <vector>

struct Foo
{
    // creates a member vector of initial size 8
    // uses copy constructor since direct initialization not allowed for member variables
    std::vector<int> v{std::vector<int>(8)};
};

class Foo2
{
    private:
    std::string m1 {};
    int m2 {};

    public:
    Foo2(std::string_view p1, int p2)
        : m1 {p1}, m2 {p2} {}
};

// need to pass vectors by reference or const reference since it is expensive copy
void func(const std::vector<int>& v) {}
// if you want to use vector with generic type you must use function templates
template <typename T>
void func(const std::vector<T>& v) {}
// vectors and their type can be passed into type T
template <typename T>
void funcTemp(const T& t) {}
// vectors and their type can be deduced by auto
void funcAuto(const auto& a) {}

// scalability with simple functions
// any type, any size
template <typename T>
T calcAvg(const std::vector<T>& v)
{
    std::size_t length {v.size()};

    T average {0};
    // Since all containers use container::size_type which is unsigned integral value
    // this can lead to issues with signed and unsigned conversions
    // some possible best practices
        // 1. use std::size_t for your type - this only works as long as theres no custom allocator
        // which there shouldnt be unless you make one
        // 2. std::vector::data to access underlying c-style array under vector
        // 3. Avoid indexing when traversing (use iterators and foreach loops)
    for (std::size_t index {0}; index < length; ++index)
    {
        average += v[index];
        // average += v.data()[index];  you can use signed integrals now :D
    }
    average /= static_cast<int>(length);
    return average;
}

template <typename T>
void printArrayStats(const std::vector<T>& v)
{
    // indices are only valid based off size not capacity
    std::cout << "Size: " << v.size() << " Capacity: " << v.capacity() << '\n';
    for (const auto& e : v) { std::cout << e << ' '; }
    std::cout << '\n';
}

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
    // finding size for vectors is runtime operation

    std::cout << "Size of Vowels: " << vowels.size() << '\n';  // returns size_type (std::size_t)
    std::cout << "Size of Vowels: " << std::size(vowels) << '\n';  // the same thing

    // casting size_type (std::size_t) into signed numbers
    int length {static_cast<int>(vowels.size())};
    std::cout << "Size of Vowels: " << length << '\n';  // now with type int!

    std::cout << "Size of Vowels: " << std::ssize(vowels) << '\n';  // returns signed equivalent
    int llength {static_cast<int>(std::ssize(vowels))};  // still need to cast due to narrowing
    auto lllength {std::ssize(vowels)};  // or use auto!

    func(primes);  // calls func(std::vector<int>)
    func(vowels);  // instantiates func(std::vector<char>) from func(std::vector<T>)
    funcTemp(primes);  // instantiates funcTemp(std::vector<int>) from funcTemp(T)
    funcAuto(primes);  // deduces type std::vector<int> from primes using auto

    std::vector testScores {84, 92, 54, 100, 98};
    std::vector testScores2 {84.3, 92.1, 54.14, 100.0, 98.8};
    std::cout << "The average class grade is: " << calcAvg(testScores)<< '\n';
    std::cout << "The average class grade is: " << calcAvg(testScores2)<< '\n';

    // resizing vectors at runtime
    printArrayStats(testScores);
    // resizing preserves elements and value initializes more elements until size is = 15
    testScores.resize(15);
    printArrayStats(testScores);
    // resizing smaller will slice off extra elements
    testScores.resize(2);
    printArrayStats(testScores);
    // shrinks valid capacity down to size
    testScores.shrink_to_fit();
    printArrayStats(testScores);
    // reserve changes capacity to match the value, without value initializing or changing length
    testScores.reserve(100);
    printArrayStats(testScores);

    std::vector<Foo2> pve {};

    // when we already have an object, push_back and emplace_back are similar efficiency
    Foo2 f {"Hello", 1};
    pve.push_back(f);  // prefer this
    pve.emplace_back(f);

    // when making temp obj, use emplace as its more efficient
    pve.push_back(Foo2 {"Bye", 2});  // Notice creating temp obj
    pve.emplace_back("Wow", 3);  // Notice just forwarding args to be created in place in vector

    // for the most part vector<bool> similar to all other vectors
    // however it is implementation specific, very variable in efficiency
    // it isnt even a vector by definition or a container
    std::vector<bool> boolV {true, false, false, true, true, true};
    // instead of std::vector<bool>, prefer constexpr std::bitset
    // if dynamic allocation necessary, use std::vector<char>, as this behaves as container

    return 0;
}