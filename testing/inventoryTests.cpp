#include <gtest/gtest.h>
#include "../header/screens/screen.h"
#include "../header/screens/inventory.h"

TEST(inventoryTests, displayTest){
    StatsManager* stats = new StatsManager();
    ItemManager* items = new ItemManager();
    EncounterManager* encounters = new EncounterManager();
    Character* character = new Character();
    User* user = new User(1,1, encounters, character, stats, items);
    Screen* inventory = new Inventory("inventoryScreen.txt", user);
    EXPECT_NO_THROW(inventory->displayScreen());
}

TEST(inventoryTests, processOptionOne){
    StatsManager* stats = new StatsManager();
    ItemManager* items = new ItemManager();
    EncounterManager* encounters = new EncounterManager();
    Weapon* newWeapon = new Weapon();
    items->getWeaponInventory()->push_back(newWeapon);
    Character* character = new Character();
    User* user = new User(1,1, encounters, character, stats, items);
    Screen* inventory = new Inventory("inventoryScreen.txt", user);
    EXPECT_EQ(inventory->processOption(1, true), inventory);
    EXPECT_EQ(items->getEquippedWeapon(), newWeapon);
}

TEST(inventoryTests, processOptionTwo){
    StatsManager* stats = new StatsManager();
    ItemManager* items = new ItemManager();
    EncounterManager* encounters = new EncounterManager();
    Armor* newArmor = new Armor();
    items->getArmorInventory()->push_back(newArmor);
    Character* character = new Character();
    User* user = new User(1,1, encounters, character, stats, items);
    Screen* inventory = new Inventory("inventoryScreen.txt", user);
    EXPECT_EQ(inventory->processOption(2, true), inventory);
    EXPECT_EQ(items->getEquippedArmor(), newArmor);
}


TEST(inventoryTests, processOptionThree){
    StatsManager* stats = new StatsManager();
    ItemManager* items = new ItemManager();
    EncounterManager* encounters = new EncounterManager();
    Trinket* newTrinket = new Trinket();
    items->getTrinketInventory()->push_back(newTrinket);
    Character* character = new Character();
    User* user = new User(1,1, encounters, character, stats, items);
    Screen* inventory = new Inventory("inventoryScreen.txt", user);
    EXPECT_EQ(inventory->processOption(3, true), inventory);
    EXPECT_EQ(items->getEquippedTrinket(), newTrinket);
}

TEST(inventoryTests, processOptionFour){
    StatsManager* stats = new StatsManager();
    ItemManager* items = new ItemManager();
    EncounterManager* encounters = new EncounterManager();
    Character* character = new Character();
    User* user = new User(1,1, encounters, character, stats, items);
    Screen* inventory = new Inventory("inventoryScreen.txt", user);
    EXPECT_NE(inventory->processOption(4, true), inventory);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}