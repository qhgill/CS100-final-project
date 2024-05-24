#include <gtest/gtest.h>
#include "../header/screens/screen.h"
#include "../header/screens/inventory.h"

TEST(inventoryTests, displayTest){
    StatsManager* stats = new StatsManager();
    ItemManager* items = new ItemManager();
    EncounterManager* encounters = new EncounterManager();
    User* user = new User(1,1, encounters, nullptr, stats, items);
    Screen* inventory = new Inventory("inventoryScreen.txt", user);
    EXPECT_NO_THROW(inventory->displayScreen());
}

TEST(inventoryTests, processOptionOne){
    StatsManager* stats = new StatsManager();
    ItemManager* items = new ItemManager();
    EncounterManager* encounters = new EncounterManager();
    User* user = new User(1,1, encounters, nullptr, stats, items);
    Screen* inventory = new Inventory("inventoryScreen.txt", user);
    EXPECT_EQ(inventory->processOption(1, true), inventory);
}

TEST(inventoryTests, processOptionTwo){
    StatsManager* stats = new StatsManager();
    ItemManager* items = new ItemManager();
    EncounterManager* encounters = new EncounterManager();
    User* user = new User(1,1, encounters, nullptr, stats, items);
    Screen* inventory = new Inventory("inventoryScreen.txt", user);
    EXPECT_EQ(inventory->processOption(2, true), inventory);
}


TEST(inventoryTests, processOptionThree){
    StatsManager* stats = new StatsManager();
    ItemManager* items = new ItemManager();
    EncounterManager* encounters = new EncounterManager();
    User* user = new User(1,1, encounters, nullptr, stats, items);
    Screen* inventory = new Inventory("inventoryScreen.txt", user);
    EXPECT_EQ(inventory->processOption(3, true), inventory);
}

TEST(inventoryTests, processOptionFour){
    StatsManager* stats = new StatsManager();
    ItemManager* items = new ItemManager();
    EncounterManager* encounters = new EncounterManager();
    User* user = new User(1,1, encounters, nullptr, stats, items);
    Screen* inventory = new Inventory("inventoryScreen.txt", user);
    EXPECT_NE(inventory->processOption(3, true), inventory);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}