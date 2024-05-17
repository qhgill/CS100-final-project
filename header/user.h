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
        void levelUp();
        std::vector<Item*> getInventory() const; 
        void equipItem(const Item* i);
        int getEncounterCount() const;
        void resetEncounterCount();
        void incrementEncounterCount();
        Character getCharacterClass() const; 
        StatsManager getStatsManager() const;
};