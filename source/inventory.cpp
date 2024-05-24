#include "../header/screens/inventory.h"
using std::cout;
using std::endl;

Inventory::Inventory(string dispFile, User* cUser): Screen(dispFile, cUser){}

void Inventory::displayScreen(){
    StatsManager* userStatsManager = currentUser->getStatsManager();
    ItemManager* userItemManager = currentUser->getItemManager();
    vector<Armor*>* userArmorInventory = userItemManager->getArmorInventory();
    vector<Weapon*>* userWeaponInventory = userItemManager->getWeaponInventory();
    vector<Trinket*>* userTrinketInventory = userItemManager->getTrinketInventory();
    
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
    cout << "Inventory: " << endl;
    cout << "Weapons: ";
    if(userWeaponInventory->size() == 0){
        cout << "empty" << endl;
    } else {
        for(unsigned i = 0; i < userItemManager->getArmorInventory()->size() - 1; i++){
            cout << userWeaponInventory->at(i)->getName() << ", ";
        }
        cout << userWeaponInventory->at(userWeaponInventory->size()-1)->getName() << endl;
    }
    cout << "Armor: ";
    if(userArmorInventory->size() == 0){
        cout << "empty" << endl;
    } else {
        for(unsigned i = 0; i < userArmorInventory->size() - 1; i++){
            cout << userArmorInventory->at(i)->getName() << ", ";
        }
        cout << userArmorInventory->at(userArmorInventory->size()-1)->getName() << endl;
    }
    cout << "Trinkets: ";
    if(userTrinketInventory->size() == 0){
        cout << "empty" << endl;
    } else {
        for(unsigned i = 0; i < userTrinketInventory->size() - 1; i++){
            cout << userTrinketInventory->at(i)->getName() << ", ";
        }
        cout << userTrinketInventory->at(userTrinketInventory->size()-1)->getName() << endl;
    }
    cout << "-------------------------------------------" << endl;
    cout << "Select an option:" << endl;
    cout << "[1] Equip a different Weapon" << endl;
    cout << "[2] Equip a different Armor" << endl;
    cout << "[3] Equip a different Trinket" << endl;
    cout << "[4] back to menu" << endl << endl;
}

Screen* Inventory::processOption(int option, bool isRunning){
    ItemManager* userItemManager = currentUser->getItemManager();
    vector<Weapon*>* userWeaponInventory = userItemManager->getWeaponInventory();
    vector<Armor*>* userArmorInventory = userItemManager->getArmorInventory();
    vector<Trinket*>* userTrinketInventory = userItemManager->getTrinketInventory();
    if(option == 1){
        if(userWeaponInventory->size() == 0){
            return this;
        } else {
            Weapon* oldWeapon = userItemManager->getEquippedWeapon();
            userItemManager->getEquippedWeapon() = userWeaponInventory->at(0);
            userWeaponInventory->erase(userWeaponInventory->begin());
            userWeaponInventory->push_back(oldWeapon);
        }
        return this;
    } else if(option == 2){
        if(userArmorInventory->size() == 0){
            return this;
        } else {
            Armor* oldArmor = userItemManager->getEquippedArmor();
            userItemManager->getEquippedArmor() = userArmorInventory->at(0);
            userArmorInventory->erase(userArmorInventory->begin());
            userArmorInventory->push_back(oldArmor);
        }
        return this;
    } else if(option == 3){
        if(userTrinketInventory->size() == 0){
            return this;
        } else {
            Trinket* oldTrinket = userItemManager->getEquippedTrinket();
            userItemManager->getEquippedTrinket() = userTrinketInventory->at(0);
            userTrinketInventory->erase(userTrinketInventory->begin());
            userTrinketInventory->push_back(oldTrinket);
        }
        return this;
    } else if(option == 4){
        Screen* menuScreen = new InGameMenu("gameMenuScreen.txt", currentUser);
        return menuScreen;
    } else {
        return this;
    }
}