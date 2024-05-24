#pragma once
#include "./screen.h"
#include <string>

class CharacterSelect: public Screen{
    public:
        CharacterSelect(string dispFile, User* user): Screen(dispFile, user){}
        Screen* processOption(int, bool) override {return this;}
        void displayScreen() override{}
};