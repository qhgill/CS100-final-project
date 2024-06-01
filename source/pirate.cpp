#include "../header/pirate.h"

Pirate::Pirate() : Enemy(0, 0, 0, 0, 0, 0, false, "")
{}

Pirate::Pirate(int level, int health, int maxHealth, int damage, int magicResist, int physicalResist, bool isDead, const std::string& name)
: Enemy(level, health, maxHealth, damage, magicResist, physicalResist, isDead, name)
{}

Pirate::Pirate(int level)
: Enemy(level, level*20, level*20, level*3, level, level*3, false, "Pirate")
{}

void Pirate::calculateTurn(StatsManager* sm) {
    int pirateDamage = getDamage();
    sm->takeDamage(pirateDamage, "physical");
    return;
}