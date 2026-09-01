#include <iostream>

class Fruit {
   public:
    // define nested types at start of the class definition
    enum Type  // nested enum within class
    {
        apple,
        banana,
        cherry,
    };

    using IDType = int;  // typedefs can also be defined as nested type

    class Printer  // nested class within class
    {
       public:
        // inner classes don't have access to the "this" pointer of outer class
        // so you must pass in the object if you want to call outer class members
        void print(const Fruit& f) const {
            // however, since printer is part of Fruit, we can access the private members directly
            std::cout << f.m_percentageEaten << "% eaten!\n";
        }
    };

    class innerClass;  // forward declared nested class

    Fruit(Type type) : m_type{type} {}

    Type getType() { return m_type; }
    int getPercentageEaten() { return m_percentageEaten; }

    // inside the class
    // we can use enums and typedef without qualifier
    bool isCherry() { return m_type == cherry; }
    IDType getId() const { return m_id; }

   private:
    Type m_type{};
    int m_percentageEaten{0};
    IDType m_id{0};
};

class innerClass {
    // definition for forward declared inner class
};

int main() {
    Fruit apple{Fruit::apple};        // to access enums, we need to specify the class
    Fruit::IDType id{apple.getId()};  // need to use qualifier to use typedef
    Fruit::Printer printer{};         // needs the qualifier of outer class to access inner class
    printer.print(apple);

    if (apple.getType() == Fruit::apple) {
        std::cout << "Fruit is Type: Apple\n";
    } else {
        std::cout << "Fruit is Not Type: Apple\n";
    }

    return 0;
}
