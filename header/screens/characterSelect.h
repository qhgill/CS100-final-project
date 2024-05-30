#pragma once
#include <string>
#include "./screen.h"
#include "../character.h"
#include "../warrior.h"
#include "../mage.h"
#include "../rogue.h"
#include "./inGameMenu.h"
using std::string;
using std::cout;
using std::endl;

class CharacterSelect: public Screen{
    public:
        CharacterSelect(string dispFile, User* cUser);
        Screen* processOption(int, bool);
        void displayScreen();
};