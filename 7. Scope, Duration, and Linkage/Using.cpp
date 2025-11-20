#include <iostream>

namespace
{
    int out()  // unnamed namespace keeps functions in global namespace but makes them static
    {
        return 5;
    }

    int in()
    {
        return 4;
    }
}

inline namespace V1  // can call this example using V1:: or just regularly as if it wasn't in
// a namespace
{
    void example()
    {
        std::cout << "this is version one\n";
    }
}

namespace V2
{
    void example()
    {
        std::cout << "this is version 2\n";
    }
}

int main()
{
    std::cout << "using the qualified name for cout " << std::max(3, 4) << '\n';

    using std::cout;

    cout << "using the using declaration " << std::max(3, 4) << '\n';

    using namespace std;  // since these using statements are in a block, this is their scope

    cout << "using the using directive " << max(3, 4) << '\n';

    example();  // if example originally was called like this, using inline namespace we can
    // keep calling it like this and create a new namespace for a newer version
    V2::example();  // the new version

    return 0;
}