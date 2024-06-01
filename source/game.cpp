#include "../header/game.h"
using std::cin;


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
    while(isRunning){
        int userInput;
        cin.clear();
        currentScreen->displayScreen();
        cin >> userInput;
        cin.ignore();
        if(!cin.good()){
            userInput = 0;
            cin.ignore(100000000000);
            cin.clear();
        }
        currentScreen = currentScreen->processOption(userInput, this->isRunning);
        if(currentScreen != previousScreen){
            delete previousScreen;
            previousScreen = currentScreen;
        }
    }
}