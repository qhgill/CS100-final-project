#include "../header/user.h"

User::User()
{
    level = 1;
    xp = 0;
    encounterCount = 0;
    inventory = new std::vector<Item*>;
    equippedWeapon = new Weapon(1, "Physical", "Fists");
    equippedArmor = new Armor; // update with constructor once implemented
    equippedTrinket = new Trinket; // update with constructor once implemented
    character = new Rogue();
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
    return 0;
}

int User::getXp() const
{
    return 0;
}

void User::levelUp()
{
    return;
}

std::vector<Item*> User::getInventory() const
{
    return std::vector<Item*>(NULL);
}

void User::equipItem(const Item* i)
{
    return;
}

int User::getEncounterCount() const
{
    return 0;
} 

void User::resetEncounterCount()
{
    return;
}

void User::incrementEncounterCount()
{
    return;
}

Character User::getCharacterClass() const
{
    return Character();
}

StatsManager User::getStatsManager() const
{
    return StatsManager();
}