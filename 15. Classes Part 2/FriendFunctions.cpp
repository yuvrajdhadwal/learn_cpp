#include <iostream>

class Subtractor;  // forward declare subtractor for friend function in Accumulator

class Accumulator
{
    private:
    int m_value {0};

    public:
    void add(int value) {m_value += value;}

    // friend declaration for non-member function
    friend void print(const Accumulator& acc);

    // we can also define non-member friend functions within class
    friend void printBetter(const Accumulator& acc)
    {
        std::cout << "Better: " << acc.m_value << '\n';
    }

    // another example of friend
    friend bool isEqual(const Accumulator& acc, const Accumulator& o);
    // example of friend of multiple classes
    friend void printValues(const Accumulator& acc, const Subtractor& sub);
};

class Subtractor
{
    private:
    int m_value {0};

    public:
    Subtractor(int value)
        : m_value {value}
    {}

    void sub(int value) {m_value -= value;}

    friend void printValues(const Accumulator& acc, const Subtractor& sub);
};

void print(const Accumulator& acc)
{
    // since it is friend of Accumulator class; can access private member variables
    std::cout << acc.m_value << '\n';
}

// this way we can have a general function instead of member function
// static cannot access non-static members, so we use friend
// friends should use public interfaces whenever possible for good coding practice (not shown here)
bool isEqual(const Accumulator& acc, const Accumulator& o)
{
    // can access private member variables
    return acc.m_value == o.m_value;
}

void printValues(const Accumulator& acc, const Subtractor& sub)
{
    // can access private member variables of all classes it is friends with
    std::cout << "Acc: " << acc.m_value << " Sub: " << sub.m_value << '\n';
}

int main()
{
    Accumulator acc {};
    acc.add(5);

    print(acc);  // non-member function
    printBetter(acc);  // another non-member function; even if defined in class thanks to friend

    Accumulator acc2 {};
    acc2.add(5);

    std::cout << isEqual(acc, acc2) << '\n';

    printValues(acc, Subtractor{10});

    return 0;
}