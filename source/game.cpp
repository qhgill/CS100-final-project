#include "../header/game.h"
using std::cin;

Game::Game(): isRunning(true){
    currentUser = new User();
    currentScreen = new StartMenu("", currentUser);
    previousScreen = currentScreen;
}
void Game::runGame(){
    int userInput;
    while(isRunning){
        currentScreen->displayScreen();
        cin >> userInput;
        currentScreen = currentScreen->processOption(userInput);
        if(currentScreen != previousScreen){
            delete previousScreen;
            previousScreen = currentScreen;
        }
    }
}