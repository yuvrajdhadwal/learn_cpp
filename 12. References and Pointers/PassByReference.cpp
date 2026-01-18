#include <iostream>
#include <string>

// Since this is Non-Const L-Value Reference, R-Values and Const L-Value References cannot be
// passed into this function as arguments
void printNonConstValue(std::string& val)  // Reference is used; no expensive copy
{
    std::cout << val << '\n';  // editing val would also edit s since it is a reference
}

// Pass by reference (no expensive copy) and inclusive to almost every type
// Favor const pass by reference unless it is necessary to change the value
void printAnyValue(const std::string& val)  // cannot change val if we want to
// prefer std::string_view in most cases, const std::string& used here for demonstration purposes
// this is because std::string_view to const std::string& is expensive conversion
// whereas std::string_view is easy conversion to turn into
{
    std::cout << val << '\n';
}


int main()
{
    // General Rule of Thumb:
    // Pass by Value if Fundamental Type (Cheap), Pass by Const Reference if Class Type (Expensive)
    // If Unsure, Pass by Const Reference

    // For cheap to copy objects, cost of copying is similar to binding, but accessing the
    // objects is faster and compiler can make optimizations
    // For expensive to copy objects, pass by reference is better since cost of copy dominates
    // References require RAM access twice, whereas Values require one access of RAM
      // This is because first you need to access where value is stored then access value (indirect)
    std::string s {"Test"};

    printNonConstValue(s);

    const std::string const_s {"Woooo!"};

    printAnyValue(s);  // l-value
    printAnyValue("Hello!");  // const l-value
    printAnyValue(std::string {"Wow!"});  // r-value, temporary copy made and val binds to that
    // this makes this as expensive as pass by value :(
    printAnyValue(const_s);  // const l-value

    return 0;
}