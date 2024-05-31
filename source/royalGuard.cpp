#include "../header/royalGuard.h"

RoyalGuard::RoyalGuard(int level, int health, int maxHealth, int damage, int magicResist, int physicalResist, bool isdead, const std::string& name)
: Enemy(level, health, maxHealth, damage, magicResist, physicalResist, isDead, name)
{}

RoyalGuard::RoyalGuard() : Enemy(0, 0, 0, 0, 0, 0, false, "")
{}

void calculateTurn(StatsManager* sm) {
    int royalGuardDamage = getDamage();

    if (sm->getMagicResist() > sm->getPhysicalResist()) {
        sm->takeDamage(royalGuardDamage, "physical");
    } else {
        sm->takeDamage(royalGuardDamage, "magical");
    }
}