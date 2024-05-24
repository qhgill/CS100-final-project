#pragma once
#include "./screen.h"
#include "./inGameMenu.h"
#include <string>
#include <iostream>

class Inventory: public Screen
{
    protected:
    public:
        Inventory(string dispFile, User* cUser);
        void displayScreen() override;
        Screen* processOption(int option, bool isRunning) override;
};