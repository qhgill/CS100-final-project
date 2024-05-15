#include "../header/weapon.h"

Weapon::Weapon(int damage_, string damageType_, Item* item1)
: damage(damage_), damageType(damageType_), info(item1) {}

