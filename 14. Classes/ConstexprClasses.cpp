#include <iostream>

// can be evaluated either at compile or runtime since its constexpr function
constexpr int greater(int x, int y)
{
    return (x > y ? x : y);
}

struct PairStruct
{
    int x{};
    int y{};

    constexpr int greater() const  // constexpr member function must be const as well
    {
        return (x > y ? x : y); 
    }
};

class PairClass
{
    public:
    // if you want compile time classes you need constexpr constructors
    constexpr PairClass(int x, int y)  // classes that want to have constexpr member functions
    // must have constexpr constructors
        : m_x {x}
        , m_y {y}
    {}

    constexpr int greater() const
    {
        return (m_x > m_y ? m_x : m_y); 
    }

    private:
    int m_x{};
    int m_y{};
};

constexpr int init()
{
    PairClass pc {5, 6};  // requires constexpr constructor
    return pc.greater();  // requires constexpr qualifier
}

int main()
{
    std::cout << greater(5, 6) << '\n';  // can be evaluated in compile or runtime

    constexpr int a {greater(5, 6)};  // must be evaluated in compile time
    std::cout << a << '\n';

    constexpr PairStruct ps {5, 6};
    std::cout << ps.greater() << '\n';

    constexpr int b {ps.greater()};  // constexpr member function can only be called on 
    // constexpr objects
    std::cout << b << '\n';

    constexpr PairClass pc {5, 6};  // need constexpr constructor for this
    std::cout << pc.greater() << '\n';

    constexpr int c {pc.greater()};  // can only be called on constexpr objects
    std::cout << c << '\n';

    constexpr int d {init()};  // init is called in compile time context
    std::cout << d << '\n';

    return 0;
}