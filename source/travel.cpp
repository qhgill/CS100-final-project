#include "../header/screens/travel.h"
using std::cout;
using std::endl;

Travel::Travel(string dispFile, User* user): Screen(dispFile,user){}

void Travel::displayScreen(){
    Screen::displayFromFile();
    cout << "--------------------------------" << endl;
    cout << "Select an option: " << endl;
    cout << "[1] continue to next encounter" << endl;
    cout << "[2] open menu" << endl;
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