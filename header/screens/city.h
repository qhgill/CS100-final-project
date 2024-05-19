#pragma once
#include "./screen.h"
#include <string>

class City: public Screen
{
    protected:
        bool tavernUsed;
        std::vector<Item*> tavernStock;
    public:
        City(string dispFile, User* cUser);
        void displayPurchasableOptions();
        void displayScreen() override;
        Screen* processOption(int choice, bool isRunning) override;
};