#include <gtest/gtest.h>
#include "../header/goblinBoss.h"
#include "../header/statsManager.h"

TEST(getterTests, constructorInitializationTest) 
{
    GoblinBoss goblinBoss;

    EXPECT_EQ(goblinBoss.getLevel(), 5);
    EXPECT_EQ(goblinBoss.getHealth(), 60);
    EXPECT_EQ(goblinBoss.getMaxHealth(), 60);
    EXPECT_EQ(goblinBoss.getDamage(), 5);
    EXPECT_EQ(goblinBoss.getMagicResist(), 10);
    EXPECT_EQ(goblinBoss.getPhysicalResist(), 15);
    EXPECT_EQ(goblinBoss.getName(), "Commander Joe");
}

TEST(GoblinBossTest, CalculatePhaseOneTurnTest) 
{
    GoblinBoss goblinBoss; 
    StatsManager* statsManager = new StatsManager();
    Weapon weapon("fists", 0, 0, "physical");  // itemName, itemLvl, dmg, dmgType
    Armor armor("cloth", 0, 0, 0, 0);           // itemName, itemLvl, healthBonus, physicalResist, magicalResist
    Trinket trinket("locket", 0, 0);            // itemName, itemLvl, pierceValue
    statsManager->updateStats(1,10,1,1, &weapon, &armor, &trinket, 1); 

    goblinBoss.dealDamage(15); //should put hp down to 45, which is above 30

    goblinBoss.calculateTurn(statsManager);

    EXPECT_EQ(statsManager->getCurrentHP(), 12);
    EXPECT_EQ(goblinBoss.getHealth(), 55);

    delete statsManager;
}

TEST(GoblinBossTest, CalculatePhaseTwoTurnTest_HighHP) 
{
    GoblinBoss goblinBoss;
    StatsManager* statsManager = new StatsManager();
    Weapon weapon("fists", 0, 0, "physical");  // itemName, itemLvl, dmg, dmgType
    Armor armor("cloth", 0, 0, 0, 0);           // itemName, itemLvl, healthBonus, physicalResist, magicalResist
    Trinket trinket("locket", 0, 0);            // itemName, itemLvl, pierceValue
    statsManager->updateStats(1,10,1,1, &weapon, &armor, &trinket, 1); 

    goblinBoss.dealDamage(35); //should put hp down to 25, which is below 30

    goblinBoss.calculateTurn(statsManager);

    EXPECT_EQ(statsManager->getCurrentHP(), 2);
    EXPECT_EQ(goblinBoss.getHealth(), 45);

    delete statsManager;
}
TEST(OrcBossTest, CalculatePhaseTwoTurnTest_LowHP) 
{
    GoblinBoss goblinBoss;
    StatsManager* statsManager = new StatsManager();
    Weapon weapon("fists", 0, 0, "physical");  // itemName, itemLvl, dmg, dmgType
    Armor armor("cloth", 0, 0, 0, 0);           // itemName, itemLvl, healthBonus, physicalResist, magicalResist
    Trinket trinket("locket", 0, 0);            // itemName, itemLvl, pierceValue
    statsManager->updateStats(1,50,1,1, &weapon, &armor, &trinket, 1); 

    int initialHP = statsManager->getCurrentHP();

    goblinBoss.dealDamage(55);

    goblinBoss.calculateTurn(statsManager);

    EXPECT_EQ(statsManager->getCurrentHP(), 10);
    EXPECT_EQ(statsManager->getCurrentPR(), 0);
    EXPECT_EQ(statsManager->getCurrentMR(), 0);
    EXPECT_EQ(goblinBoss.getHealth(), 55);
    
    delete statsManager;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}