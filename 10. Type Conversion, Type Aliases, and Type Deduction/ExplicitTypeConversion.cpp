#include <cassert>
#include <iostream>
#include <vector>

void func(int* xyz) { *xyz += 4; }
void read_only_func(int* xyz) { std::cout << *xyz << '\n'; }

auto main() -> int {
    // static_cast - performs compile-time conversions between related types (safe)
    // dynamic_cast - performes run-time conversions on pointers or references in polymorphic
    // inheirtance hierarchy (safe)

    // const_cast - adds or removes const (safe for adding const to var) avoid unless good reason
    // reinterpret_cast - reinterprets bit level representation of one type as if it were another
    // (unsafe) avoid unless good reason

    // c-style casts - unsafe

    int x{10};
    int y{4};

    // c style casting - very common; do not use
    // performs a wide array of casts: static_cast, const_cast, and reinterpretive cast
    // and never clear which one it is doing
    std::cout << x << " / " << y << " = " << x / y << '\n';
    std::cout << (double)x << " / " << y << " = " << (double)x / y << '\n';
    std::cout << double(x) << " / " << y << " = " << double(x) / y << '\n';

    // most common cast is static_cast<>()
    // returns a temp variable that is direct initialized with new value
    // provides compile time checks, prevents dangerous casts
    std::cout << x << " / " << y << " = " << static_cast<double>(x) / y << '\n';

    // using const cast to write over a const variable!
    const int zzz{2};
    const int* ptr{&zzz};
    std::cout << *ptr << '\n';
    func(const_cast<int*>(ptr));  // editing a const value is undefined behavior so even though we
                                  // are doing it right now, theres no guarnatees about it
    std::cout << *ptr << '\n';    // this print 6
    std::cout << zzz << '\n';     // this prints 2 (constant folding most likely)

    // a better example of using const cast is to deal with functions that take in non-const
    // pointers but don't actually write to them

    read_only_func(const_cast<int*>(
        ptr));  // here we need to pass in a const ptr, but the parameter is nonconst. we know this
                // is safe though because the function is read-only so theres no undefined behavior

    return 0;
}

// another const cast example
class Buffer {
   private:
    std::vector<int> data;

   public:
    // const function to support const Buffers
    [[nodiscard]] auto at(std::size_t index) const -> const int& {
        assert(index > 0 && "Index must be greater than 0!");
        assert(index < data.size() && "Index must be less than Buffer size!");
        return data.at(index);
    }

    // non-const function to support non-const Buffers
    [[nodiscard]] auto at(std::size_t index) -> int& {
        // trying to re-use the logic from the const implementation of this function
        return const_cast<int&>(static_cast<const Buffer*>(this)->at(index));
        // Here we are first taking the non-const Buffer (through this) and then casting it into
        // const Buffer*. This allows us to call the const at function. We don't use const_cast here
        // because const_cast is generally seen as an unsafe function so we are using static cast
        // because we are adding constness here not removing it. later we remove the constness of
        // the return value so that the user can use their int& however they may like.
    }
};
