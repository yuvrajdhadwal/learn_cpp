#include <ios>  // for std::boolalpha
#include <iostream>

template <typename T>
class Pair
{
    public:
    // notice how we don't need to restate typename T within class
    // notice it's Pair not Pair<T> this is because constructor is within scope of Pair class
    Pair(const T& first, const T& second)
        : m_first {first}
        , m_second {second}
    {}

    // type T is injected since within Pair definition
    bool isEqual(const Pair& o);  // forward declaration

    private:
    T m_first {};
    T m_second {};
};

// since member method is templated, we need to define it in the same file as declaration
// or else compiler won't know how it is defined everytime we call it
// this is why templated member methods are implemented below class declarations in the same header

// need to supply that T is template since implementation is outside class declaration
template <typename T>
bool Pair<T>::isEqual(const Pair& o)  // taking method header from declaration thats why
// argument is fine with Pair instead of Pair<T>
{
    return m_first == o.m_first && m_second == o.m_second;
}

int main()
{
    Pair p1 {5, 6};  // uses ctad to figure out this is Pair<int>
    std::cout << std::boolalpha << "isEqual(5, 6): " << p1.isEqual(Pair{5, 6}) << '\n';
    std::cout << std::boolalpha << "isEqual(5, 7): " << p1.isEqual(Pair{5, 7}) << '\n';

    return 0;
}