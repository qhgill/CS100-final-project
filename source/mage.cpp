#include "../header/mage.h"

Mage::Mage() 
{
    this->baseHP = 7;
    this->baseDamage = 12;
    this->basePhysicalResist = 5;
    this->baseMagicResist = 5;
    this->className = "Mage";
    this->firstSpell = new ArcaneBlast();
    this->secondSpell = new LifeLeech();
    this->thirdSpell = new Incinerate();
}

Mage::~Mage() 
{}