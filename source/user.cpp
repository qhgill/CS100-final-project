#include "../header/user.h"

User::User()
{
    level = 1;
    xp = 0;
    encounterCount = 0;
    inventory = new vector<Item*>;
    equippedWeapon = nullptr;
    equippedArmor = nullptr;
    equippedTrinket = nullptr;
    character = nullptr;
    userStats = new StatsManager();
}
User::User(int lvl, int exp, int eCount, std::vector<Item*>* inv, Weapon* w, Armor* a, Trinket* t, Character* cClass, StatsManager* sm)
{
    level = lvl;
    xp = exp;
    encounterCount = eCount;
    inventory = inv;
    equippedWeapon = w;
    equippedArmor = a;
    equippedTrinket = t;
    character = cClass;
    userStats = sm;
}
User::~User()
{
    delete inventory;
    delete equippedWeapon;
    delete equippedArmor;
    delete equippedTrinket;
    delete character;
    delete userStats;
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
    return this->inventory;
}
Character* User::getCharacterClass() 
{
    return this->character;
}
StatsManager* User::getStatsManager() 
{
    return this->userStats;
}

void User::levelUp()
{
    this->level++;
    return;
}
void User::equipItem(const Item* i)
{
    // Implementation needed
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