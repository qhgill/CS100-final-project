#pragma once
#include "./enemy.h"
#include "./statsManager.h"

class RoyalGuard : public Enemy {
    public:
        RoyalGuard();
        RoyalGuard(int level);
        RoyalGuard(int level, int health, int maxHealth, int damage, int magicResist, int physicalResist, bool isDead, const std::string& name);

        void calculateTurn(StatsManager*);
};