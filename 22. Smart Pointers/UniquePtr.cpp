#include <iostream>
#include <memory>   // for std::unique_ptr
#include <utility>  // for std::move
// while std::unique_ptr can be used for arrays, its better to use std::array or std::vector or
// std::string
class Resource {
   public:
    Resource() { std::cout << "Resource Acquired\n"; }
    ~Resource() { std::cout << "Resource Released\n"; }
};

class Fraction {
   private:
    int m_numerator{0};
    int m_denominator{1};

   public:
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{numerator}, m_denominator{denominator} {}

    friend auto operator<<(std::ostream& out, const Fraction& frac) -> std::ostream&;
};

auto operator<<(std::ostream& out, const Resource& res) -> std::ostream& {
    out << "I am a resource!";
    return out;
}

auto operator<<(std::ostream& out, const Fraction& frac) -> std::ostream& {
    out << frac.m_numerator << '/' << frac.m_denominator;
    return out;
}

auto createResource() -> std::unique_ptr<Resource>  // returns std::unique_ptr
{
    return std::make_unique<Resource>();
}  // prior to C++17 move semantics will be employed; after this will be elided

// this takes ownership of resource, which isn't what we want
void takeOwnership(std::unique_ptr<Resource> res) {
    if (res) {
        std::cout << *res << '\n';
    }
}  // the resource is destroyed here

// this function only uses resource, so we accept pointer to resource, not reference to the whole
// unique_ptr<Resource>
void useResource(const Resource* res) {
    if (res) {
        std::cout << *res << '\n';
    } else {
        std::cout << "No resource!\n";
    }
}

auto main() -> int {
    // allocate resource obj and have it owned by unique_ptr
    std::unique_ptr<Resource> res{new Resource()};
    std::unique_ptr<Resource> res2;

    std::cout << "res is " << (res ? "null\n" : "not null\n");
    std::cout << "res2 is " << (res2 ? "null\n" : "not null\n");

    // res2 = res;  // this won't compile since unique_ptr deletes copy semantics
    res2 = std::move(res);  // res2 assumes ownership; res is null

    std::cout << "Ownership transfered\n";

    std::cout << "res is " << (res ? "null\n" : "not null\n");
    std::cout << "res2 is " << (res2 ? "null\n" : "not null\n");

    if (res2)  // implicit cast of unique_ptr to bool
    {
        std::cout << *res2 << '\n';  // derefernece and use just like regular pointer
    }
    // dynamically allocated fraction onto heap
    // we can also put auto type deduction to good use here
    // always prefer make_unique over the new command and unique_ptr
    auto frac1{std::make_unique<Fraction>(3, 4)};
    std::cout << *frac1 << '\n';

    auto fracArr{std::make_unique<Fraction[]>(
        4)};  // creating c-style array of type fraction and length 4
              // don't do this used std::array<Fraction> but this is for demo purposes
    std::cout << fracArr[0] << '\n';

    auto ptr{createResource()};

    // takeOwnership(ptr);  // this doesn't work we can't use copy semantics with unique_ptr
    // takeOwnership(std::move(ptr));  // need to use move semantics

    useResource(ptr.get());  // note: get() used here to get pointer to the resource
    // this ensures that ptr can be used after by using copy semantics on the raw pointer
    //
    // dont delete underlying resource in unique_ptr (this causes double free)
    // dont have multiple unique ptrs for the same resource (this causes double free)
    std::cout << "Ending Program\n";

    return 0;
}  // res goes out of scope here; deallocates resource
