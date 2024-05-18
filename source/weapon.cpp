#include "../header/weapon.h"

Weapon::Weapon(int damage_, string damageType_, string name, int level)
: damage(damage_), damageType(damageType_), Item(name, level) {}

