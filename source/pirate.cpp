#include "../header/pirate.h"

Pirate::Pirate() : Enemy(0, 0, 0, 0, 0, 0, false, "")
{}

Pirate::Pirate(int level, int health, int maxHealth, int damage, int magicResist, int physicalResist, bool isDead, const std::string& name)
: Enemy(level, health, maxHealth, damage, magicResist, physicalResist, isDead, name)
{}

void Pirate::calculateTurn(StatsManager* sm) {
    int pirateDamage = damage;
    sm.takeDamage(damage, "physical");
    return;
}