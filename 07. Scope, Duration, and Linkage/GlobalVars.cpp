#include <iostream>

// global var example (in the global namespace)
// global variables are considered static variables
// global variables are zero initialized since they are considered static
int g_my_global_var{};

// global variables can be defined in other namespaces too
namespace MyGlobalVarNamspace
{
    // it is best to define global variables in a namespace rather than global namespace
    // it is also best to use prefix "g_" that way it is clear that this is global var
    // best practice to keep all global variables const
    int g_my_global_var{};
}

void example()
{
    // global variables can be seen and edited from anywhere
    g_my_global_var = 6;
    std::cout << "My Global Var Value is now: " << g_my_global_var << '\n';

    MyGlobalVarNamspace::g_my_global_var = 12;
    std::cout << "My (namespaced) Global Var Value is now: "
        << MyGlobalVarNamspace::g_my_global_var << '\n';
}

int main()
{
    example();
    std::cout << "My Global Var Value is still: " << g_my_global_var << " since it is a global"
    " variable and not local to that function.\n";

    example();
    std::cout << "My (namespaced) Global Var Value is still: "
    << MyGlobalVarNamspace::g_my_global_var << " since it is a global"
    " variable and not local to that function.\n";

    g_my_global_var = 7;
    std::cout << "My Global Var Value is now: " << g_my_global_var << " because we just changed it"
    " in this function!\n";

    MyGlobalVarNamspace::g_my_global_var = 14;
    std::cout << "My (namespaced) Global Var Value is now: "
    << MyGlobalVarNamspace::g_my_global_var << " because we just changed it"
    " in this function!\n";

    return 0;
}