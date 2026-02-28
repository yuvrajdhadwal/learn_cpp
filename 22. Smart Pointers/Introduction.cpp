#include <iostream>

/**
 * Manually calling new and delete is painful and also easy to forget
 * thus we make smart pointers!
 */

// making our own smart pointer
template <typename T>
class Auto_ptr {
   private:
    T* m_ptr{};

   public:
    // pass in pointer to own via constructor
    Auto_ptr(T* ptr = nullptr) : m_ptr(ptr) {}

    // destructor will ensure deallocation
    ~Auto_ptr() { delete m_ptr; }  // deleting a nullptr has no effect

    // move semantics: class will transfer ownership of object rather than making copy
    // a copy constructor that implements move semantics
    Auto_ptr(Auto_ptr& a)  // note non-const
    {
        m_ptr = a.m_ptr;    // transfer dumb pointer from source to our local object
        a.m_ptr = nullptr;  // ensure source no longer owns this pointer
    }

    // assignment operator that implements move semantics
    auto operator=(Auto_ptr& a) -> Auto_ptr&  // note non-const
    {
        if (&a == this) {
            return *this;
        }

        delete m_ptr;       // ensure deallocation of any pointer we already own
        m_ptr = a.m_ptr;    // transfer dumb pointer ownership
        a.m_ptr = nullptr;  // ensure source no longer owns the pointer
        return *this;
    }

    // overload dereference and operator-> so auto_ptr1 is same as regular ptr to
    // users
    auto operator*() const -> T& { return *m_ptr; }
    auto operator->() const -> T* { return m_ptr; }
    [[nodiscard]] auto isNull() const -> bool { return m_ptr == nullptr; }
};

class Resource {
   public:
    Resource() { std::cout << "Resource Acquired!\n"; }
    ~Resource() { std::cout << "Resource Released!\n"; }
    void sayHi() { std::cout << "Hi!\n"; }
};

auto main() -> int {
    Auto_ptr<Resource> res(
        new Resource());  // note we are allocating memory here
                          // but no explicit delete of memory
                          // also note we are using Resource as type not Resource*
                          // this is because m_ptr is type T* not type T
                          //
    // since initially we didn't make copy/assignment/move constructor, our smart pointer can break
    // this is why we need the cpp rule of 5
    // Auto_ptr1<Resource> res2(res);  // or res2 = res; this causes double free on memory leading
    // to program crash. the way to get around this is deep copying (expensive) or move semantics
    //

    Auto_ptr<Resource> res2;  // starts as nullptr

    std::cout << "res1 is " << (res.isNull() ? "null\n" : "not null\n");
    std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

    res2 = res;
    std::cout << "Transfer of ownership\n";

    std::cout << "res1 is " << (res.isNull() ? "null\n" : "not null\n");
    std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

    return 0;
}  // res goes out of scope here, and autoptr destructor is called freeing the
   // memory
