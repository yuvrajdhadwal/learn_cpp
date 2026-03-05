#include <iostream>

class Base
{
    public:
    Base() = default;

    void identify() const { std::cout << "Base::identify()\n"; }
    friend auto operator<< (std::ostream& out, const Base& base) -> std::ostream&
    {
        out << "Base!\n";
        return out;
    }

    void print(int) const { std::cout << "Calling Base::print(int)\n"; }
    void print(double) const { std::cout << "Calling Base::print(double)\n"; }

    private:
    // void print() const { std::cout << "base\n"; }  // to use using all overloaded versions must
    // be accessible 
};

class Derived : public Base
{
    public:
    Derived() = default;

    // overrides the behavior of the parent
    // if this didn't exist, then derived.identify() would call the Base version
    // we also now call the parents version of identify too
    // note: requires the scope for call or else it would be recursive call
    void identify() const { std::cout << "Derived::identify()\n"; Base::identify(); }

    void print() const { std::cout << "derived\n"; }
    void print(double) const { std::cout << "Calling Derived::print(double)\n"; }
    using Base::print;  // makes all Base::print functions eligible for overload resolution

    friend auto operator<< (std::ostream& out, const Derived& derived) -> std::ostream&
    {
        out << "Derived!\n";
        // static_cast Derived to Base so that we can get Base version of operator<<
        // this works by default since Derived is a Base
        out << static_cast<const Base&>(derived);
        return out;
    }
};

auto main() -> int
{
    Base base{};
    base.identify();

    Derived derived{};
    derived.identify();
    derived.print();  // shadowed the private print in base
    derived.print(5);  // will cast 5 to 5.0 then call Derived::print(double)
                       // unless we use `using` that makes it so that this call will call
                       // Base::print(int) instead since it is now available for overload in 
                       // Derived
}
