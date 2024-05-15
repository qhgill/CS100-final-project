#include <iostream>
#include <string>
using namespace std;

class Item
{
    private:
        string name;
    public:
        Item():name(""){}
        Item(string name_):name(name_){}
        string getName() {return name;}
};

class Weapon: public Item
{
    private:
        int damage;
        string damageType;
        Item* info;

    public:
        Weapon():damage(0), damageType(0), info(nullptr) {}
        Weapon(int damage_, string damageType_, Item* item1);
        int getDamage() {return damage;}
        string getDamageType() {return damageType;}
        int calcDamage(int level) {return level*damage;}

};
