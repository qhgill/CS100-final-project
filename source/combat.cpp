#include "../header/screens/screen.h"
using std::cout;
using std::endl;

Combat::Combat(string dispFile, User* cUser)
: Screen(dispFile, cUser), inCombat(true), enemyLastMoveStr("Enemy hasn't made a move yet"), userLastMoveStr("You haven't made a move yet"), rewardsStr("10 gold, 10xp"){
    isBossFight = (currentUser->getEncounterManager()->getEncounterCount() == 10);
    int storyAct = currentUser->getStoryAct();
    int encounterCount = currentUser->getEncounterManager()->getEncounterCount();
    if(storyAct == 1){
        if(encounterCount != 10){
            enemy = new Orc(); //replace with goblin when implemented
        } else {
            enemy = new OrcBoss(); // "
        }
    } else if(storyAct == 2){
        if(encounterCount != 10){
            enemy = new Orc(); 
        } else {
            enemy = new OrcBoss();
        }
    } else if(storyAct == 3){
        if(encounterCount != 10){
            enemy = new Pirate();
        } else {
            enemy = new PirateBoss();
        }
    } else if(storyAct == 4){
        if(encounterCount != 10){
            enemy = new RoyalGuard();
        } else {
            enemy = new FinalBoss();
        }
    }
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
    cout << "Enemy HP: " << enemy->getHealth() << "/" << enemy->getMaxHealth()   << "         " << "Your HP: " << currentUser->getStatsManager()->getCurrentHP() << "/" << currentUser->getStatsManager()->getMaxHP() << endl;
    cout << "Enemy's last move: " << enemyLastMoveStr << endl;
    cout << "Your last move: " << userLastMoveStr << endl;
    if(inCombat){
        cout << "select an option:" << endl;
        cout << "[1] Use your weapon" << endl;
        cout << "[2] Use your first spell: " << currentUser->getCharacterClass()->getFirstSpell()->getSpellClass();
        if(currentUser->getLevel() < currentUser->getCharacterClass()->getFirstSpell()->getSpellLevelThreshold()){
            cout << "(LEVEL NOT HIGH ENOUGH)";
        }
        cout << endl;
        cout << "[3] Use your second spell" << currentUser->getCharacterClass()->getSecondSpell()->getSpellClass();
        if(currentUser->getLevel() < currentUser->getCharacterClass()->getSecondSpell()->getSpellLevelThreshold()){
            cout << "(LEVEL NOT HIGH ENOUGH)";
        }
        cout << endl;
        cout << "[4] Use your third spell" << currentUser->getCharacterClass()->getThirdSpell()->getSpellClass();
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

Screen* Combat::processOption(int option, bool& isRunning){
    if(inCombat){
        Character* userCharacterClass = currentUser->getCharacterClass();
        StatsManager* userStats = currentUser->getStatsManager();
        int userLevel = currentUser->getLevel();
        if(option == 1){
            enemy->dealDamage(userStats->getCurrentDMG());
            userLastMoveStr = "you attacked the enemy with your weapon";
            if(enemy->getHealth() <= 0){
                enemy->killThis();
                inCombat = false;
                return this;
            }
        } else if(option == 2){
            if(userCharacterClass->getFirstSpell()->getSpellLevelThreshold() <= currentUser->getLevel()){
                userCharacterClass->getFirstSpell()->doSpell(userStats->getCurrentHP(), userStats->getCurrentDMG(), currentUser->getLevel(), currentUser->getGold(), enemy);
                userLastMoveStr = "You used " + userCharacterClass->getFirstSpell()->getSpellClass() + " on the enemy!";
            } else {
                userLastMoveStr = "You tried to use " + userCharacterClass->getFirstSpell()->getSpellClass() + " on the enemy, but your level isn't high enough!";
            }
            if(enemy->getHealth() <= 0){
                enemy->killThis();
                inCombat = false;
                return this;
            }
        } else if(option == 3){
            if(userCharacterClass->getSecondSpell()->getSpellLevelThreshold() <= currentUser->getLevel()){
                userCharacterClass->getSecondSpell()->doSpell(userStats->getCurrentHP(), userStats->getCurrentDMG(), currentUser->getLevel(), currentUser->getGold(), enemy);
                userLastMoveStr = "You used " + userCharacterClass->getSecondSpell()->getSpellClass() + " on the enemy!";
            } else {
                userLastMoveStr = "You tried to use " + userCharacterClass->getSecondSpell()->getSpellClass() + " on the enemy, but your level isn't high enough!";
            }
            if(enemy->getHealth() <= 0){
                enemy->killThis();
                inCombat = false;
                return this;
            }
        } else if(option == 4){
            if(userCharacterClass->getThirdSpell()->getSpellLevelThreshold() <= currentUser->getLevel()){
                userCharacterClass->getThirdSpell()->doSpell(userStats->getCurrentHP(), userStats->getCurrentDMG(), currentUser->getLevel(), currentUser->getGold(), enemy);
                userLastMoveStr = "You used " + userCharacterClass->getThirdSpell()->getSpellClass() + " on the enemy!";
            } else {
                userLastMoveStr = "You tried to use " + userCharacterClass->getThirdSpell()->getSpellClass() + " on the enemy, but your level isn't high enough!";
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
        enemyLastMoveStr = "the enemy attacked you!"; //fix later, calculate turn should be changed to return a description string of the move
        if(currentUser->getStatsManager()->getCurrentHP() <= 0){
            inCombat = false;
        }
        return this;
    } else {
        if(!enemy->getStatus()){
            currentUser->getStatsManager()->getCurrentHP() = currentUser->getStatsManager()->getMaxHP();
            return new Travel("travelScreen.txt", currentUser);
        } else {
            ItemManager* userItems = currentUser->getItemManager();
            Character* userCharacter = currentUser->getCharacterClass();
            currentUser->getGold() += 10;
            currentUser->getStatsManager()->resetMRandPR(userCharacter->getBaseMagicResist(), userCharacter->getBasePhysicalResist(), userItems->getEquippedWeapon(), userItems->getEquippedArmor(), userItems->getEquippedTrinket(), currentUser->getLevel());
            currentUser->getXp() += 10;
            //when item drops are figured out update with item drop functionality
            return new Travel("travelScreen.txt", currentUser);
        }
    }
}

string Combat::getEnemyLastMoveStr() const{
    return enemyLastMoveStr;
}

string Combat::getUserLastMoveStr() const{
    return userLastMoveStr;
}

string Combat::getRewardsStr() const{
    return rewardsStr;
}
