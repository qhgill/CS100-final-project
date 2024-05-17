#pragma once
#include "./screen.h"
#include <string>

class InGameMenu: public Screen{
    public:
        Screen* processOption(int);
        void displayScreen();
};