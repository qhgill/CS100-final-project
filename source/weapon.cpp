#include "../header/weapon.h"

Weapon::Weapon()
: damage(0), damageType("physical"), Item("a", 0, "weapon") 
{}

Weapon::Weapon( const std::string& name, int level, int damage_, const std::string& damageType_ )
: damage(damage_), damageType(damageType_), Item(name, level, "weapon") 
{}

int Weapon::getDamage() 
{ 
    return damage; 
}

std::string Weapon::getDamageType() 
{ 
    return damageType; 
}

int Weapon::calcDamage(int lvl) 
{ 
    return lvl*damage; 
}

int Weapon::calcValue() 
{ 
    return 0; 
}