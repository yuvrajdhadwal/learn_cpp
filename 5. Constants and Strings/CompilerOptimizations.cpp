#include <iostream>

int five()
{
    return 5;
}

int pass(const int x) // x is a runtime constant
{
    return x;
}

int main()
{
    // we will be discussing compile time evaluations

    // constant folding
    int x { 3 + 4 };  // during compile time this is optimized down to 7
    // here is the compiled code
    // mov     DWORD PTR [rbp-4], 7
    // as you can see the 3 + 4 got optimized down to 7 

    std::cout << x << '\n';

    std::cout << 3 + 4 << '\n';
    /*
        Here is the compiled down code for the above line

        mov     esi, 7  <-- See Here: 3 + 4 is constant folded down to 7
        mov     edi, OFFSET FLAT:std::cout
        call    std::ostream::operator<<(int)
        mov     esi, 10
        mov     rdi, rax
        call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char)
    */


    // constant propogation

    // is an optimization technique where the compiler replaces variables known to have 
    // constant values with their values, saves fetch cycles from memory and store for the var

    const int y { 7 };
    std::cout << y << '\n';

    /*
        mov     DWORD PTR [rbp-8], 7  <-- this is storing 7 into y
        mov     esi, 7  <-- ignoring y value and just putting 7 here
        mov     edi, OFFSET FLAT:std::cout
        call    std::ostream::operator<<(int)
        mov     esi, 10
        mov     rdi, rax
        call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char)
    */

    const int z { 3 };
    std::cout << y + z << '\n';

    /*
        mov     DWORD PTR [rbp-12], 3  <-- this is storing 3 into z
        mov     esi, 10  <-- constant folding and propogation both!
        mov     edi, OFFSET FLAT:std::cout
        call    std::ostream::operator<<(int)
        mov     esi, 10
        mov     rdi, rax
        call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char)
    */

    // Dead Code Elimination

    [[maybe_unused]] int a {1};  // will eliminate this code
    std::cout << 1 << '\n';

    // if attempting to debug and it is not behaving according to how you expect
    // chances are there was some sort of compile time optimization that changed the behavior

    // The following are non-constants:
    [[maybe_unused]] int a { 5 };

    // The following are compile-time constants:
    [[maybe_unused]] const int b { 5 };
    [[maybe_unused]] const double c { 1.2 };
    [[maybe_unused]] const int d { b };       // b is a compile-time constant

    // The following are runtime constants:
    [[maybe_unused]] const int e { a };       // a is non-const
    [[maybe_unused]] const int f { e };       // e is a runtime constant
    [[maybe_unused]] const int g { five() };  // return value isn't known until runtime
    [[maybe_unused]] const int h { pass(5) }; // return value isn't known until runtime
    return 0;
}
