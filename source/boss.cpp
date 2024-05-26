#include "../header/boss.h"

Boss::Boss() : Enemy(0, 0, 0, 0, 0, 0, false, "") 
{}

Boss::Boss(int level, int health, int maxHealth, int damage, int magicResist, int physicalResist, bool isDead, const std::string& name) 
: Enemy(level, health, maxHealth, damage, magicResist, physicalResist, isDead, name)
{}
