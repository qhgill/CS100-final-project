#pragma once
#include <vector>
#include "./weapon.h"
#include "./trinket.h"
#include "./armor.h"

class ItemManager 
{
    private:
        std::vector<Weapon*>* weaponInventory;
        std::vector<Armor*>* armorInventory;
        std::vector<Trinket*>* trinketInventory;
        Weapon* equippedWeapon;
        Armor* equippedArmor;
        Trinket* equippedTrinket;
    public:
        ItemManager();
        ItemManager(std::vector<Weapon*>* weapons, std::vector<Armor*>* armors, std::vector<Trinket*>* trinkets, Weapon* w, Armor* a, Trinket* t);
        ~ItemManager();
        std::vector<Weapon*>* getWeaponInventory();
        std::vector<Armor*>* getArmorInventory();
        std::vector<Trinket*>* getTrinketInventory();
        Weapon*& getEquippedWeapon();
        Armor*& getEquippedArmor();
        Trinket*& getEquippedTrinket();
};