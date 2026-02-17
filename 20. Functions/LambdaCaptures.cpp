#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <string>

// captures are cloned everytime the lambda is defined
// cloned variables initialized from outer scope variables
// captured variables are member variables of functor object (the lambda)
// when lambda definition is encountered at runtime, lambda object and capture vars instantiated 

// captures are treated as const by default; there will be compiler error
// possible to have dangling captured variables
// dont use mutable lambdas

int main()
{
    std::array<std::string_view, 4> arr {"apple", "banana", "walnut", "lemon"};

    std::cout << "Enter a fruit: ";
    std::string search {};
    std::cin >> search;

    auto found 
    {
        std::find_if(arr.begin(), arr.end(), 
        // can't use another parameter since find_if is expecting only one parameter
        //   vvvvvv  this is the capture clause that allows us to use search here
            [search](std::string_view str)
            {
                return str.find(search) != std::string_view::npos;
            })
    };

    if (found == arr.end()) { std::cout << "Not Found!\n"; }
    else { std::cout << *found << " found!\n"; }

    int ammo {10};
    
    auto shoot
    {
        // if mutable keyword not used, then compiler error
        // since capture variables are member variables, they're updated
        [ammo]() mutable  // mutable allows you to edit captured value
        {
            --ammo;
            std::cout << "Pew! Ammo: " << ammo << '\n';
        }
    };

    shoot();
    shoot();
    shoot();
    shoot();
    // logic error!
    std::cout << "Ammo: " << ammo << '\n';  // ammo was cloned for capture variable
    shoot();  // capture ammo != ammo

    auto correctShot
    {
        // no need for mutable
        [&ammo]()  // captured by reference
        {
            // this will effect the regular ammo
            std::cout << "Pew! Ammo: " << --ammo << '\n';
        }
    };

    correctShot();
    correctShot();
    correctShot();
    correctShot();
    std::cout << "Ammo: " << ammo << '\n';  // logic error fixed :)
    correctShot();

    // we can use capture variables for counting stuff

    std::array array {2, 3, 7, 1, 2, 10, 12, 15, 23};
    int comp {0};

    std::sort(array.begin(), array.end(), 
                [&comp](int x, int y) { ++comp; return x < y; });
    
    std::cout << "Sort had " << comp << " comparisons!\n";

    struct enemy { int damage; };

    int health {100};
    int armor {100};
    std::vector<enemy> enemies{};

    [health, armor, &enemies]() {};  // multiple capture variables in one lambda

    // default captures capture all variables that are mentioned in the lambda

    [=]() { return health; };  // captures health by value
    [&]() {return enemies; };  // captures enemies by reference
    [=, &health, &enemies]()  // default capture is first, all other captures can't be same type
    // of capture
    { 
        std::cout << enemies[0].damage << " hit you!\n";  // enemies captured by ref
        health -= enemies[0].damage;  // health captured by ref
        std::cout << "Status: " << armor << " Armor; " << health << " Health!\n";  
        // armor captured by valye
    };

    // you can define new vars in lambda capture
    [vitality {health * armor}]() {};  // type of vitality is deduced
    // don't do this, create a var vitality and then capture it since this syntax is wack

    return 0;
}