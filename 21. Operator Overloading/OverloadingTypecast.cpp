#include <iostream>

const int centsInDollar {100};
class Dollars;

class Cents
{
    private:
    int m_cents{};

    public:
    Cents(int cents = 0) : m_cents {cents} {}
    // prefer converting constructor over typecast operator overload
    // generally better to make converting constructors rather than typecast operator overloading
    // needs to be forward declared until after it sees how dollars is made
    // explicit since converting constructor with only one parameter
    explicit Cents(Dollars dollars);

    // overloaded int cast
    // must be non-static member variable, should be const to use with const vars
    // no explicit parameters, will just use this pointer
    // overloaded typecasts do not declare return type. name of converstion is return type
    // prefer typecast overloading over converting constructors when converting to fundamental type
    // when conversion returns reference or const reference
    // when converting to types you can't add constructors to (such as std::vector)
    // when you don't want the type being constructed to be aware of type converted from
            // this last one is good for circular dependencies (see how i had to do the converting
            // constructor for dollars -> cents)
    operator int() const { return m_cents; }

    [[nodiscard]] auto getCents() const -> int { return m_cents; }
    void setCents(int newCents) { m_cents = newCents; }
};

class Dollars
{
    private:
    int m_dollars{};

    public:
    Dollars(int dollars) : m_dollars {dollars} {}
    // explicit ensures explicit invoked casting (eg. static_cast) or direct init (braces/paren)
    // no copy init
    // generally, typecasts should be made explicit, unless type being converted is synonymous with
    // the type being converted to
    explicit operator Cents() const { return Cents {m_dollars * centsInDollar}; }
    
    [[nodiscard]] auto getDollars() const -> int { return m_dollars; }
};

// implementing forward declared constructor
Cents::Cents(Dollars dollars) : m_cents {dollars.getDollars() * centsInDollar} {}

void printInt(int myInt)
{
    std::cout << myInt;
}

void printCents(Cents myCent)
{
    printInt(myCent);
}


auto main() -> int
{
    Cents cents {3};
    printInt(cents);  // will implicitly convert type Cents to int with overloaded cast
    std::cout << '\n';

    // you can evoke the overloaded typecast explicitly
    std::cout << static_cast<int>(cents) << '\n';

    Dollars dollar {4};
    // printCents(dollar);   // explicit makes this fail, cant make temp copy cents from dollars
    printCents(static_cast<Cents>(dollar));  // fixed!
    std::cout << '\n';

    return 0;

    /*
        General Best Practices:
            When Converting from Type A to Type B:
                IF B is class type you can modify, prefer converting constructor in B (A -> B)
                Else If A is class type you can modify, prefer overloaded typecast in A (A -> B)
                Else, use non-member function to convert A -> B
    */
}