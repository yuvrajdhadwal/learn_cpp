#include <iostream>

template <typename T>
class AutoPtr {
    T* m_ptr{};

   public:
    AutoPtr(T* ptr = nullptr) : m_ptr{ptr} {}

    ~AutoPtr() { delete m_ptr; }

    // Copy constructor: deep copy
    AutoPtr(const AutoPtr& a) {
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
    }

    // Move  Constructor (transfers ownership and can only take r-val)
    AutoPtr(AutoPtr&& a) noexcept  // guarantee to not throw exceptions
        : m_ptr{a.m_ptr} {
        a.m_ptr = nullptr;
    }

    // copy assignment, deepcopy
    auto operator=(const AutoPtr& a) {
        if (&a == this) {
            return *this;
        }

        delete m_ptr;

        m_ptr = new T;
        *m_ptr = *a.m_ptr;

        return *this;
    }

    // move assignment, will only take rvals
    AutoPtr& operator=(AutoPtr&& a) noexcept {
        if (&a == this) {
            return *this;
        }

        delete m_ptr;
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;

        return *this;
    }

    auto operator*() const -> T& { return *m_ptr; }
    auto operator->() const -> T* { return m_ptr; }
    [[nodiscard]] auto isNull() const -> bool { return m_ptr == nullptr; }
};

class Resource {
   public:
    Resource() { std::cout << "Resource Acquired\n"; }
    ~Resource() { std::cout << "Resource Released\n"; }
};

auto generateResource() -> AutoPtr<Resource> {
    AutoPtr<Resource> res{new Resource};
    return res;  // this will invoke move constructor
}

auto main() -> int {
    AutoPtr<Resource> mainres;
    mainres =
        generateResource();  // this assignment will invoke move assignment
                             // this is so much more efficient, instead of 2 copies, it's 2 moves
    // move is called when argument is r-val this is typically a literal or a temporary value
    // default move exists if copy, copy assignment, move constructor, move assignment, destructor
    // not customized default move calls move constructors/assingment on all members with them
    // defined, else will copy note: this means that member pointers are shallow copied! ensure
    // during move, both objects left in valid state (this is why we set a.m_ptr to nullptr)
    //
    // sometimes l-values will be moved, this is why they are being returned by value. sometimes
    // this will be elided, thus it won't be moved or copied, instead it will be constructed in the
    // returned variable
    //
    // Rule of 5:
    //      If Copy Constructor, Copy Assignment, Move Constructor, Move Assignment, or Destructor
    //      defined or deleted, then all of these need to be defined or deleted
    return 0;
}
