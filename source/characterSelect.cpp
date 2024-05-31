#include "../header/screens/characterSelect.h"

CharacterSelect::CharacterSelect(string dispFile, User* cUser): Screen(dispFile, cUser){}

void CharacterSelect::displayScreen(){
    Screen::displayFromFile();
    cout << "Select an option: " << endl;
    cout << "[1] Warrior" << endl;
    cout << "[2] Mage" << endl;
    cout << "[3] Rogue" << endl;
}

Screen* CharacterSelect::processOption(int option, bool isrunning){
    if(option == 1){
        currentUser->getCharacterClass() = new Warrior();
    } else if(option == 2){
        currentUser->getCharacterClass() = new Mage();
    } else if(option == 3){
        currentUser->getCharacterClass() = new Rogue();
    } else {
        return this;
    }
    Character* userCharacter = currentUser->getCharacterClass();
    currentUser->getStatsManager()->updateStats(userCharacter->getBaseDamage(), userCharacter->getBaseHP(), userCharacter->getBaseMagicResist(), userCharacter->getBasePhysicalResist(), currentUser->getItemManager()->getEquippedWeapon(), currentUser->getItemManager()->getEquippedArmor(), currentUser->getItemManager()->getEquippedTrinket(), currentUser->getLevel());
    return new InGameMenu("gameMenuScreen.txt", currentUser);
}