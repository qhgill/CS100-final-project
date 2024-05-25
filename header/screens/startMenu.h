#pragma once
#include <string>
#include "./screen.h"

class StartMenu: public Screen{
    public:
        StartMenu(std::string dispFile, User* cUser): Screen(dispFile, cUser){}
        Screen* processOption(int option, bool isRunning) override;
        void displayScreen() override;
};