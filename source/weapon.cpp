#include "../header/weapon.h"

Weapon::Weapon( string name, int level, int damage_, string damageType_ )
: damage(damage_), damageType(damageType_), Item(name, level, "weapon") {}

