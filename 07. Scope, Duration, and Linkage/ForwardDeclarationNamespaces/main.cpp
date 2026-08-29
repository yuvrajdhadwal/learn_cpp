#include <iostream>

#include "add.hpp"
#include "circle.hpp"
#include "growth.hpp"

int main() {
    // since we defined namespace, we need to identify add with it
    std::cout << BasicMath::add(4, 3) << '\n';

    // we can have namespace defined across multiple files
    // and have constants defined under namespaces as well
    std::cout << BasicMath::pi << ' ' << BasicMath::e << '\n';

    return 0;
}
