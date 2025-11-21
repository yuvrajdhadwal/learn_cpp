#include <iostream>

void doNothing()
{
    ;  // null statement
}

int main()
{
    doNothing();

    if (false);
    {
        std::cout << "this will still print due to the above null statement";
    }

    return 0;
}