#pragma once
#include <string>
#include "character.h"

class Mage : public Character {
    public:
        Mage();
        Mage(int, int, int, int, std::string, Spell*, Spell*, Spell*);
};