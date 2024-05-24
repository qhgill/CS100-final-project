#pragma once
#include "./screen.h"
#include "../header/screens/characterSelect.h"
#include <string>

class StartMenu: public Screen{
    public:
        StartMenu(string dispFile, User* cUser): Screen(dispFile, cUser){}
        Screen* processOption(int option, bool isRunning) override;
        void displayScreen() override;
};