#include <iostream>

void countDown(int count)
{
    // needs a base case
    std::cout << --count << '\n';
    countDown(count);  // tail call; compiler may optimize this into an iterative function
}

int main()
{
    // countDown(5);  // infinite recursion, stack overflow
    // all recursive functions can be written iteratively; however, it may be much harder

    /*
        Use Recursion if:
            - much easier to implement
            - recusive depth is limited
            - iterative version of algorithm requires managing a stack of data
            - not performance critical portion of code
        
        Generally favor iterative over recursive solutions
    */
    return 0;
}