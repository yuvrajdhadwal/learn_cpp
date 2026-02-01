#include <iostream>

// "this" is a const pointer; all non-static member functions have it

class Simple
{
    public:
    Simple() = default;
    Simple(int id)
        : m_id {id}
    {}

    int getID() const
    {
        return m_id;
        // implicity: return this->m_id;
    }

    void setID(int m_id)
    {
        // "this" is used to disambiguate 
        this->m_id = m_id;
    }

    // in a const function you cannot change this. it is const pointer to const obj right now
    void print() const
    {
        std::cout << m_id << '\n';
        // implicitly: std::cout << this->m_id;
    }

    // we can chain function calls by making functions return the object
    Simple& add(int value) {m_id += value; return *this;}
    Simple& sub(int value) {m_id -= value; return *this;}
    Simple& mul(int value) {m_id *= value; return *this;}

    // resets the current object by creating a new object and changing this refernece
    // to reference that object
    // notice how this is a const pointer (can't change where its pointing to but can
    // change what its pointing to)
    void reset() {*this = {};}

    private:
    int m_id{};
};

int main()
{
    Simple s {5};

    // chaining functions
    s.add(5).sub(3).mul(2);
    s.print();
    s.reset();
    s.print();

    return 0;
}