/**
 * L-Value References Recap:
 *      Can only be initialized with modifiable L-Values
 *      Can also modify the modifiable L-Values
 *
 *      LValue References to Const can be initialized with LValues, LValue const, and RValues but
 * cannot modify anything
 *
 * R-Value References:
 *      Can be initialized with R-Values, and can modify those R-Values
 *      R-Value References to Const can be initialized with R-Values but cannot modify them
 */

int x{5};       // regular variable
int& lref{x};   // L-Value reference
int&& rref{5};  // R-value reference
                //

#include <iostream>

class Fraction {
   private:
    int m_numerator{0};
    int m_denominator{1};

   public:
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{numerator}, m_denominator{denominator} {}

    friend auto operator<<(std::ostream& out, const Fraction& oFrac) -> std::ostream& {
        out << oFrac.m_numerator << '/' << oFrac.m_denominator;
        return out;
    }
};

void myFunc(const int& lref)  // l-val args will select this function
{
    std::cout << "lval ref to const: " << lref << '\n';
}

void myFunc(int&& rref)  // r-val args will select this function
{
    std::cout << "rval ref: " << rref << '\n';
}

auto main() -> int {
    auto&& rref{Fraction{3, 5}};  // rvalue reference to temporary fraction
                                  // since, we are making rval ref, temp object not destoryed
    std::cout << rref << '\n';    // operator<< binds to temp ref, no copies made
                                  //
    int&& intrref{5};             // because we are init rref, temp with val 5 is created here
    intrref = 10;
    std::cout << intrref << '\n';

    int x{5};
    myFunc(x);  // lval
    myFunc(5);  // rval
    int&& ref {5};
    fun(ref);  // chooses lval, lval of type int&&
               // dont return rval refs since theyll lead to hanging refs most likely
    return 0;
}
