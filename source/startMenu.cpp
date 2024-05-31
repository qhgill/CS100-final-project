#include "../header/screens/startMenu.h"

void StartMenu::displayScreen()
{
    Screen::displayFromFile();
    std::cout << "You must rise to the occasion. \n You must complete all challenges. \n So that you may take your rightful place on the throne. \n Welcome to the Game!\n";
    std::cout << "1. Start Game\n";
    std::cout << "2. Exit\n";
}

Screen* StartMenu::processOption(int option, bool isRunning)
{
    if (option == 2){
        isRunning = false;
        return this;
    } else if (option == 1){
        return new CharacterSelect("characterSelectScreen.txt", currentUser);
    } else {
        return this;  
    }
    
    
}