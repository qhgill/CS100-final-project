#pragma once
#include "./screen.h"
#include <string>

class City: public Screen{
    public:
        City(string dispFile, User* cUser);
        Screen* processOption(int);
        void displayScreen();
};