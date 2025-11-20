#include <iostream>

// internal linkage means the variables stay within this file
// important to ensure your identifier isn't accessible, and being pedantic about naming collisions
// limits usage to within the same file

static int g_x{};  // non const globals have external linkage, you can turn this to internal
// linkage with the static keyword, zero initialized by default since it's static

const int g_y {1};  // const globals have internal linkage by default
constexpr int g_z {2};  // constexpr globals have internal linkage by default

// internal linkage for function, they have external linkage by default
[[maybe_unused]] static int add(int x, int y)
{
    return x + y;
}

int main()
{
    std::cout << g_x << ' ' << g_y << ' ' << g_z << '\n';
}