#pragma once
#include <string>
#include "character.h"

class Warrior : public Character 
{
    public:
        Warrior();
        Warrior(int, int, int, int, std::string, Spell*, Spell*, Spell*);    
};