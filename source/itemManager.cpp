#include "../header/itemManager.h"

ItemManager::ItemManager() 
: weaponInventory(new std::vector<Weapon*>), armorInventory(new std::vector<Armor*>), trinketInventory(new std::vector<Trinket*>), equippedWeapon(new Weapon()), equippedArmor(new Armor()), equippedTrinket(new Trinket()) 
{}
ItemManager::ItemManager(std::vector<Weapon*>* weapons, std::vector<Armor*>* armors, std::vector<Trinket*>* trinkets, Weapon* w, Armor* a, Trinket* t) 
: weaponInventory(weapons), armorInventory(armors), trinketInventory(trinkets), equippedWeapon(w), equippedArmor(a), equippedTrinket(t) 
{}
ItemManager::~ItemManager() 
{
    delete weaponInventory;
    delete armorInventory;
    delete trinketInventory;
    delete equippedWeapon;
    delete equippedArmor;
    delete equippedTrinket;
};
std::vector<Weapon*>* ItemManager::getWeaponInventory() 
{
    return weaponInventory;
}
std::vector<Armor*>* ItemManager::getArmorInventory() 
{
    return armorInventory;
}
std::vector<Trinket*>* ItemManager::getTrinketInventory() 
{
    return trinketInventory;
}
Weapon*& ItemManager::getEquippedWeapon() 
{
    return equippedWeapon;
}
Armor*& ItemManager::getEquippedArmor() 
{
    return equippedArmor;
}
Trinket*& ItemManager::getEquippedTrinket() 
{
    return equippedTrinket;
}