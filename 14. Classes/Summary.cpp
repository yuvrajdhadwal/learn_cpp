#include <cmath>
#include <iostream>

class Point2d 
{
    public:
    Point2d(double x, double y)
        : m_x {x}
        , m_y {y}
    {}

    Point2d() = default;

    void print() const
    {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }

    double distanceTo(const Point2d& o) const
    {
        return std::sqrt((m_x - o.m_x) * (m_x - o.m_x) + (m_y - o.m_y) * (m_y - o.m_y));
    }

    private:
    double m_x {0};
    double m_y {0};
};

class Fraction
{
    public:
    Fraction() = default;
    Fraction(int n, int d)
        : m_numerator {n}
        , m_denominator {d}
    {}

    Fraction getFraction() const
    {
        Fraction temp{};

        std::cout << "Enter a value for numerator: ";
        std::cin >> temp.m_numerator;
        std::cout << "Enter a value for denominiator: ";
        std::cin >> temp.m_denominator;
        std::cout << '\n';

        return temp;
    }

    Fraction multiply(const Fraction& o) const
    {
        return Fraction {m_numerator * o.m_numerator, m_denominator * o.m_denominator};
    }

    void printFraction() const
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }

    private:
    int m_numerator {0};
    int m_denominator {1};
};

int main()
{
    Point2d first{};
    Point2d second{3.0, 4.0};

    // Point2d third{4.0}; should error

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    Fraction f0 {};
    Fraction f1 = f0.getFraction();
    Fraction f2 = f0.getFraction();

    std::cout << "Your two fractions multiplied together: ";

    f1.multiply(f2).printFraction();

    return 0;
}