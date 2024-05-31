#include "../header/enemy.h"

Enemy::Enemy(int level_, int health_, int maxHealth_, int damage_, int magicResist_, int physicalResist_, bool isdead_, std::string name_)
: level(level_), health(health_), maxHealth(maxHealth_), damage(damage_), magicResist(magicResist_), physicalResist(physicalResist_), isdead(isdead_), name(name_) 
{}

Enemy::Enemy(): level(1), health(10), maxHealth(10), damage(2), magicResist(1), physicalResist(1), isdead(false), name("enemy")
{}

int Enemy::getLevel() 
{
    return level;
}
int Enemy::getHealth() 
{
    return health;
}
int Enemy::getMaxHealth() 
{
    return maxHealth;
}
int Enemy::getDamage() 
{
    return damage;
}
int Enemy::getMagicResist() 
{
    return magicResist;
}
int Enemy::getPhysicalResist() 
{
    return physicalResist;
}
bool Enemy::getStatus() 
{
    return isdead;
}
std::string Enemy::getName() 
{
    return name;
}
void Enemy::dealDamage(int takeDamage) 
{
    health-=takeDamage;
}
void Enemy::healself(int healHP) 
{
    health+=healHP;
}
void Enemy::killThis() 
{
    isdead=true;
}