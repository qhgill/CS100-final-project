#pragma once
#include <string>
#include <iostream>
#include "./screen.h"
#include "./startMenu.h"
#include "./travel.h"
#include "../enemy.h"
using std::string;

class Combat: public Screen{
    private:
        bool isBossFight;
        bool inCombat;
        Enemy* enemy;
        string enemyLastMoveStr;
        string userLastMoveStr;
        string rewardsStr;
    public:
        Combat(string dispFile, User* cUser);
        ~Combat();
        Combat(Combat&) = delete;
        Combat operator=(Combat&) = delete;
        Screen* processOption(int, bool);
        void displayScreen();
};