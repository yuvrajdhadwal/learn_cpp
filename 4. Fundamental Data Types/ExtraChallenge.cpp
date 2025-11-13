#include <iostream>

double calc_height(double time, double start_height)
{
    return start_height - 9.8 * time * time / 2;
}

int main()
{
    double height{};
    std::cout << "Enter the height of the tower in meters: ";
    std::cin >> height;

    std::cout << "At 0 seconds, the ball is at height: " << calc_height(0, height) << " meters\n";
    std::cout << "At 1 seconds, the ball is at height: " << calc_height(1, height) << " meters\n";
    std::cout << "At 2 seconds, the ball is at height: " << calc_height(2, height) << " meters\n";
    std::cout << "At 3 seconds, the ball is at height: " << calc_height(3, height) << " meters\n";
    std::cout << "At 4 seconds, the ball is at height: " << calc_height(4, height) << " meters\n";
    std::cout << "At 5 seconds, the ball is on the ground.\n";
}
