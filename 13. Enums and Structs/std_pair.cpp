#include <iostream>
#include <utility>  // for std::pair

template <typename T, typename U>
void print(std::pair<T, U> p)
{
    std::cout << '[' << p.first << ", " << p.second << "]\n";
}

int main()
{
    std::pair<int, int> p1 {1, 2};
    print(p1);
    
    return 0;
}