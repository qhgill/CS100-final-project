#pragma once
#include <string>
#include "./screen.h"

class Combat: public Screen{
    public:
        Screen* processOption(int);
        void displayScreen();
};