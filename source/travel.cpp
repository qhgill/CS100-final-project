#include "../header/screens/travel.h"

Travel::Travel(std::string dispFile, User* user): Screen(dispFile,user){}

void Travel::displayScreen(){
    Screen::displayFromFile();
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Select an option: " << std::endl;
    std::cout << "[1] continue to next encounter" << std::endl;
    std::cout << "[2] open menu" << std::endl;
}

Screen* Travel::processOption(int option, bool isRunning){
    if(option == 1){
        // Screen* nextCombat = new Combat();
        // return nextCombat;
        return this;
    } else if(option == 2){
        Screen* menuScreen = new InGameMenu("gameMenuScreen.txt", currentUser);
        return menuScreen;
    } else {
        return this;
    }
}