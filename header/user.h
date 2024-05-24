#pragma once
#include <string>
#include <vector>
#include "item.h"
#include "weapon.h"
#include "armor.h"
#include "trinket.h"
#include "character.h"
#include "statsManager.h"
#include "itemManager.h"
#include "encounterManager.h"

class User
{
    private:
        int level;
        int xp;
        Character* character;
        StatsManager* userStats;
        ItemManager* userItems;
        EncounterManager* encounters;
    public:
        User();
        User(int lvl, int exp, EncounterManager* em, Character* cClass, StatsManager* sm, ItemManager* im);
        ~User();
        int getLevel() const;
        int getXp() const;
        Character* getCharacterClass(); 
        StatsManager* getStatsManager();
        ItemManager* getItemManager();
        void levelUp();
        EncounterManager* getEncounterManager();
};