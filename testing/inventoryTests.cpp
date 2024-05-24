#include <gtest/gtest.h>
#include "../header/screens/screen.h"
#include "../header/screens/inventory.h"

TEST(inventoryTests, displayTest){
    vector<Item*>* inv = new vector<Item*>;
    StatsManager* stats = new StatsManager();
    User* user = new User(1,1,nullptr, inv, nullptr, nullptr, nullptr, nullptr, stats);
    Screen* inventory = new Inventory("inventoryScreen.txt", user);
    EXPECT_NO_THROW(inventory->displayScreen());
}

TEST(inventoryTests, processOptionOne){
    vector<Item*>* inv = new vector<Item*>;
    StatsManager* stats = new StatsManager();
    User* user = new User(1,1,nullptr, inv, nullptr, nullptr, nullptr, nullptr, stats);
    Screen* inventory = new Inventory("inventoryScreen.txt", user);
    EXPECT_EQ(inventory->processOption(1, true), inventory);
}

TEST(inventoryTests, processOptionTwo){
    vector<Item*>* inv = new vector<Item*>;
    StatsManager* stats = new StatsManager();
    User* user = new User(1,1,nullptr, inv, nullptr, nullptr, nullptr, nullptr, stats);
    Screen* inventory = new Inventory("inventoryScreen.txt", user);
    EXPECT_EQ(inventory->processOption(2, true), inventory);
}

TEST(inventoryTests, processOptionThree){
    vector<Item*>* inv = new vector<Item*>;
    StatsManager* stats = new StatsManager();
    User* user = new User(1,1,nullptr, inv, nullptr, nullptr, nullptr, nullptr, stats);
    Screen* inventory = new Inventory("inventoryScreen.txt", user);
    EXPECT_EQ(inventory->processOption(3, true), inventory);
}

//more tests later, need to alter some stuff to make it more testable

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}