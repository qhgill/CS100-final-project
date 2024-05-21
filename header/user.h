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

class User
{
    private:
        int level;
        int xp;
        int encounterCount;
        
        Character* character;
        StatsManager* userStats;
        ItemManager* userItems;
    public:
        User();
        User(int lvl, int exp, int eCount, Character* cClass, StatsManager* sm, ItemManager* im);
        ~User();
        
        int getLevel() const;
        int getXp() const;
        int getEncounterCount() const;
        std::vector<Item*>* getInventory(); 
        Character* getCharacterClass(); 
        StatsManager* getStatsManager();
        ItemManager* getItemManager();

        void levelUp();
        void resetEncounterCount();
        void incrementEncounterCount();
};