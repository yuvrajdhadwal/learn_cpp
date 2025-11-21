#include <iostream>

namespace Constants
{
    inline constexpr double gravity {9.8};
}

int main()
{
    // float equality fine here because these are two literals
    // if variables in if statement conditional are constexpr, compiler may treat if like
    // if constexpr as an optimization even if programmer didn't specify
    if constexpr (Constants::gravity == 9.8)  // this will always evaluate true/false at compile
    // thus if we use "if constexpr" to get compile time optimization
    {
        std::cout << "Gravity is normal\n";
    } else
    {
        std::cout << "Gravity is not normal!\n";
    }
}

/*

    with constexpr this whole file is compiled into the following assembly thanks to optimizations
    11 lines vs 30 lines of code thanks to two keywords
    
    .LC0:
        .string "Gravity is normal\n"
    main:
        push    rbp
        mov     rbp, rsp
        mov     esi, OFFSET FLAT:.LC0
        mov     edi, OFFSET FLAT:std::cout
        call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)
        mov     eax, 0
        pop     rbp
        ret
    
    without optimizations

    Constants::gravity:
        .long   -1717986918
        .long   1076074905
    .LC1:
            .string "Gravity is normal\n"
    .LC2:
            .string "Gravity is not normal!\n"
    main:
            push    rbp
            mov     rbp, rsp
            movsd   xmm0, QWORD PTR Constants::gravity[rip]
            ucomisd xmm0, QWORD PTR .LC0[rip]
            jp      .L2
            ucomisd xmm0, QWORD PTR .LC0[rip]
            jne     .L2
            mov     esi, OFFSET FLAT:.LC1
            mov     edi, OFFSET FLAT:std::cout
            call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)
            jmp     .L4
    .L2:
            mov     esi, OFFSET FLAT:.LC2
            mov     edi, OFFSET FLAT:std::cout
            call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)
    .L4:
            mov     eax, 0
            pop     rbp
            ret
    .LC0:
            .long   -1717986918
            .long   1076074905

*/