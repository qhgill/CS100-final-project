#pragma once 
#include "./statsManager.h"
#include <string>
//#include "./statsManager.h"

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
        Enemy(int level_, int health_, int maxHealth_, int damage_, int magicResist_, int physicalResist_, bool isdead_, std::string name_);
        Enemy();
        virtual ~Enemy();
        int getLevel();
        int getHealth();
        int getMaxHealth();
        int getDamage();
        int getMagicResist();
        int getPhysicalResist();
        bool getStatus();
        std::string getName();
        void dealDamage(int takeDamage);
        void healself(int healHP);
        void killThis();
        virtual void calculateTurn(StatsManager*) = 0;
};
