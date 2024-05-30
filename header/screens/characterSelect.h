#pragma once
#include <string>
#include "./screen.h"

class CharacterSelect: public Screen{
    public:
        CharacterSelect(std::string dispFile, User* user): Screen(dispFile, user){}
        Screen* processOption(int, bool) override {return this;}
        void displayScreen() override{}
};