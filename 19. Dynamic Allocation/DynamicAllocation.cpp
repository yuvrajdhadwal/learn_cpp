#include <iostream>

/*
C++ supports three basic types of memory allocation

Static Memory Allocation: Happens for Static and Global Variables. Allocated at program start
and persist throughout program lifetime

Automatic Memory Allocation: Happens for function parameters and local variables. Allocated
when declared and then freed once block ends (variables stored on the stack) this includes
fixed arrays

Static and Automatic Memory Allocation must know the size of variable at compile time and
memory allocation and deallocation happens automatically when the variable is initialized and 
destroyed

Stack is 8 MB in size per process

Dynamic Memory Allocation: Heap allocated memory, when the program requests memory from the 
operating system when needed. should be used when sizeof variable is unknown at compile time
*/

void memoryLeak()
{
    int* ptr {new int{}};  // this will lead to memory leak
}  // ptr will go out of scope, but heap allocated memory will stay
// memory leaks will be cleaned by operating system once program is over (linux)

int main()
{
    // new keyword can fail when os cannot grant any more memory (program will crash)
    int* ptr {new int};  // dynamically allocates an integer and returns address of block to ptr
    *ptr = 4;  // assign value of 4 to allocated memory
    delete ptr;  // return memory pointed to by ptr to the operating system

    // access heap allocated objes is generally slower than accessing stack allocated objects

    // dangling pointers
    std::cout << *ptr << '\n';  // ptr is deallocated so dereferenceing it is undefined
    // this prints -1342554145 instead of 4

    // another dangling pointer example
    int* ptr2 { new int{} };  // dynamically allocates new int (0)
    int* otherPtr { ptr2 };  // otherPtr points to ptr2 location

    delete ptr2;  // deallocated memory
    ptr2 = nullptr;  // good practice to set freed pointers to nullptr
    std::cout << *otherPtr << '\n';  // undefined behavior, accessing dangling ptr

    // ensure program doesn't crash when calling new like this
    int* val {new (std::nothrow) int{}};  // ensures program doesn't crash; instead val is nullptr
    delete ptr2;  // does nothing; not efficient or inefficent to delete nullptrs

    memoryLeak();  // causes memory leak

    int value {5};
    int* memLeakPtr {new int{}};
    // delete memLeakPtr;  - this fixes th memory leak
    memLeakPtr = &value;  // this causes memory leak since orig ptr is changed

    int* anotherMemLeak {new int{}};
    anotherMemLeak = new int{};  // another memory leak! orig ptr is changed

    // dynamically allocate arrays (what?! but they're fixed size)
    // if your arrays are so large that they pollute the stack (fixed size of 8mb)
    // you can dynamically allocate them to heap which is many GB

    int length {5};  // does not need to be constant anymore
    // note this is a ptr to first element in array (decayed c-style array)
    int* array { new int[length]{} };  // heap allocated fixed-size array
    array[0] = 5;  // same as always usage
    delete[] array;  // syntax to free array from heap memory (Notice: delete[] not delete)

    auto* anotherArray{ new int[5]{ 9, 7, 5, 3, 1 } };
    delete[] anotherArray;

    return 0;
}