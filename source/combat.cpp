#include "../header/screens/combat.h"
using std::cout;
using std::endl;

Combat::Combat(string dispFile, User* cUser)
: Screen(dispFile, cUser), inCombat(true), enemyLastMoveStr("Enemy hasn't made a move yet"), userLastMoveStr("You haven't made a move yet"){
    isBossFight = (currentUser->getEncounterManager()->getEncounterCount() == 10);
    //enemy = new goblin;  need to update this when enemy subclasses are introduced
}

Combat::~Combat(){
    delete enemy;
}

void Combat::displayScreen(){
    Screen::displayFromFile();
    cout << "you have entered a fight with a level" << enemy->getLevel() << " " << enemy->getName() << "!";
    if(isBossFight){
        cout << " This is a bossfight!";
    }
    cout << endl;
    cout << "Enemy HP: " << enemy->getHealth() << "/" << enemy->getMaxHealth() << endl;
    cout << "Enemy's last move: " << enemyLastMoveStr << endl;
    cout << "Your last move: " << userLastMoveStr << endl;
    if(inCombat){
        cout << "select an option:" << endl;
        cout << "[1] Use your weapon" << endl;
        cout << "[2] Use your first spell";
        if(currentUser->getLevel() < currentUser->getCharacterClass()->getFirstSpell()->getSpellLevelThreshold()){
            cout << "(LEVEL NOT HIGH ENOUGH)";
        }
        cout << endl;
        cout << "[3] Use your second spell";
        if(currentUser->getLevel() < currentUser->getCharacterClass()->getSecondSpell()->getSpellLevelThreshold()){
            cout << "(LEVEL NOT HIGH ENOUGH)";
        }
        cout << endl;
        cout << "[4] Use your third spell";
        if(currentUser->getLevel() < currentUser->getCharacterClass()->getThirdSpell()->getSpellLevelThreshold()){
            cout << "(LEVEL NOT HIGH ENOUGH)";
        }
        cout << endl;
        cout << "[5] flee" << endl;
    } else {
        if(!enemy->getStatus()){
            cout << "You died! press any key to continue" << endl;
        } else {
            cout << "You won! Here's what you got: " << rewardsStr << endl;
            cout << "press any key to continue" << endl;
        }
    }
}

Screen* Combat::processOption(int option, bool isRunning){
    if(inCombat){
        Character* userCharacterClass = currentUser->getCharacterClass();
        StatsManager* userStats = currentUser->getStatsManager();
        if(option == 1){
            enemy->dealDamage(userStats->getCurrentDMG());
            if(enemy->getHealth() <= 0){
                enemy->killThis();
                inCombat = false;
                return this;
            }
        } else if(option == 2){
            if(userCharacterClass->getFirstSpell()->getSpellLevelThreshold() <= currentUser->getLevel()){
                //do spell
            }
            if(enemy->getHealth() <= 0){
                enemy->killThis();
                inCombat = false;
                return this;
            }
        } else if(option == 3){
            if(userCharacterClass->getSecondSpell()->getSpellLevelThreshold() <= currentUser->getLevel()){
                //do spell
            }
            if(enemy->getHealth() <= 0){
                enemy->killThis();
                inCombat = false;
                return this;
            }
        } else if(option == 4){
            if(userCharacterClass->getThirdSpell()->getSpellLevelThreshold() <= currentUser->getLevel()){
                //do spell
            }
            if(enemy->getHealth() <= 0){
                enemy->killThis();
                inCombat = false;
                return this;
            }
        } else if(option == 5){
            userLastMoveStr = "You tried to flee and failed!";
        } else {
            return this;
        }
        enemy->calculateTurn(userStats);
        return this;
    } else {
        if(!enemy->getStatus()){
            //reset player stats, maybe go back to travel and reset health to what it was before instead of just killing all progress?
            return new StartMenu("startMenu.txt", currentUser);
        } else {
            //update player stats and inventory
            return new Travel("travelScreen.txt", currentUser);
        }
    }
}