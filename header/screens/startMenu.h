#pragma once
#include "./screen.h"
#include <string>

class StartMenu: public Screen{
    public:
        StartMenu(string dispFile, User* cUser): Screen(dispFile, cUser){}
        Screen* processOption(int);
        void displayScreen();
};