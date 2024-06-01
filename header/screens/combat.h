#pragma once
#include <string>
#include <iostream>
#include "./screen.h"
#include "./startMenu.h"
#include "./travel.h"
#include "../enemy.h"
#include "../orc.h"
#include "../orcBoss.h"
#include "../pirate.h"
#include "../pirateBoss.h"
#include "../royalGuard.h"
#include "../finalBoss.h"
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
        string getEnemyLastMoveStr() const;
        string getUserLastMoveStr() const;
        string getRewardsStr() const;
        void displayScreen();
};