#include "foo.hpp"
#include "pair.hpp"

#include <iostream>

int main()
{
    Pair<double> p2 {3.4, 5.6};
    std::cout << max(p2) << " is larger\n";

    foo();

    return 0;
}