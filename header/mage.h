#pragma once
#include <string>
#include "character.h"
#include "./lifeleech.h"
#include "./incinerate.h"
#include "./arcaneBlast.h"

class Mage : public Character 
{
    public:
        Mage();
        Mage(int, int, int, int, std::string, Spell*, Spell*, Spell*);
};