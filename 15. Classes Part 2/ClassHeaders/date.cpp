#include "date.hpp"

// note the definition file has the same name as the header

Date::Date(int year, int month, int day)  // constructor defined
    : m_year {year}
    , m_month {month}
    , m_day {day}
{}

void Date::print() const  // print defined
{
    std::cout << "Date(" << m_year << ", " << m_month << ", " << m_day << ")\n";
}