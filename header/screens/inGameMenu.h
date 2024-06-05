#pragma once
#include <string>
#include <iostream>
#include "./screen.h"
#include "./travel.h"
#include "./inventory.h"
#include "./startMenu.h"
using std::string;
using std::cout;
using std::endl;

class InGameMenu: public Screen{
    public:
        InGameMenu(string dispFile, User* user);
        Screen* processOption(int, bool);
        void displayScreen();
};