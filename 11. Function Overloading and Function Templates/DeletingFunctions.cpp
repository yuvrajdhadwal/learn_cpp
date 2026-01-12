#include <iostream>

void printInt(int x)
{
    std::cout << x << '\n';
}

void printInt(char) = delete;
void printInt(bool) = delete;  // calls to this function will result in compiler error

template <typename T>
void printInt(T x) = delete;  // uses template to delete all other types, no need for long list

int main()
{
    printInt(96);
    
    // printInt('a');  // delete results in compilation error
    // printInt(true);  // numeric conversion

    // printInt(5.0);  // ambigious, numeric conversion has no best between printInt(int),
    // printInt(char), printInt(bool) even though those two are deleted

    return 0;
}