#pragma once
#include <iostream>
#include "user.h"
#include "screens/screen.h"
#include "screens/startMenu.h"

class Game 
{
    private:
        User* currentUser;
        Screen* currentScreen;
        Screen* previousScreen;
        bool isRunning;
    public:
        Game();
        void runGame();
};