#include "../header/game.h"
#include <limits>
using std::cin;


Game::Game()
{
    isRunning = true;
    currentUser = new User();
    currentScreen = new StartMenu("startMenu.txt", currentUser);
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
        currentScreen->displayScreen();
        cin >> userInput;
        if(cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            userInput = 0;
        }
        currentScreen = currentScreen->processOption(userInput, this->isRunning);
        if(currentScreen != previousScreen){
            delete previousScreen;
            previousScreen = currentScreen;
        }
    }
}