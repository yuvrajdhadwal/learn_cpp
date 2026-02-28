/**
 * Unique Pointer is the only Pointer that owns a resource
 * What if we want multiple pointers to the same resource? Shared Pointers!
 *
 * Unique Pointers can be converted to Shared Pointers; Shared Pointers cannot be converted to Unique Pointers
 */

#include <iostream>
#include <memory>

class Resource {
   public:
    Resource() { std::cout << "Resource Acquired\n"; }
    ~Resource() { std::cout << "Resource Released\n"; }
};

auto main() -> int {
    // allocate resource shared by multiple shared pointers
    auto ptr1{std::make_shared<Resource>()};  // safer and more performant
                                              // make_shared uses one allocation to allocate resource and shared pointer tracking object

    {
        auto ptr2{ptr1};
        // make another shared ptr pointing to same resource
        // note: we copied shared ptr not made new shared pointer this is how it keeps
        // count of how many references; if we made with res, it would destroy resource
        // in this scope and cause double free
        std::cout << "Killing one shared pointer\n";
    }  // ptr2 goes out of scope; nothing happens
       //
    std::cout << "Killing another shared pointer\n";

    return 0;
}  // all pointers to resource go out of scope deallocating it
