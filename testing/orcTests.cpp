#include <gtest/gtest.h>
#include "../header/orc.h"
#include "../header/character.h"

TEST(getterTests, constructorInitializationTest) {
    Orc orc;

    EXPECT_EQ(orc.getLevel(), 3);
    EXPECT_EQ(orc.getHealth(), 60);
    EXPECT_EQ(orc.getMaxHealth(), 60);
    EXPECT_EQ(orc.getDamage(), 8);
    EXPECT_EQ(orc.getMagicResist(), 3);
    EXPECT_EQ(orc.getPhysicalResist(), 8);
    EXPECT_EQ(orc.getName(), std::string("Orc").c_str());
}

TEST(damageTests, damageEffectsTest) {
    Orc orc;
    Character character;                        // baseHP(10), baseDamage(5), basePhysicalResist(1), baseMagicResist(1)
    Weapon weapon("fists", 1, 10, "physical");  // itemName, itemLvl, dmg, dmgType
    Armor armor("cloth", 1, 1, 2, 0);           // itemName, itemLvl, healthBonus, physicalResist, magicalResist
    Trinket trinket("locket", 1, 2);            // itemName, itemLvl, pierceValue
    StatsManager statsManager; 
    
    statsManager.updateStats(&character, &weapon, &armor, &trinket, 1);
    
    // Pre-Turn Stats
    EXPECT_EQ(statsManager.getCurrentHP(), 21);
    EXPECT_EQ(statsManager.getCurrentDMG(), 20);
    EXPECT_EQ(statsManager.getCurrentMR(), 1);
    EXPECT_EQ(statsManager.getCurrentPR(), 3);
    
    orc.calculateTurn(&statsManager);
    
    // Post-Turn Stats
    EXPECT_EQ(statsManager.getCurrentHP(), 0);
    EXPECT_EQ(statsManager.getCurrentDMG(), 20); 
    EXPECT_EQ(statsManager.getCurrentMR(), 1); 
    EXPECT_EQ(statsManager.getCurrentPR(), 3-2); 
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}