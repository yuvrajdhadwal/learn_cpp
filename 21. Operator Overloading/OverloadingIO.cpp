#include <iostream>

class Point
{
    private:
    double m_x{};
    double m_y{};
    double m_z{};

    public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x {x}
        , m_y {y}
        , m_z {z}
    {}

    // using friend for easy access to member vars (i dont wanna make getters)
    friend std::ostream& operator<< (std::ostream& out, const Point& point);
};

std::ostream& operator<< (std::ostream& out, const Point& point)
{
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';
    return out;
}

// not a friend function
std::istream& operator>> (std::istream& in, Point& point)  // notice non-const point
{
    double x{};
    double y{};
    double z{};

    // if (in >> x >> y >> z)  // if all executions succeed
    {
        // point = Point{x, y, z};  // safely create point
    }  // this is considered a transactional function (all or nothing)

    // a better way
    in >> x >> y >> z;  //  it evaluates like this: (((in >> x) >> y) >> z) -> in (false if fail)
    point = in ? Point{x, y, z} : Point{};  // defaults original point to 0 on failure

    // you can also set in to fail if you want
    in >> x >> y >> z;  // fails if any value is negative
    if (x < 0 || y < 0 || z < 0) { in.setstate(std::ios_base::failbit); }
    point = in ? Point{x, y, z} : Point{};  // default case

    return in;
}

int main()
{
    Point p1 {};
    std::cout << "My point is " << p1 << '\n';
    std::cin >> p1;
    std::cout << "My point is now " << p1 << '\n';

    return 0;
}