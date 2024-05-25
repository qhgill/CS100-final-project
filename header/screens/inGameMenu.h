#pragma once
#include <string>
#include "./screen.h"

class InGameMenu: public Screen{
    public:
        InGameMenu(std::string dispFile, User* user): Screen(dispFile, user) {}
        Screen* processOption(int, bool){return this;}
        void displayScreen(){}
};