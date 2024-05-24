#pragma once
#include <iostream>
#include <vector>
#include "./user.h"
#include "./item.h"
#include "./weapon.h"
#include "./trinket.h"
#include "./armor.h"

class ItemManager {
    private:
        vector<Weapon*>* weaponInventory;
        vector<Armor*>* armorInventory;
        vector<Trinket*>* trinketInventory;
        Weapon* equippedWeapon;
        Armor* equippedArmor;
        Trinket* equippedTrinket;

    public:
        ItemManager() : weaponInventory(new vector<Weapon*>),armorInventory(new vector<Armor*>), trinketInventory(new vector<Trinket*>), equippedWeapon(new Weapon()), equippedArmor(new Armor()), equippedTrinket(new Trinket()) {};
        ItemManager(vector<Weapon*>* weapons, vector<Armor*>* armors, vector<Trinket*>* trinkets, Weapon* w, Armor* a, Trinket* t) 
            : weaponInventory(weapons), armorInventory(armors), trinketInventory(trinkets), equippedWeapon(w), equippedArmor(a), equippedTrinket(t) {};

        ~ItemManager() {
            delete weaponInventory;
            delete armorInventory;
            delete trinketInventory;
            delete equippedWeapon;
            delete equippedArmor;
            delete equippedTrinket;
        };

        vector<Weapon*>* getWeaponInventory() {return weaponInventory;}
        vector<Armor*>* getArmorInventory() {return armorInventory;}
        vector<Trinket*>* getTrinketInventory() {return trinketInventory;}
        Weapon*& getEquippedWeapon() {return equippedWeapon;}
        Armor*& getEquippedArmor() {return equippedArmor;}
        Trinket*& getEquippedTrinket() {return equippedTrinket;}
};