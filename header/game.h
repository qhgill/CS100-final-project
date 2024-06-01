#pragma once
#include <iostream>
#include "user.h"
#include "screens/screen.h"

class Game 
{
    private:
        User* currentUser;
        Screen* currentScreen;
        Screen* previousScreen;
        bool isRunning;
    public:
        Game();
        ~Game();
        Game(Game&) = delete;
        Game operator=(Game&) = delete;
        void runGame();
};