#include "../header/user.h"

User::User()
{
    level = 1;
    xp = 0;
    encounters = nullptr;
    inventory = nullptr;
    equippedWeapon = nullptr;
    equippedArmor = nullptr;
    equippedTrinket = nullptr;
    character = nullptr;
    userStats = nullptr;
}
User::User(int lvl, int exp, EncounterManager* em, std::vector<Item*>* inv, Weapon* w, Armor* a, Trinket* t, Character* cClass, StatsManager* sm)
{
    level = lvl;
    xp = exp;
    encounters = em;
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

EncounterManager* User::getEncounterManager()
{
    return this->encounters;
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
