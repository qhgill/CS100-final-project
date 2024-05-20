#pragma once
#include <string>
#include <vector>
#include "item.h"
#include "weapon.h"
#include "armor.h"
#include "trinket.h"
#include "character.h"
#include "statsManager.h"
#include "encounterManager.h"

class User
{
    private:
        int level;
        int xp;
        std::vector<Item*>* inventory;
        Weapon* equippedWeapon;
        Armor* equippedArmor;
        Trinket* equippedTrinket;
        Character* character;
        StatsManager* userStats;
        EncounterManager* encounters;

    public:
        User();
        User(int lvl, int exp, EncounterManager* em, std::vector<Item*>* inv, Weapon* w, Armor* a, Trinket* t, Character* cClass, StatsManager* sm);
        ~User();
        
        int getLevel() const;
        int getXp() const;
        std::vector<Item*>* getInventory(); 
        Character* getCharacterClass(); 
        StatsManager* getStatsManager();
        EncounterManager* getEncounterManager();

        void levelUp();
        void equipItem(const Item* i);
};