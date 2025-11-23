#include <iostream>
#include <random>

int main()
{
    // utilizing os to create random seed for our twister random
    // os specific call
    std::random_device rd{};
    // seed sequence generates the necessary 624 integers for initial seed
    std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};  // gets 8 random integers
    std::mt19937 mt{ ss };  // initializes the random number generator

    // uses random to get uniform distribution over domain
    std::uniform_int_distribution die6{1, 6};

    for (int i {1}; i <= 40; ++i)
    {
        // mt() calls operator( on the variable
        std::cout << mt() << '\t';

        if (i % 5 == 0)
        {
            std::cout << '\n';
        }
    }

    for (int i {1}; i <= 40; ++i)
    {
        // calls operator( on die6 variable and passes in the twister
        std::cout << die6(mt) << '\t';

        if (i % 10 == 0)
        {
            std::cout << '\n';
        }
    }

    return 0;
}