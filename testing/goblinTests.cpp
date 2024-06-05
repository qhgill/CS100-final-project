#include <gtest/gtest.h>
#include "../header/goblin.h"
#include "../header/character.h"

TEST(getterTests, constructorInitializationTest)
{
    Goblin goblin;

    EXPECT_EQ(goblin.getLevel(), 2);
    EXPECT_EQ(goblin.getHealth(), 15);
    EXPECT_EQ(goblin.getMaxHealth(), 15);
    EXPECT_EQ(goblin.getDamage(), 3);
    EXPECT_EQ(goblin.getMagicResist(), 5);
    EXPECT_EQ(goblin.getPhysicalResist(), 5);
    EXPECT_EQ(goblin.getName(), std::string("Goblin").c_str());
}

TEST(damageTests, damage_heal_Test) 
{
    Goblin goblin;                    
    StatsManager* statsManager = new StatsManager(); 
    Weapon weapon("fists", 0, 0, "physical");  // itemName, itemLvl, dmg, dmgType
    Armor armor("cloth", 0, 0, 0, 0);           // itemName, itemLvl, healthBonus, physicalResist, magicalResist
    Trinket trinket("locket", 0, 0);            // itemName, itemLvl, pierceValue
    statsManager->updateStats(1,10,1,1, &weapon, &armor, &trinket, 1); 
    
    // Pre-Turn Stats
    EXPECT_EQ(statsManager->getCurrentHP(), 20);
    EXPECT_EQ(statsManager->getCurrentDMG(), 6);
    EXPECT_EQ(statsManager->getCurrentMR(), 1);
    EXPECT_EQ(statsManager->getCurrentPR(), 1);
    
    goblin.dealDamage(5);
    
    goblin.calculateTurn(statsManager);
    
    // Post-Turn Stats
    EXPECT_EQ(statsManager->getCurrentHP(), 18);
    EXPECT_EQ(goblin.getHealth(), 13); 

    delete statsManager;

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}