#include <iostream>

int example(int x, int y)  // global namespace
{
    return x * y;
}

namespace NamespaceIdentifier  // syntax for user-defined namespace
{
    int example(int x, int y)
    {
        return x + y;
    }
}

namespace AnotherNamespace
{
    // unnecessary but shows that you can have inner namespaces
    namespace AnInnerNamespace
    {
        int example(int x, int y)
        {
            // an example of calling the global namespace example rather than recursive call
            return x - y - ::example(x, y);
        }
    }
}

int main()
{
    // thanks to namespaces there is no ambiguity 
    std::cout << NamespaceIdentifier::example(3, 4) << ' '
        << AnotherNamespace::AnInnerNamespace::example(3, 4) << ' '
        << ::example(3, 4) << '\n';  // using the global namespace with just ::
        // this is kinda useless since without :: it will still grab the same example

    // sometimes namespaces get long and you want to alias them
    namespace curr = AnotherNamespace::AnInnerNamespace;

    std::cout << curr::example(3, 4) << " is way easier to read and understand than "
        << AnotherNamespace::AnInnerNamespace::example(3, 4) << " given that we have a better "
        "alias name than curr lol";
    
    return 0;
}