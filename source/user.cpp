#include "../header/user.h"

User::User()
{
    level = 1;
    xp = 0;
    encounterCount = 0;
    inventory = nullptr;
    equippedWeapon = new Weapon(1, "Physical", "Fists", 0);
    equippedArmor = new Armor("Wood", 0, 0, 0, 0);
    equippedTrinket = new Trinket("Necklace", 0, 0);
    character = nullptr;
    userStats = nullptr;
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