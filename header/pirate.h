#pragma once
#include "./enemy.h"

class Pirate {
    private:

    public:
        Pirate();
        Pirate(int level, int health, int maxHealth, int damage, int magicResist, int physicalResist, bool isDead, const std::string& name);

        virtual void calculateTurn(StatsManager*);
};