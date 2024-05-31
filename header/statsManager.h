#pragma once
#include <string>
#include "weapon.h"
#include "armor.h"
#include "trinket.h"

class StatsManager
{
private:
    int maxHP;
    int currentHP;
    int currentDMG;
    int currentMR;
    int currentPR;
public:
    StatsManager();
    void updateStats(int baseDmg, int baseHP, int baseMR, int basePR, Weapon* weapon, Armor* armor, Trinket* trinket, int level);
    void resetMRandPR(int baseMR, int basePR, Weapon* weapon, Armor* armor, Trinket* trinket, int level);
    int getCurrentMR() const;
    int getCurrentPR() const;
    int getMaxHP() const;
    int getCurrentHP() const;
    int& getCurrentHP();
    int getCurrentDMG() const;
    int& getCurrentDMG();
    void takeDamage(int dmgAmount, const std::string& dmgType);
    void healSelf(int healAmount);
    void reduceMR(int mrAmount);
    void reducePR(int prAmount);
};