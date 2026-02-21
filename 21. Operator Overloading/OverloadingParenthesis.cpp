#include <cassert>  // for assert
#include <iostream>

// must be overloaded as a member function

class Matrix
{
    private:
    double m_data[4][4] {};

    public:
    // can have variable number of parameters and types of parameters
    double& operator()(int row, int col);
    double operator()(int row, int col) const;  // for const objs
    // proof, don't do this though since it doesn't semantically make sense
    void operator()();

    // as of cpp23, operator[] can do the same thing with multiple parameters
    // double& operator[](int row, int col); i dont think my compiler supports it yet
};

double& Matrix::operator()(int row, int col)
{
    assert(row >= 0 && row < 4);
    assert(col >= 0 && col < 4);

    return m_data[row][col];
}

double Matrix::operator()(int row, int col) const
{
    assert(row >= 0 && row < 4);
    assert(col >= 0 && col < 4);

    return m_data[row][col];
}

void Matrix::operator()()
{
    for (int i {0}; i < 4; ++i)
    {
        for (int j {0}; j < 4; ++j)
        {
            m_data[i][j] = 0.0;
        }
    }
}

// double& Matrix::operator[](int row, int col)
// {
//     return (*this)(row, col);  // utilizing the other function to keep this easy
// }

// operator() is commonly overloaded for implementing functors (function objects)
// these are classes that act like functions, the benefit is that they can store member variables

class Accumulator
{
    private:
    int m_counter{0};

    public:
    // this could be member variable but this is an easy way to do it too
    int operator()(int i) { return (m_counter += i); }

    void reset() { m_counter = 0; }  // regular member variables
};

int main()
{
    Matrix matrix;
    matrix(1, 2) = 4.5;
    matrix();
    std::cout << matrix(1, 2) << '\n';
    // std::cout << matrix[3, 2] << '\n';

    Accumulator acc{};
    std::cout << acc(1) << '\n';
    std::cout << acc(4) << '\n';

    Accumulator acc2{};  // member variables are defaulted when new object created
    // that may be obvious, but it explains difference between functor member variables
    // and static local variables
    std::cout << acc2(15) << '\n';
    std::cout << acc2(12) << '\n';

    return 0;
}