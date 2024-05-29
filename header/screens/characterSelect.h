#pragma once
#include <string>
#include "./screen.h"
using std::string;

class CharacterSelect: public Screen{
    public:
        CharacterSelect(string dispFile, User* cUser);
        Screen* processOption(int, bool);
        void displayScreen();
};