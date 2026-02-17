#include <iostream>
#include <cstdarg>  // needed for ellipses

// note: one not ellipsis parameters is needed, ellipses must be last parameter
// note: no type checking of parameters
// note: no way of knowing how many parameters; solution: use count; but callers don't
// need to follow this syntax
// could use sentinel value, but this has a lot of the same issues, and now the first value is
// part of average instead of count

// biggest note: DONT USE ELLIPSIS LOL
double findAverage(int count, ...)  // ellipses
{
    int sum{};
    // can only access ellipses data through va_list
    std::va_list list;
    // initialize va_lists with va_start, first argument is list, second is last non ellipses arg
    va_start(list, count);

    for (int arg {0}; arg < count; ++arg)
    {
        // this is how to access arguments; first is list; second is type
        // note va_arg moves the parameter list one forward
        // note: since no type checking, if we passed in a double this would undefined behavior
        sum += va_arg(list, int);
    }

    va_end(list);  // this cleans up va_list we made

    return static_cast<double>(sum) / count;
}

int main()
{
    // variable parameter count
    std::cout << findAverage(5, 1, 2, 3, 4, 5) << '\n';
    std::cout << findAverage(6, 1, 2, 3, 4, 5, 6) << '\n';
}