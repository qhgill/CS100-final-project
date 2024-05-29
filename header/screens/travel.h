#pragma once
#include <iostream>
#include <string>
#include "./screen.h"
#include "./inGameMenu.h"

class Travel: public Screen{
    public:
        Travel(std::string dispFile, User* user);
        Screen* processOption(int, bool);
        void displayScreen();
};