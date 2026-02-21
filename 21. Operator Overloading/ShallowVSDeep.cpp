#include <cassert>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <cstring>

class Fraction
{
    private:
    int m_numerator {0};
    int m_denominator {1};

    public:
    Fraction(int numerator = 0, int denominator = 1) // NOLINT(bugprone-easily-swappable-parameters)
        : m_numerator {numerator}
        , m_denominator {denominator}
    {
        assert(denominator != 0);
    }

    // has default copy constructor and copy assignment (shallow, member wise copying)

    friend auto operator<< (std::ostream& out, const Fraction& frac) -> std::ostream&;
};

auto operator<< (std::ostream& out, const Fraction& frac) -> std::ostream&
{
    out << frac.m_numerator << '/' << frac.m_denominator << '\n';
    return out;
}

class MyString  // NOLINT
{
    private:
    char* m_data{};
    std::size_t m_length{};

    public:
    MyString(const char* source = "")
    {
        assert(source);  // make sure not null string

        // find length of source and + 1 for null terminator
        m_length = std::strlen(source) + 1;
        
        // allocate new data on heap
        m_data = new char[m_length];  // NOLINT(cppcoreguidelines-owning-memory)

        // deep copy
        for (std::size_t i {0}; i < m_length; ++i)
        {
            m_data[i] = source[i];  // NOLINT
        }
    }

    ~MyString()
    {
        delete[] m_data;  // need to deallocate our string
    }

    auto getString() -> char* { return m_data; }
    [[nodiscard]] auto getLength() const -> std::size_t { return m_length; }
    void deepCopy(const MyString& source);

    // deep copy constructor
    MyString(const MyString& str);
    // deep copy overload assignment operator
    auto operator= (const MyString& str) -> MyString&;
};

void MyString::deepCopy(const MyString& source)
{
    // first deallocate any values in our string
    delete[] m_data;

    // can shallow copy since its a value not pointer
    m_length = source.m_length;

    if (source.m_data != nullptr)  // make sure not null
    {
        // allocate new memory
        m_data = new char[m_length];  // NOLINT

        for (std::size_t i {0}; i < m_length; ++i) { m_data[i] = source.m_data[i]; } // NOLINT
    } else { m_data = nullptr; }
}

MyString::MyString(const MyString& str)
{
    deepCopy(str);
}

auto MyString::operator=(const MyString& str) -> MyString&
{
    // check for self assignment
    if (this != &str)
    {
        deepCopy(str);  // deep copy assignment
    }
    
    return *this;
}

auto main() -> int
{
    return 0;
}