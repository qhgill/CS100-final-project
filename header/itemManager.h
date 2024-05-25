#pragma once
#include <vector>
#include "./user.h"
#include "./item.h"
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
        ItemManager() : weaponInventory(new std::vector<Weapon*>),armorInventory(new std::vector<Armor*>), trinketInventory(new std::vector<Trinket*>), equippedWeapon(new Weapon()), equippedArmor(new Armor()), equippedTrinket(new Trinket()) {};
        ItemManager(std::vector<Weapon*>* weapons, std::vector<Armor*>* armors, std::vector<Trinket*>* trinkets, Weapon* w, Armor* a, Trinket* t) 
            : weaponInventory(weapons), armorInventory(armors), trinketInventory(trinkets), equippedWeapon(w), equippedArmor(a), equippedTrinket(t) {};

        ~ItemManager() {
            delete weaponInventory;
            delete armorInventory;
            delete trinketInventory;
            delete equippedWeapon;
            delete equippedArmor;
            delete equippedTrinket;
        };

        std::vector<Weapon*>* getWeaponInventory() {return weaponInventory;}
        std::vector<Armor*>* getArmorInventory() {return armorInventory;}
        std::vector<Trinket*>* getTrinketInventory() {return trinketInventory;}
        Weapon*& getEquippedWeapon() {return equippedWeapon;}
        Armor*& getEquippedArmor() {return equippedArmor;}
        Trinket*& getEquippedTrinket() {return equippedTrinket;}
};