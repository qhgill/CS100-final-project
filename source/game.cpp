#include "../header/game.h"

Game::Game()
{
    isRunning = true;
    currentUser = new User();
    currentScreen = new StartMenu("", currentUser);
    previousScreen = currentScreen;
}
void Game::runGame(){
    int userInput;
    while(isRunning){
        currentScreen->displayScreen();
        std::cin >> userInput;
        currentScreen = currentScreen->processOption(userInput, this->isRunning);
        if(currentScreen != previousScreen){
            delete previousScreen;
            previousScreen = currentScreen;
        }
    }
}