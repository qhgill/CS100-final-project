#include "../header/screens/city.h"
#include "../header/screens/travel.h"
using std::cout;
using std::endl;

City::City(string dispFile, User* cUser): Screen(dispFile, cUser), tavernUsed(false){}

Screen* City::processOption(int userOption, bool isRunning)
{ 
    if(userOption == 1){
        if(tavernUsed == false){
            tavernUsed = true;
            currentUser->getStatsManager()->getCurrentHP() = currentUser->getStatsManager()->getMaxHP();
        }
        return this;
    } else if(userOption == 2){
        if(cityWeapon == nullptr){
            return this;
        } else {
            //fix when inventorymanager gets pushed
            return this;
        }
    } else if(userOption == 3){
        if(cityArmor == nullptr){
            return this;
        } else {
            //fix when inventorymanager gets pushed
            return this;
        }
    } else if(userOption == 4){
        if(cityTrinket == nullptr){
            return this;
        } else {
            //fix when inventorymanager gets pushed
            return this;
        }
    } else if(userOption == 5){
        if(currentUser->getInventory()->size() == 0){
            return this;
        } else {
            //fix when inventorymanager gets pushed
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
    }
    cout << endl;
    cout << "[3] purchase City's armor";
    if(cityArmor == nullptr){
        cout << " (ALREADY PURCHASED)";
    }
    cout << endl;
    cout << "[4] purchase City's trinket";
    if(cityTrinket == nullptr){
        cout << " (ALREADY PURCHASED)";
    }
    cout << endl;
    cout << "[5] sell all uneqipped items in your inventory" << endl;
    cout << "[6] leave city" << endl;
}