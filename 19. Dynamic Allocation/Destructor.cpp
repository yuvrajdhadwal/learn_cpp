#include <iostream>

/*
    Destructors are used for cleaning up memory once class is being freed
    - cannot take in arguments, cannot return anything, there can only be one per class
    - automatically called when object is destroyed (like constructor is auto called)

    RAII - Resource Acquired is Initialization
        - Resource acquired during construction, used during duration of object
        - Resoruce released in destructor, this limits memory leaks
        - IntArray is example of RAII Class, std::exit() will not call destructors
*/

class IntArray
{
    private:
    int* m_array{};
    int m_length{};

    public:
    IntArray(int length)  // constructor
    {
        m_array = new int[static_cast<std::size_t>(length)]{};
        m_length = length;
    }

    ~IntArray()  // destructor
    {
        delete[] m_array;
    }

    void setValue(int index, int value) { m_array[index] = value; }
    int getValue(int index) { return m_array[index]; }

    int getLength() { return m_length; }
};

int main()
{
    IntArray ar {10};  // allocates array of 10 integers
    for (int i {0}; i < ar.getLength(); ++i)
        ar.setValue(i, i + 1);

    for (int i {0}; i < ar.getLength(); ++i)
        std::cout << ar.getValue(i) << ' ';

    std::cout << ar.getValue(5);

    return 0;
}