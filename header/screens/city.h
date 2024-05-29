#pragma once
#include <iostream>
#include <string>
#include "./screen.h"

class City: public Screen
{
    protected:
        bool tavernUsed;
        Weapon* cityWeapon;
        Trinket* cityTrinket;
        Armor* cityArmor;
    public:
        City(std::string dispFile, User* cUser);
        void displayScreen() override;
        Screen* processOption(int choice, bool isRunning) override;
        Weapon* getCityWeapon();
        Armor* getCityArmor();
        Trinket* getCityTrinket();
        bool getTavernUsed();
};