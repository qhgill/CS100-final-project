#include "../header/user.h"

User::User(): level(1), xp(0), gold(0), storyAct(1), encounters(new EncounterManager()), character(nullptr), userStats(new StatsManager()), userItems(new ItemManager())
{}

User::User(int lvl, int exp, EncounterManager* em, Character* cClass, StatsManager* sm, ItemManager* im):
level(lvl), xp(exp), gold(0), storyAct(1), encounters(em), character(cClass), userStats(sm), userItems(im)
{}

User::~User()
{
    delete character;
    delete userStats;
    delete userItems;
    delete encounters;
}
int User::getStoryAct() const{
    return storyAct;
}

void User::incrementStoryAct(){
    storyAct++;
}

int User::getLevel() const
{
    return this->level;
}
int User::getXp() const
{
    return this->xp;
}
int& User::getXp()
{
    return this->xp;
}

int& User::getGold(){
    return gold;
}

int User::getGold() const{
    return gold;
}

Character*& User::getCharacterClass() 
{
    return this->character;
}

Character* User::getCharacterClass() const{
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
