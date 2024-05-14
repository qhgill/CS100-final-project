#include "header/enemy.h"

Enemy::Enemy(int level_, 
              int health_, 
              int maxHealth_, 
              int damage_, 
              int magicResist_, 
              int physicalResist_,
              bool isdead_,
              string name_,
              City cityName_)
: level(level_), health(health_), maxHealth(maxHealth_), 
damage(damage_), magicResist(magicResist_), physicalResist(physicalResist_), 
isdead(isdead_), name(name_), cityName(cityName_) {}


