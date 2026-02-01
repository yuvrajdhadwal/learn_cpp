#include <iostream>

class Simple
{
    public:
    Simple (int id)
        : m_id {id}
    {
        std::cout << "Constructing Simple:  " << m_id << '\n';
    }

    // if not declared, program will provide placeholder empty destructor
    ~Simple()  // destructor - can't take arguments or return anything
    // there can only be one destructor
    {
        std::cout << "Destructing Simple: " << m_id << '\n';
    }

    int getId() const { return m_id; }

    private:
    int m_id {};
};

int main()
{
    Simple simple1 {1};

    {  // inner scope
        Simple simple2 {2};
    }

    // std::exit and unhandled exceptions may not call destructors leading to potential 
    // memory leaks
    return 0;
}