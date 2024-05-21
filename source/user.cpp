#include "../header/user.h"

User::User()
{
    level = 1;
    xp = 0;
    encounterCount = 0;
    inventory = nullptr;
    equippedWeapon = nullptr;
    equippedArmor = nullptr;
    equippedTrinket = nullptr;
    character = nullptr;
    userStats = nullptr;
    userItems = nullptr;
}
User::User(int lvl, int exp, int eCount, Character* cClass, StatsManager* sm, ItemManager* im)
{
    level = lvl;
    xp = exp;
    encounterCount = eCount;
    character = cClass;
    userStats = sm;
    userItems = im;
}
User::~User()
{
    delete character;
    delete userStats;
    delete userItems;
}

int User::getLevel() const
{
    return this->level;
}
int User::getXp() const
{
    return this->xp;
}
int User::getEncounterCount() const
{
    return this->encounterCount;
} 
std::vector<Item*>* User::getInventory()
{
    return this->userItems->getInventory();
}
Character* User::getCharacterClass() 
{
    return this->character;
}
StatsManager* User::getStatsManager() 
{
    return this->userStats;
}

ItemManager* User::getItemManager() {
    return this->userItems;
}

void User::levelUp()
{
    this->level++;
    return;
}
void User::resetEncounterCount()
{
    this->encounterCount = 0;
    return;
}
void User::incrementEncounterCount()
{
    this->encounterCount++;
    return;
}