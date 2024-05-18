#pragma once
#include <string>
#include <vector>
#include "item.h"
#include "weapon.h"
#include "armor.h"
#include "trinket.h"
#include "statsManager.h"
#include "character.h"
#include "rogue.h"

class User
{
    private:
        int level;
        int xp;
        int encounterCount;
        std::vector<Item*>* inventory;
        Weapon* equippedWeapon;
        Armor* equippedArmor;
        Trinket* equippedTrinket;
        Character* character;
        StatsManager* userStats;
    public:
        User();
        User(int lvl, int exp, int eCount, std::vector<Item*>* inv, Weapon* w, Armor* a, Trinket* t, Character* cClass, StatsManager* sm);
        ~User();
        
        int getLevel() const;
        int getXp() const;
        int getEncounterCount() const;
        std::vector<Item*>* getInventory(); 
        Character* getCharacterClass(); 
        StatsManager* getStatsManager();

        void levelUp();
        void equipItem(const Item* i);
        void resetEncounterCount();
        void incrementEncounterCount();
};