#include <iostream>
#include <random>

void playGame(int num)
{
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100."
    " You have 7 tries to guess what it is.\n";

    for (int i {0}; i < 7; ++i)
    {
        int guess{};
        std::cout << "Guess #" << i + 1 << ": ";
        std::cin >> guess;

        if (guess < num)
        {
            std::cout << "Your guess is too low.\n";
        } else if (guess > num)
        {
            std::cout << "Your guess is too high\n";
        } else {
            std::cout << "Correct! You Win!\n";
            break;
        }
    }
}

int main()
{
    std::random_device rd{};
    std::seed_seq ss {rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937 mt {ss};

    std::uniform_int_distribution random_range {1, 100};

    char res{};
    do {
        playGame(random_range(mt));

        while (true)
        {
            std::cout << "Would you like to play again (y/n)? ";
            std::cin >> res;

            if (res == 'n' || res == 'y')
            {
                break;
            }
        }
    } while (res == 'y');
    
    std::cout << "Thank you for playing.";

    return 0;
}