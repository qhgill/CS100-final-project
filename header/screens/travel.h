#pragma once
#include "./screen.h"
#include <string>

class Travel: public Screen{
    public:
        Screen* processOption(int);
        void displayScreen();
};