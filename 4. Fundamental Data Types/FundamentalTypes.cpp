#include <iomanip> // for std::setw (which sets the width of the subsequent output)
#include <iostream>
#include <climits> // for CHAR_BIT
#include <cstdint> // for fast and least types


int main()
{
    // Minimum Size of Types
    // For maximum portability, you shouldn’t assume that objects 
    // are larger than the specified minimum size.

    bool x{ true };  // 1 Byte

    char y{ 'a' };  // 1 Byte

    short z{ 6555 };  // 2 Bytes  (-32,768 to 32,767)
    int a{ 6555 };  // 2 Bytes  (-2,147,483,648 to 2,147,483,647)
    long b{ 655555565 };  // 4 Bytes  (-2,147,483,648 to 2,147,483,647)
    long long c{ 3532453453453454325 };  // 8 Bytes
    // (-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807)

    float d{ 411.134f };  // 4 Bytes
    double e{ 123412341234.1234123412 };  // 8 Bytes
    long double f{ 2341234121234123234.123412341234 };  // 8 Bytes

    std::cout << x << y << z << a << b << c << d << e << f << '\n';

    // results may vary based on compiler, computer architecture, OS, compilation settings 

    std::cout << "A byte is " << CHAR_BIT << " bits\n\n";

    std::cout << std::left; // left justify output

    // sizeof does not include dynamic memory used by an object
    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";

    return 0;
}
