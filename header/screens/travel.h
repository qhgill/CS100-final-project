#pragma once
#include "./screen.h"
#include "./inGameMenu.h"
#include <iostream>
#include <string>

class Travel: public Screen{
    public:
        Travel(string dispFile, User* user);
        Screen* processOption(int, bool);
        void displayScreen();
};