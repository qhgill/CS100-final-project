#include "../header/screens/inventory.h"
using std::cout;
using std::endl;

Inventory::Inventory(string dispFile, User* cUser): Screen(dispFile, cUser){}

void Inventory::displayScreen(){
    StatsManager* userStatsManager = currentUser->getStatsManager();
    vector<Item*>* userInventory = currentUser->getInventory();
    Screen::displayFromFile();
    cout << endl;
    cout << "Level: " << currentUser->getLevel() << endl;
    cout << "xp: " << currentUser->getXp() << endl;
    cout << "current HP: " << userStatsManager->getCurrentHP() << "/" << userStatsManager->getMaxHP() << endl;
    cout << "Magic Resist: " << userStatsManager->getCurrentMR() << endl;
    cout << "Physical Resist: " << userStatsManager->getCurrentPR() << endl;
    cout << "Damage: " << userStatsManager->getCurrentDMG() << endl;
    cout << endl << "Equipment:" << endl;
    cout << "Equipped Weapon: NEEDS FIX" << endl;
    cout << "Equipped Armor: NEEDS FIX" << endl;
    cout << "Equipped Trinket: NEEDS FIX" << endl;
    cout << "Inventory: ";
    for(unsigned i = 0; i < userInventory->size() - 1; i++){
        cout << userInventory->at(i)->getName() << ", ";
    }
    cout << userInventory->at(userInventory->size()-1)->getName() << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Select an option:" << endl;
    cout << "[1] Equip a different Weapon" << endl;
    cout << "[2] Equip a different Armor" << endl;
    cout << "[3] Equip a different Trinket" << endl;
    cout << "[4] back to menu" << endl << endl;
}

Screen* Inventory::processOption(int option, bool isRunning){
    vector<Item*>* userInventory = currentUser->getInventory();
    if(option == 1){
        //need to update inventory interface for this to work
        return this;
    } else if(option == 2){
        //"
        return this;
    } else if(option == 3){
        //"
        return this;
    } else if(option == 4){
        Screen* menuScreen = new InGameMenu(filename, currentUser);
        return menuScreen;
    } else {
        return this;
    }
}