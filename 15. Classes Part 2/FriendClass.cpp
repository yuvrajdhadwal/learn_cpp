#include <iostream>

class Storage
{
    private:
    int m_nValue {};
    double m_dValue {};

    public:
    Storage(int nValue, double dValue)
        : m_nValue {nValue}
        , m_dValue {dValue}
    {}

    friend class Display;  // display is friend of storage; so it has access to all private members
    // also acts as forward declaration
};

class Display
{
    private:
    bool m_displayIntFirst {};

    public:
    Display(bool displayIntFirst)
        : m_displayIntFirst {displayIntFirst}
    {}

    void displayStorage(const Storage& storage)
    {
        if (m_displayIntFirst)
        {
            // stince class is friend of storage; it can access storage private members
            std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
        } else
        {
            std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
        }
    }

    void setDisplayIntFirst(bool b)
    {
        m_displayIntFirst = b;
    }

    // since this is commented; storage cannot access private members of Display
    // friendship is not recipricated by default nor is it transative nor inheritive
    // friend class Storage;
};

class Banana;  // forward declared
class Apple
{
    public:
    void displayComp(const Banana& b);  // forward declared
};

class Banana
{
    private:
    bool ripe {true};

    public:
    // friend for member function
    friend void Apple::displayComp(const Banana& b);
};

// friendly member function defined
void Apple::displayComp(const Banana& b)
{
    std::cout << "Apple is not ripe. Banana is: " << b.ripe << '\n';
}

int main()
{
    Storage storage {5, 6.7};
    Display display {false};

    display.displayStorage(storage);

    display.setDisplayIntFirst(true);
    display.displayStorage(storage);

    return 0;
}