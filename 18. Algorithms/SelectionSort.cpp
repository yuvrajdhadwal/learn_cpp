#include <algorithm>  // for std::sort
#include <iostream>
#include <iterator>  // for std::size
#include <utility>  // for std::swap

int main()
{
    int array[] {10, 20, 30, 50, 40};
    constexpr int length {static_cast<int>(std::size(array))};

    for (int startIndex {0}; startIndex < length - 1; ++startIndex)
    {
        int smallestIndex {startIndex};

        for (int currentIndex {startIndex + 1}; currentIndex < length; ++currentIndex)
        {
            if (array[currentIndex] < array[smallestIndex])
            {
                smallestIndex = currentIndex;
            }
        }

        std::swap(array[startIndex], array[smallestIndex]);
    }

    for (int index {0}; index < length; ++index)
    {
        std::cout << array[index] << ' '; 
    }

    std::sort(std::begin(array), std::end(array));
    std::cout << '\n';

    
    for (int e : array)
        std::cout << e << ' ';
    std::cout << '\n';

    return 0;
}