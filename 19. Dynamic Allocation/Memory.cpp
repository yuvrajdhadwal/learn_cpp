/*

Memory is divided into following segements:

Code: where compiled program sits in memory, typically read only
BSS: where zero-initialized global and static variables are stored
Data: where initialized global and static variables are stored
Heap: where dynamically allocated variables are allocated from
Call Stack: where function parameters, local variables, and function related info is stored

Heap:
    - Allocating memory on heap is comparatively slow
    - Allocated memory exists until deallocated or application ends (os frees memory)
    - Allocated memory can only be allocated through dereferencing pointer (slower than direct)
    - Big pool of memory (gigabytes in size)

Stack:
    - Stack Overflow: Stack is only 8MB of space, if fully allocated, stack will overflow
        - OS will terminate offending program
    - Allocating memory on stack is comparatively fast
    - Memory allocated on stack stays allocated until popped off stack
    - All memory stored on stack is known at compile time; memory can be accessed through variable
    - Don't put large data structures on stack as space is limited
*/