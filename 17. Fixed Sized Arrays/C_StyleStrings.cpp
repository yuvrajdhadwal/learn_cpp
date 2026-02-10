#include <cstring>  // for all basic c string functions
#include <iostream>

void print(const char s[])  // decayed c-styled string (const char*)
{
    std::cout << s << '\n';  // will keep printing characters till null terminator is hit
    // this can cause issues if you forget to add null terminator
}

int main()
{
    char str1[8] {};  // array of 8 chars, indices 0 through 7

    // let compiler deduce length, this way you don't forget null terminator needs allocation
    char str2[] {"string"};  // array of 7 char (note one char is null terminator)
    constexpr char str3[] {"hello"};  // array of 7 const chars

    const char col[] {"Red"};  // Red is stored somewhere in read-only memory, then red is copied
    // into this variable. thus two copies are made which is inefficient
    const char* const color {"Orange"};  // const ptr to cstyle string literal
    // creates orange in read only memory and then creates pointer to that. one copy

    auto s1 {"Yuvraj"};  // const char*
    auto* s2 {"Yuvraj"};  // const char*
    auto& s3 {"Yuvraj"};  // const char(&)[5]
    // prefer constexpr std::string_view in favor of c-style string constants as is safer and fast

    // due to c-style array decay, c-style strings will decay to const char* or char*
    // string literals like "hi" will decay into const char *

    print(str2);

    // like c-style arrays you cant reassign c-style strings
    // but you can change individual characters

    str2[1] = 'p';
    print(str2);

    std::cout << std::strlen(str2) << '\n';

    // generally avoid non-const strings in favor of std::string

    return 0;
}