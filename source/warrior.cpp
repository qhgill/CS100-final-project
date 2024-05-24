#include "../header/warrior.h"

Warrior::Warrior() 
{
    this->baseHP = 15;
    this->baseDamage = 7;
    this->basePhysicalResist = 5;
    this->baseMagicResist = 5;
    this->className = "Warrior";
    this->firstSpell = new Slam();
    this->secondSpell = new Shatter();
    this->thirdSpell = new Bludgeon();
}

Warrior::~Warrior() 
{
    delete firstSpell;
    delete secondSpell;
    delete thirdSpell;
}