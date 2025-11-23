#include <iostream>

// no need to include wow! linker will automatically figure everything out for us
// in this context, extern means this is a forward decalartion for external variable defined
// somewhere else in the codebase
extern int g_a;  // extern is forward declaration of g_a which is defined somewhere
extern const int g_b;  // extern is forward declaration of g_b which is defined somewhere

int main()
{
    std::cout << g_a << ' ' << g_b << '\n';

    return 0;
}