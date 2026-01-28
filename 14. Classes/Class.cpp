#include <iostream>
#include <string>

class Date
{    
    // declare public members first, then protected, then private
    public:  // class members are private by default, any private member removes access to aggregate
    void printDate()
    {
        std::cout << m_month << '/' << m_day << '/' << m_year << '\n';
    }

    // prefer implementing functions as non-member functions if you can
    // this includes functions that do not affect the state of object (like this one!)
    void printTwoDates(const Date& o)
    {   // access level specifiers are per-class not per-object
        // this is how this class (within Date) is able to access private members within
        // another object which is of the same class (Date)
        std::cout << m_month << '/' << m_day << '/' << m_year << ' '
            <<  o.m_month << '/' << o.m_day << '/' << o.m_year << '\n';
    }

    int getYear() const { return m_year; }  // getters should be const to allow const objs to access
    void setYear(int year) { m_year = year; }  // setters cannot be const

    int getMonth() const { return m_month; }  // getters should only return "read-only" values
    void setMonth(int month) { m_month = month; }

    int getDay() const { return m_day; }
    void setDay(int day) { m_day = day; }

    // if returning by reference, return by reference of same type to avoid unecessary conversions
    // auto would ensure no conversions, however it would make it hard to deduce types
    // rvalue references will be dangling as rvalues are deleted after expression
    const std::string& getName() const { return m_holidayName; }
    void setName(std::string_view name) { m_holidayName = name; }

    private:  // its still good to be explicit about public/private/protected
    int m_day {};  // generally should have only private/protected data members
    int m_month {};
    int m_year {};  // common convention to prefix private member variables with m_
    std::string m_holidayName {};
};

int main()
{
    Date date {};
    date.printDate();

    std::string_view sv {"Hello"};

    // prefer static cast when performing narrowing conversion
    // make it really obvious that we are converting the type
    // want to avoid list initialization (such as for vector)
    static_cast<std::string>(sv);  // returns temp object std::string which is direct initialized
    // prefer this when do not want to perform narrowing conversion
    // need to provide additional arguments to constructor to cast
    std::string {sv};  // explicitly creates std::string with list initialization

    return 0;
}