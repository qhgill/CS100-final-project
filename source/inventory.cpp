#include "../header/screens/inventory.h"
using std::cout;
using std::endl;

Inventory::Inventory(string dispFile, User* cUser): Screen(dispFile, cUser){}

void Inventory::displayScreen(){
    StatsManager* userStatsManager = currentUser->getStatsManager();
    ItemManager* userItemManager = currentUser->getItemManager();
    //vector<Item*>* userInventory = userItemManager->getInventory();
    Screen::displayFromFile();
    cout << endl;
    cout << "Level: " << currentUser->getLevel() << endl;
    cout << "xp: " << currentUser->getXp() << endl;
    cout << "current HP: " << userStatsManager->getCurrentHP() << "/" << userStatsManager->getMaxHP() << endl;
    cout << "Magic Resist: " << userStatsManager->getCurrentMR() << endl;
    cout << "Physical Resist: " << userStatsManager->getCurrentPR() << endl;
    cout << "Damage: " << userStatsManager->getCurrentDMG() << endl;
    cout << endl << "Equipment:" << endl;
    cout << "Equipped Weapon: " << userItemManager->getEquippedWeapon()->getName() << endl;
    cout << "Equipped Armor: " << userItemManager->getEquippedArmor()->getName() << endl;
    cout << "Equipped Trinket: " << userItemManager->getEquippedTrinket()->getName() << endl;
    cout << "Inventory: ";
    // if(userInventory->size() == 0){
    //     cout << "empty" << endl;
    // } else {
    //     for(unsigned i = 0; i < userInventory->size() - 1; i++){
    //         cout << userInventory->at(i)->getName() << ", ";
    //     }
    //     cout << userInventory->at(userInventory->size()-1)->getName() << endl;
    // }
    cout << "-------------------------------------------" << endl;
    cout << "Select an option:" << endl;
    cout << "[1] Equip a different Weapon" << endl;
    cout << "[2] Equip a different Armor" << endl;
    cout << "[3] Equip a different Trinket" << endl;
    cout << "[4] back to menu" << endl << endl;
}

Screen* Inventory::processOption(int option, bool isRunning){
    ItemManager* userItemManager = currentUser->getItemManager();
    //vector<Item*>* userInventory = userItemManager->getInventory();
    if(option == 1){
        // Item* userEquippedWeapon = userItemManager->getEquippedWeapon();
        // if(userInventory->size() != 0){
        //     int i = 0;
        //     while(i < userInventory->size() && userInventory->at(i)->getType() != "weapon"){
        //         i++;
        //     }
        //     if(i >= userInventory->size()){
        //         return this;
        //     } else {
        //         Item* userOldWeapon = userEquippedWeapon;
        //         currentUser->getItemManager()->getEquippedWeapon() = userInventory->at(i);
        //         userInventory->erase(userInventory->begin() + i - 1);
        //         userInventory->push_back(userOldWeapon);
        //     }
        // }
        return this;
    } else if(option == 2){
        // Item* userEquippedArmor = userItemManager->getEquippedArmor();
        // if(userInventory->size() != 0){
        //     int i = 0;
        //     while(i < userInventory->size() && userInventory->at(i)->getType() != "armor"){
        //         i++;
        //     }
        //     if(i >= userInventory->size()){
        //         return this;
        //     } else {
        //         Item* userOldArmor = userEquippedArmor;
        //         userEquippedArmor = userInventory->at(i);
        //         userInventory->erase(userInventory->begin() + i - 1);
        //         userInventory->push_back(userOldArmor);
        //     }
        // }
        return this;
    } else if(option == 3){
        // Item* userEquippedTrinket = userItemManager->getEquippedTrinket();
        // if(userInventory->size() != 0){
        //     int i = 0;
        //     while(i < userInventory->size() && userInventory->at(i)->getType() != "trinket"){
        //         i++;
        //     }
        //     if(i >= userInventory->size()){
        //         return this;
        //     } else {
        //         Item* userOldTrinket = userEquippedTrinket;
        //         userEquippedTrinket = userInventory->at(i);
        //         userInventory->erase(userInventory->begin() + i - 1);
        //         userInventory->push_back(userOldTrinket);
        //     }
        // }
        return this;
    } else if(option == 4){
        Screen* menuScreen = new InGameMenu("gameMenuScreen.txt", currentUser);
        return menuScreen;
    } else {
        return this;
    }
}