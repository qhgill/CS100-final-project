#include "../header/screens/screen.h"
using std::cout;
using std::endl;

City::City(std::string dispFile, User* cUser): Screen(dispFile, cUser), tavernUsed(false), cityArmor(new Armor()), cityTrinket(new Trinket()), cityWeapon(new Weapon()){
    currentUser->getEncounterManager()->resetEncounterCount();
    currentUser->incrementStoryAct();
}
City::~City(){
    if(cityArmor != nullptr){
        delete cityArmor;
    }
    if(cityWeapon != nullptr){
        delete cityWeapon;
    }
    if(cityTrinket != nullptr){
        delete cityTrinket;
    }
}
Screen* City::processOption(int userOption, bool& isRunning)
{ 
    if(userOption == 1){
        if(tavernUsed == false){
            tavernUsed = true;
            currentUser->getStatsManager()->getCurrentHP() = currentUser->getStatsManager()->getMaxHP();
        }
        return this;
    } else if(userOption == 2 && currentUser->getGold() - cityWeapon->calcValue() < 0){
        if(cityWeapon == nullptr){
            return this;
        } else {
            currentUser->getGold() -= cityWeapon->calcValue();
            currentUser->getItemManager()->getWeaponInventory()->push_back(cityWeapon);
            cityWeapon = nullptr;
            return this;
        }
    } else if(userOption == 3 && currentUser->getGold() - cityArmor->calcValue() < 0){
        if(cityArmor == nullptr){
            return this;
        } else {
            currentUser->getGold() -= cityArmor->calcValue();
            currentUser->getItemManager()->getArmorInventory()->push_back(cityArmor);
            cityArmor = nullptr;
            return this;
        }
    } else if(userOption == 4 && currentUser->getGold() - cityTrinket->calcValue() < 0){
        if(cityTrinket == nullptr){
            return this;
        } else {
            currentUser->getGold() -= cityTrinket->calcValue();
            currentUser->getItemManager()->getTrinketInventory()->push_back(cityTrinket);
            cityTrinket = nullptr;
            return this;
        }
    } else if(userOption == 5){
        ItemManager* userItemManager = currentUser->getItemManager();
        std::vector<Weapon*>* userWeapons = userItemManager->getWeaponInventory();
        std::vector<Armor*>* userArmor = userItemManager->getArmorInventory();
        std::vector<Weapon*>* userTrinkets = userItemManager->getWeaponInventory();
        if(userItemManager->getWeaponInventory()->size() == 0 && userItemManager->getArmorInventory()->size() == 0 && userItemManager->getTrinketInventory()->size() == 0){
            return this;
        } else {
            for(int i = userWeapons->size() - 1; i >= 0; i--){
                currentUser->getGold() += userWeapons->at(i)->calcValue();
                delete userWeapons->at(i);
                userWeapons->pop_back();
            }
            for(int i = userArmor->size() - 1; i >= 0; i--){
                currentUser->getGold() += userArmor->at(i)->calcValue();
                delete userWeapons->at(i);
                userArmor->pop_back();
            }
            for(int i = userTrinkets->size() - 1; i >= 0; i--){
                currentUser->getGold() += userTrinkets->at(i)->calcValue();
                delete userTrinkets->at(i);
                userTrinkets->pop_back();
            }
            return this;
        }
    } else if(userOption == 6){
        Screen* travelScreen = new Travel("travelScreen.txt", currentUser);
        return travelScreen;
    } else {
        return this;
    }
}

void City::displayScreen()
{
    Screen::displayFromFile();
    cout << "------------------------" << endl;
    cout << "select an option:" << endl;
    cout << "[1] Rest in tavern(restore your HP)";
    if(tavernUsed == true){
        cout << " (USED)";
    }
    cout << endl;
    cout << "[2] purchase City's weapon";
    if(cityWeapon == nullptr){
        cout << " (ALREADY PURCHASED)";
    } else if (currentUser->getGold() - cityWeapon->calcValue() < 0){
        cout << " (NOT ENOUGH GOLD)";
    }
    cout << endl;
    cout << "[3] purchase City's armor";
    if(cityArmor == nullptr){
        cout << " (ALREADY PURCHASED)";
    } else if (currentUser->getGold() - cityArmor->calcValue() < 0){
        cout << " (NOT ENOUGH GOLD)";
    }
    cout << endl;
    cout << "[4] purchase City's trinket";
    if(cityTrinket == nullptr){
        cout << " (ALREADY PURCHASED)";
    } else if (currentUser->getGold() - cityTrinket->calcValue() < 0){
        cout << " (NOT ENOUGH GOLD)";
    }
    cout << endl;
    cout << "[5] sell all uneqipped items in your inventory";
    ItemManager* userItemManager = currentUser->getItemManager();
    if(userItemManager->getWeaponInventory()->size() == 0 && userItemManager->getArmorInventory()->size() == 0 && userItemManager->getTrinketInventory()->size() == 0){
        cout << "(NO ITEMS TO SELL)";
    } 
    cout << endl;
    cout << "[6] leave city" << endl;
}

Weapon* City::getCityWeapon(){
    return cityWeapon;
}

Armor* City::getCityArmor(){
    return cityArmor;
}

Trinket* City::getCityTrinket(){
    return cityTrinket;
}

bool City::getTavernUsed(){
    return tavernUsed;
}