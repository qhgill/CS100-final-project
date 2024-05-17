#include "../header/enemy.h"

Enemy::Enemy(int level_, 
              int health_, 
              int maxHealth_, 
              int damage_, 
              int magicResist_, 
              int physicalResist_,
              string name_)
: level(level_), health(health_), maxHealth(maxHealth_), 
damage(damage_), magicResist(magicResist_), physicalResist(physicalResist_), 
name(name_) {}


