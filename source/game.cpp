#include "../header/game.h"

Game::Game()
{
    isRunning = true;
    currentUser = new User();
    currentScreen = new StartMenu("", currentUser);
    previousScreen = currentScreen;
}
Game::~Game(){
    delete currentUser;
    if(previousScreen != currentScreen){
        delete currentScreen;
        delete previousScreen;
    } else {
        delete currentScreen;
    }
}
void Game::runGame(){
    int userInput;
    while(isRunning){
        currentScreen->displayScreen();
        std::cin >> userInput;
        if(!std::cin.good()){
            userInput = 0;
        }
        currentScreen = currentScreen->processOption(userInput, this->isRunning);
        if(currentScreen != previousScreen){
            delete previousScreen;
            previousScreen = currentScreen;
        }
        std::cin.clear();
    }
}