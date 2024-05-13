#include <iostream>
#include <string>
using namespace std;

class enemy
{
    private:
        int level;
        int health;
        int maxHealth;
        int damage;
        int magicResist;
        int physicalResist;

        bool isdead = false;

        string name;
        // City cityName;
    public:
        enemy();
        int getLevel() {return level;}
        int getHealth() {return health;}
        int getMaxHealth() {return maxHealth;}
        int getDamage() {return damage;}
        int getMagicResist() {return magicResist;}
        int getPhysicalResist() {return physicalResist;}
        bool getStatus() {return isdead;}
        string getName() {return name;}
        //City getCityName() {return cityName;}

        void dealDamage(int takeDamage) {health-=takeDamage;}

        void healself(int healHP) {health+=healHP;}

        void killThis() {isdead=true;}

        //virtual int calcTurn();

};