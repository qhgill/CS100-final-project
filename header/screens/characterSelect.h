#pragma once
#include "./screen.h"
#include <string>

class CharacaterSelect: public Screen{
    public:
        Screen* processOption(int);
        void displayScreen();
};