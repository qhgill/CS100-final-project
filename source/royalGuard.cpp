#include "../header/royalGuard.h"

RoyalGuard::RoyalGuard(int level, int health, int maxHealth, int damage, int magicResist, int physicalResist, bool isdead, std::string name)
: level(level), health(health), maxHealth(maxHealth), damage(damage), magicResist(magicResist), physicalResist(physcialResist), isdead(isdead), name(name)
{}

RoyalGuard::RoyalGuard() : level(0), health(0), maxHealth(0), damage(0), magicResist(0), physicalResist(0), isdead(false), name("")
{}

void calculateTurn(StatsManager* sm) {
    int royalGuardDamage = getDamage();

    if (sm->getMagicResist() > sm->getPhysicalResist()) {
        sm->takeDamage(royalGuardDamage, "physical");
    } else {
        sm->takeDamage(royalGuardDamage, "magical");
    }
}