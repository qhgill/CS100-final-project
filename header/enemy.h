#pragma once 
#include <string>

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
        std::string name;
    public:
        Enemy(int level_, 
              int health_, 
              int maxHealth_, 
              int damage_, 
              int magicResist_, 
              int physicalResist_,
              bool isdead_,
              std::string name_);
              
        int getLevel() {return level;}
        int getHealth() {return health;}
        int getMaxHealth() {return maxHealth;}
        int getDamage() {return damage;}
        int getMagicResist() {return magicResist;}
        int getPhysicalResist() {return physicalResist;}
        bool getStatus() {return isdead;}
        std::string getName() {return name;}

        void dealDamage(int takeDamage) {health-=takeDamage;}

        void healself(int healHP) {health+=healHP;}

        void killThis() {isdead=true;}

        //virtual int calcTurn();
};
