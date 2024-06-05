#include "../header/screens/screen.h"

InGameMenu::InGameMenu(string dispFile, User* user):Screen(dispFile, user){}

void InGameMenu::displayScreen(){
    Screen::displayFromFile();
    cout << "Select an option" << endl;
    cout << "[1] play game" << endl;
    cout << "[2] open inventory" << endl;
    cout << "[3] return to main menu" << endl;
}

Screen* InGameMenu::processOption(int choice, bool& isRunning){
    if(choice == 1){
        return new Travel("travelScreen.txt", currentUser);
    } else if(choice == 2){
        return new Inventory("inventoryScreen.txt", currentUser);
    } else if(choice == 3){
        return new StartMenu("startMenu.txt", currentUser);
    } else {
        return this;
    }
}

