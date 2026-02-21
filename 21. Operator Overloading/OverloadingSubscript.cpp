#include <iostream>

class IntList
{
    private:
    int m_list[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    public:
    int& operator[] (int index);
    // const overload for const objs
    const int& operator[] (int index) const;
};

int& IntList::operator[] (int index)
{
    return m_list[index];
}

const int& IntList::operator[] (int index) const
{
    return m_list[index];
}

int main()
{
    IntList list {};
    list[2] = 3;
    std::cout << list[2] << '\n';

    const IntList clist {};
    std::cout << clist[2] << '\n';

    return 0;
}