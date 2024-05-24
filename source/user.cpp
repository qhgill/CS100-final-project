#include "../header/user.h"

User::User()
{
    level = 1;
    xp = 0;
    encounters = new EncounterManager();
    character = nullptr;
    userStats = new StatsManager();
    userItems = new ItemManager();
}
User::User(int lvl, int exp, EncounterManager* em, Character* cClass, StatsManager* sm, ItemManager* im)
{
    level = lvl;
    xp = exp;
    encounters = em;
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

EncounterManager* User::getEncounterManager()
{
    return this->encounters;
}

void User::levelUp()
{
    this->level++;
    return;
}
