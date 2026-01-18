#include <iostream>

const std::string& getConstRef(); // some function that returns a const reference

int main()
{
    // top level consts: applies to object itself (references implicitly top level const)
        // const int x, int* const ptr
    // bottom level consts: const applies to object being referenced or pointed to
        // const int& ref, const int* ptr
    
    // const int x;    // this const applies to x, so it is top-level
    // int* const ptr; // this const applies to ptr, so it is top-level
    // references don't have a top-level const syntax, as they are implicitly top-level const
    // const int& ref; // this const applies to the object being referenced, so it is low-level
    // const int* ptr; // this const applies to the object being pointed to, so it is low-level
    // const int* const ptr; // the left const is low-level, the right const is top-level

    // type deductions first drop references, unless deduced type is described as reference
    // this causes low level consts to become high level consts for references
// type deduction then drops top level consts, unless deduced type is described as const/constexpr
    // constexpr never deduced, must be manually described
    // type deduction does not drop pointers
    // always describe deduction to ensure there is no miscommunication, even if redundant

    auto ref1{ getConstRef() };        // std::string (reference and top-level const dropped)
    const auto ref2{ getConstRef() };  // const std::string (reference dropped, const dropped, 
    // const reapplied)

    auto& ref3{ getConstRef() };       // const std::string& (reference dropped and reapplied, 
    // low-level const not dropped)
    const auto& ref4{ getConstRef() }; // const std::string& (reference dropped and reapplied, 
    // low-level const not dropped)

    // when using auto, deduced type will be pointer if initializer is pointer, auto* always pointer
    // auto const, const auto will make deduced pointer into const pointer (can't change address)
    // auto* const will also make const pointers
    // const auto* will make pointers to const objects
    // consider auto* over auto when deducing pointer type, allows you to explictly reapply const

    std::string s{};
    const std::string* const ptr { &s };

    auto ptr1{ ptr };  // const std::string*
    auto* ptr2{ ptr }; // const std::string*

    auto const ptr3{ ptr };  // const std::string* const
    const auto ptr4{ ptr };  // const std::string* const

    auto* const ptr5{ ptr }; // const std::string* const
    const auto* ptr6{ ptr }; // const std::string*

    // const auto const ptr7{ ptr };  // error: const qualifer can not be applied twice
    const auto* const ptr8{ ptr }; // const std::string* const
    return 0;
}