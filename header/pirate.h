#pragma once
#include "./enemy.h"
#include "./statsManager.h"

class Pirate : public Enemy {
    public:
        Pirate();
        Pirate(int level, int health, int maxHealth, int damage, int magicResist, int physicalResist, bool isDead, const std::string& name);

        void calculateTurn(StatsManager*);
};