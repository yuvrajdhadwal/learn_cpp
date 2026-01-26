#include <iostream>
#include <string>

enum class MonsterType
{
    OGRE, DRAGON, ORC, SPIDER, SLIME,
};

struct Monster
{
    std::string name {};
    MonsterType type {};
    int health {};
};

template <typename T>
struct Triad
{
    T one {};
    T two {};
    T three {};
};

constexpr std::string_view monsterTypeToString(MonsterType type)
{
    switch (type)
    {
        case MonsterType::OGRE:
            return "Ogre";
        case MonsterType::DRAGON:
            return "Dragon";
        case MonsterType::ORC:
            return "Orc";
        case MonsterType::SPIDER:
            return "Giant Spider";
        case MonsterType::SLIME:
            return "Slime";
        default:
            return "";
    }
}

void printMonster(const Monster& monster)
{
    std::cout << "This " << monsterTypeToString(monster.type) << " is named " << monster.name
        << " and has " << monster.health << " health.\n";
}

template <typename T>
void print(Triad<T> t)
{
    std::cout << '[' << t.one << ", " << t.two << ", " << t.three << ']';
}

int main()
{
    Monster torg {"Torg", MonsterType::OGRE, 145};
    Monster blurp {"Blurp", MonsterType::SLIME, 23};

    printMonster(torg);
    printMonster(blurp);

    Triad t1 {1, 2, 3};  // using ctad to deduce template arguments
    print(t1);

    Triad t2 {1.2, 3.4, 5.6};
    print(t2);

    return 0;
}