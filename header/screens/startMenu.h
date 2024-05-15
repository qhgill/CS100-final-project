#pragma once
#include "./screen.h"
#include <string>

class StartMenu: public Screen{
    public:
        Screen* processOption(int);
        void displayScreen();
};