#include <iostream>
#include <vector>

void printStack(const std::vector<int>& stack)
{
    if (stack.empty()) { std::cout << "Empty"; }

    for (const auto& e : stack) { std::cout << e << ' '; }
    std::cout << "\tCapacity: " << stack.capacity() << " Length: " << stack.size() << '\n';
}

int main()
{
    std::vector<int> stack {};
    printStack(stack);

    stack.push_back(1);  // pushes element on stack
    printStack(stack);
    stack.push_back(2);
    printStack(stack);
    stack.push_back(3);
    printStack(stack);

    std::cout << "Top: " << stack.back() << '\n';  // back gives last element

    stack.pop_back();  // pops from stack
    printStack(stack);
    stack.pop_back();
    printStack(stack);
    stack.pop_back();
    printStack(stack);

    return 0;
}