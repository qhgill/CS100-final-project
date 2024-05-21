#pragma once
#include "./screen.h"
#include <string>

class InGameMenu: public Screen{
    public:
        InGameMenu(string dispFile, User* user): Screen(dispFile, user){}
        Screen* processOption(int);
        void displayScreen();
        Screen* processOption(int option, bool isRunning);
};