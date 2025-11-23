#include <iostream>
#include <cstdint>

int main()
{
    // unsigned numbers can underflow easily
    // any operation with unsigned numbers will result in an unsigned number
    unsigned short us { 255 };
    unsigned int ui { 65'535 };
    unsigned long ul { 4'294'967'295 };
    unsigned long long ull { 8'446'744'073'709'551'614 };

    std::cout << us << ui << ul << ull << '\n';

    // the following code only works since we disabled treat warnings as errors
    unsigned short g{ 65535 }; // largest 16-bit unsigned value possible
    std::cout << "x was: " << g << '\n';

    g = 65536; // 65536 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << g << '\n';

    g = 65537; // 65537 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << g << '\n';

    unsigned short v{ 0 }; // smallest 2-byte unsigned value possible
    std::cout << "x was: " << v << '\n';

    v = -1; // -1 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << v << '\n';

    v = -2; // -2 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << v << '\n';

    // least will give you the smallest int that fits requirements
    // fast will give you fastest int that fits requirements
    // different results on different machines - avoid

    // sizeof returns type std::size_t

    std::cout << "least 8:  " << sizeof(std::int_least8_t)  * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
	std::cout << '\n';
	std::cout << "fast 8:  "  << sizeof(std::int_fast8_t)   * 8 << " bits\n";
	std::cout << "fast 16: "  << sizeof(std::int_fast16_t)  * 8 << " bits\n";
	std::cout << "fast 32: "  << sizeof(std::int_fast32_t)  * 8 << " bits\n";

    std::int_fast16_t h{ 1 };
    std::cout << h << '\n';

    /*
    Best practice

    Prefer int when the size of the integer doesn’t matter (e.g. the number will always fit within
    the range of a 2-byte signed integer). For example, if you’re asking the user to enter their
    age, or counting from 1 to 10, it doesn’t matter whether int is 16-bits or 32-bits
    (the numbers will fit either way). This will cover the vast majority of the cases you’re
    likely to run across.
    
    Prefer std::int#_t when storing a quantity that needs a guaranteed range.
    Prefer std::uint#_t when doing bit manipulation or well-defined wrap-around behavior
    is required (e.g. for cryptography or random number generation).
    
    
    Avoid the following when possible:

    short and long integers (prefer a fixed-width integer type instead).
    The fast and least integral types (prefer a fixed-width integer type instead).
    Unsigned types for holding quantities (prefer a signed integer type instead).
    The 8-bit fixed-width integer types (prefer a 16-bit fixed-width integer type instead).
    Any compiler-specific fixed-width integers (for example, Visual Studio defines
    __int8, __int16, etc…)

    */
}
