#include <array>  // contains iterator specific for arrays
#include <iostream>
#include <vector>  // contains iterator specifics for vectors

int main()
{
    // iterators: objects designed to traverse containers; with similar interfaces for all types

    std::array array {1, 2, 3};  // ctad

    auto begin {array.begin()};  // first element in the container
    // auto begin {std::begin(array)}   another way of doing it
    auto end {array.end()};  // one past the last element in the container
    // auto end {std::end(array)}  another way to do it

    // relational operators may not work for all iterators; thus we use !=  
    for (auto p {begin}; p != end; ++p)  // ++ moves the element
    {
        std::cout << *p << ' ';  // indirect to get value of iterator
    }
    std::cout << '\n';

    // Dangling Iterators
    // iterators can be left dangling if elements being iterated over change address or are
    // destroyed, this invalidates the iterator
    // accessing dangling iterators is undefined behavior don't do it

    // an example
    std::vector v {0, 1, 2, 3, 4};
    for (auto num : v)  // range based for loops use iterators under the hood
    {
        if (num % 2 == 0) { v.push_back(num + 1); }  // this will invalidate iterator; undefined
    }

    // v becomes {0 1 2 3 4 1 1351464229 353582785 5}
    for (auto e : v)
        std::cout << e << ' ';
    std::cout << '\n';

    // another example
    std::vector v2 {1, 2, 3, 4, 5, 6, 7};
    auto it {v.begin()};

    ++it;  // moves to second element
    std::cout << *it << '\n';
    // v2.erase(it);  // erases current element
    // this invalidates it, and subsequent values
    it = v2.erase(it);  // erases current element and returns iterator of next element (or end)

    ++it;  // undefined behavior
    std::cout << *it << '\n';

    return 0;
}