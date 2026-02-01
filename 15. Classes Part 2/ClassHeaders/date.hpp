#pragma once

#include <iostream>

class Date
{
    public:
    // keep default arguments in the declaration not in implementation
    Date(int year, int month, int day = 5);  // constructor declared

    void print() const;  // print declared 

    // trivial functions definied in declaration
    // member functions defined within class declaration are implicitly inline
    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }

    private:
    int m_year {};
    int m_month {};
    int m_day {};
};

// member function definitions can be placed within header file outside of declaration
// as long as you explicitly declare them as inline