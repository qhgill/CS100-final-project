#include <iostream>
#include <string>
using namespace std;

class City;

class Enemy
{
    private:
        int level;
        int health;
        int maxHealth;
        int damage;
        int magicResist;
        int physicalResist;

        bool isdead;

        string name;
        City cityName;

    public:
        Enemy(int level_, 
              int health_, 
              int maxHealth_, 
              int damage_, 
              int magicResist_, 
              int physicalResist_,
              bool isdead_,
              string name_,
              City cityName_);
              
        int getLevel() {return level;}
        int getHealth() {return health;}
        int getMaxHealth() {return maxHealth;}
        int getDamage() {return damage;}
        int getMagicResist() {return magicResist;}
        int getPhysicalResist() {return physicalResist;}
        bool getStatus() {return isdead;}
        string getName() {return name;}
        City getCityName() {return cityName;}

        void dealDamage(int takeDamage) {health-=takeDamage;}

        void healself(int healHP) {health+=healHP;}

        void killThis() {isdead=true;}

        virtual int calcTurn();

};

class City
{
    private:
        string name;
    
    public:
        City(string name_) : name(name_) {}
};

