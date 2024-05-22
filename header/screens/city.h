#pragma once
#include "./screen.h"
#include <string>
#include <iostream>

class City: public Screen
{
    protected:
        bool tavernUsed;
        Item* cityWeapon;
        Item* cityTrinket;
        Item* cityArmor;
    public:
        City(string dispFile, User* cUser);
        void displayScreen() override;
        Screen* processOption(int choice, bool isRunning) override;
};