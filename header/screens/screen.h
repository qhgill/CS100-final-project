#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "../user.h"
#include "../character.h"
#include "../warrior.h"
#include "../mage.h"
#include "../rogue.h"
#include "../enemy.h"
#include "../orc.h"
#include "../orcBoss.h"
#include "../pirate.h"
#include "../pirateBoss.h"
#include "../royalGuard.h"
#include "../finalBoss.h"

using std::string;
using std::cout;
using std::endl;

class Screen {
    protected:
        std::string filename;
        User* currentUser;
    public:
        Screen(std::string dispFile, User* user);
        void displayFromFile();
        virtual Screen* processOption(int option, bool& isRunning) = 0;
        virtual void displayScreen() = 0;
};

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
        Screen* processOption(int choice, bool& isRunning) override;
        Weapon* getCityWeapon();
        Armor* getCityArmor();
        Trinket* getCityTrinket();
        bool getTavernUsed();
};

class StartMenu: public Screen{
    public:
        StartMenu(std::string dispFile, User* cUser): Screen(dispFile, cUser){}
        Screen* processOption(int option, bool& isRunning) override;
        void displayScreen() override;
};

class Travel: public Screen{
    public:
        Travel(std::string dispFile, User* user);
        Screen* processOption(int, bool&);
        void displayScreen();
};

class InGameMenu: public Screen{
    public:
        InGameMenu(string dispFile, User* user);
        Screen* processOption(int, bool&);
        void displayScreen();
};

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
        Screen* processOption(int, bool&);
        string getEnemyLastMoveStr() const;
        string getUserLastMoveStr() const;
        string getRewardsStr() const;
        void displayScreen();
};

class CharacterSelect: public Screen{
    public:
        CharacterSelect(string dispFile, User* cUser);
        Screen* processOption(int, bool&);
        void displayScreen();
};

class Inventory: public Screen
{
    protected:
    public:
        Inventory(std::string dispFile, User* cUser);
        void displayScreen() override;
        Screen* processOption(int option, bool& isRunning) override;
};