#include "../header/rogue.h"

Rogue::Rogue() 
{
    this->baseHP = 10;
    this->baseDamage = 15;
    this->basePhysicalResist = 3;
    this->baseMagicResist = 1;
    this->className = "Rogue";
    this->firstSpell = new BackStab();
    this->secondSpell = new PickPocket();
    this->thirdSpell = new CutThroat();
}

Rogue::~Rogue() 
{
    delete firstSpell;
    delete secondSpell;
    delete thirdSpell;
}