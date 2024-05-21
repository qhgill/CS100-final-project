#include <iostream>
#include <vector>
#include "./user.h"
#include "./item.h"
#include "./weapon.h"
#include "./trinket.h"
#include "./armor.h"

class ItemManager {
    private:
        vector<Item*>* inventory;

        Weapon* equippedWeapon;
        Armor* equippedArmor;
        Trinket* equippedTrinket;

    public:
        ItemManager() : inventory(nullptr), equippedWeapon(nullptr), equippedArmor(nullptr), equippedTrinket(nullptr) {};
        ItemManager(vector<Item*>* inv, Weapon* w, Armor* a, Trinket* t) : inventory(inv), equippedWeapon(w), equippedArmor(a), equippedTrinket(t) {};

        ~ItemManager() {
            delete inv;
            delete w;
            delete a;
            delete t;
        };

        vector<Item*>* getInventory() {return inventory;};
        Weapon* getEquippedWeapon() {return equippedWeapon;};
        Armor* getEquippedArmor() {return equippedArmor;};
        Trinket* getEquippedTrinket() {return equippedTrinket;};
        

        void equipItem(const Item* i);
};