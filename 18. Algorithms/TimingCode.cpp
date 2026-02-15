#include <chrono>
#include <iostream>

class Timer
{
    private:
    // type aliases to make accessing nested types easier
    using Clock = std::chrono::steady_clock;
    using Second = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<Clock> m_beg {Clock::now()};

    public:
    void reset()
    {
        m_beg = Clock::now();
    }

    [[nodiscard]] auto elapsed() const -> double
    {
        return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
    }
};

int main()  // good to run at least 3 times and have similar results
// timing can be different due to many external factors, time more to get better accuracy of true
// time
{
    Timer t{};
    // do stuff
    std::cout << t.elapsed() << '\n';

    return 0;
}