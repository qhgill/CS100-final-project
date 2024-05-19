#include "../header/statsManager.h"

StatsManager::StatsManager()
    : maxHP(0), currentHP(0), currentDMG(0), currentMR(0), currentPR(0) {}

void StatsManager::updateStats(Character* character, Weapon* weapon, Armor* armor, Trinket* trinket, int level) {
    this->maxHP = character->getBaseHP() + armor->getHealth() + (level * 10);
    this->currentHP = maxHP;
    this->currentDMG = character->getBaseDamage() + weapon->getDamage() + (level * 5);
    this->currentMR = character->getBaseMagicResist() + armor->getMagRes();
    this->currentPR = character->getBasePhysicalResist() + armor->getPhyRes();
}

void StatsManager::resetMRandPR(Character* character, Weapon* weapon, Armor* armor, Trinket* trinket, int level) {
    this->currentMR = character->getBaseMagicResist() + armor->getMagRes();
    this->currentPR = character->getBasePhysicalResist() + armor->getPhyRes();
}

int StatsManager::getCurrentMR() const {
    return this->currentMR;
}

int StatsManager::getCurrentPR() const {
    return this->currentPR;
}

int StatsManager::getMaxHP() const {
    return this->maxHP;
}

int StatsManager::getCurrentHP() const {
    return this->currentHP;
}

int StatsManager::getCurrentDMG() const {
    return this->currentDMG;
}

void StatsManager::takeDamage(int dmgAmount, const std::string& dmgType) {
    if (dmgType == "physical") {
        dmgAmount -= this->currentPR;
    } else if (dmgType == "magical") {
        dmgAmount -= this->currentMR;
    }
    if (dmgAmount < 0) dmgAmount = 0;
    this->currentHP -= dmgAmount;
    if (this->currentHP < 0) this->currentHP = 0;
}

void StatsManager::healSelf(int healAmount) {
    this->currentHP += healAmount;
    if (this->currentHP > this->maxHP) this->currentHP = this->maxHP;
}

void StatsManager::reduceMR(int mrAmount) {
    this->currentMR -= mrAmount;
    if (this->currentMR < 0) this->currentMR = 0;
}

void StatsManager::reducePR(int prAmount) {
    this->currentPR -= prAmount;
    if (this->currentPR < 0) this->currentPR = 0;
}