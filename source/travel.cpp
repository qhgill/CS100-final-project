#include "../header/screens/screen.h"

Travel::Travel(std::string dispFile, User* user): Screen(dispFile,user){}

void Travel::displayScreen(){
    Screen::displayFromFile();
    std::cout << "--------------------------------" << std::endl;
    if(currentUser->getStoryAct() == 1 && currentUser->getEncounterManager()->getEncounterCount() == 0){
        cout << "You've been gvien a quest to fight enemies! good luck on your journey!" << endl;
    }
    std::cout << "Select an option: " << std::endl;
    std::cout << "[1] continue to next encounter" << std::endl;
    std::cout << "[2] open menu" << std::endl;
}

Screen* Travel::processOption(int option, bool& isRunning){
    if(option == 1){
        Screen* nextCombat = new Combat("combatScreen.txt", currentUser);
        return nextCombat;
    } else if(option == 2){
        Screen* menuScreen = new InGameMenu("gameMenuScreen.txt", currentUser);
        return menuScreen;
    } else {
        return this;
    }
}