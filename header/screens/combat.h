#pragma once
#include "./screen.h"
#include <string>

class Combat: public Screen{
    public:
        Screen* processOption(int);
        void displayScreen();
};