#pragma once
#include <string>
#include "./screen.h"

class CharacterSelect: public Screen{
    public:
        Screen* processOption(int);
        void displayScreen();
};