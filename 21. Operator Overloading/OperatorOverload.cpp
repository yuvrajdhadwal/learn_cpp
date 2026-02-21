#include <iostream>

/**
 * Best Practices:
 *      - Overloaded Operators should operate on at least one program defined type
 *          - Either as a parameter or implicit object
 *      - When Overloading Operators, keep function of Operators as close to original intent
 *          as possible
 *      - Operators can be pretty unclear, if not immediately obvious, use a named func instead
 *      - Operators that don't edit operands, should generally return by value
 *      - Operators that do edit operands, should return by reference
 * 
 * When to Use Normal, Friend, or Member Operator Overloads?
 *      - Binary Operators that don't modify left parameter: friend/normal(preferred)
 *      - Binary Operators that do modify left parameter: member
 *      - Unary Operators: member
 *
 *      - If Overloading assignment, operator[], operator(), operator->: member
 *      - Binary Operators when modifying left parameter, but it can't be class
 *          friend/normal(preferred)
 */