#pragma once
#include <iostream>
#include <string>
#include "./screen.h"
#include "./travel.h"

class City: public Screen
{
    protected:
        bool tavernUsed;
        Weapon* cityWeapon;
        Trinket* cityTrinket;
        Armor* cityArmor;
    public:
        City(std::string dispFile, User* cUser);
        ~City();
        City(City&) = delete;
        City operator=(City&) = delete;
        void displayScreen() override;
        Screen* processOption(int choice, bool &isRunning) override;
        Weapon* getCityWeapon();
        Armor* getCityArmor();
        Trinket* getCityTrinket();
        bool getTavernUsed();
};