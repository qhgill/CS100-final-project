#pragma once
#include "./screen.h"
#include <string>
#include <iostream>

class City: public Screen
{
    protected:
        bool tavernUsed;
        Weapon* cityWeapon;
        Trinket* cityTrinket;
        Armor* cityArmor;
    public:
        City(string dispFile, User* cUser);
        void displayScreen() override;
        Screen* processOption(int choice, bool isRunning) override;
        Weapon* getCityWeapon();
        Armor* getCityArmor();
        Trinket* getCityTrinket();
        bool getTavernUsed();
};