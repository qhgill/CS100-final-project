#pragma once
#include <string>
#include <iostream>
#include "./screen.h"
#include "./inGameMenu.h"

class Inventory: public Screen
{
    protected:
    public:
        Inventory(std::string dispFile, User* cUser);
        void displayScreen() override;
        Screen* processOption(int option, bool isRunning) override;
};