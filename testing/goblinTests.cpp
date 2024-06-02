#include <gtest/gtest.h>
#include "../header/goblin.h"
#include "../header/character.h"

TEST(getterTests, constructorInitializationTest)
{
    Goblin goblin;

    EXPECT_EQ(goblin.getLevel(), 2);
    EXPECT_EQ(goblin.getHealth(), 15);
    EXPECT_EQ(goblin.getMaxHealth(), 15);
    EXPECT_EQ(goblin.getDamage(), 5);
    EXPECT_EQ(goblin.getMagicResist(), 5);
    EXPECT_EQ(goblin.getPhysicalResist(), 5);
    EXPECT_EQ(goblin.getName(), std::string("Goblin").c_str());
}

TEST(damageTests, damage_heal_Test) 
{
    Goblin* goblin = new Goblin();                    
    StatsManager* statsManager = new StatsManager(); 
    statsManager->updateStats(1,5,0,0, nullptr, nullptr, nullptr, 1); 
    
    // Pre-Turn Stats
    EXPECT_EQ(statsManager->getCurrentHP(), 5);
    EXPECT_EQ(statsManager->getCurrentDMG(), 1);
    EXPECT_EQ(statsManager->getCurrentMR(), 0);
    EXPECT_EQ(statsManager->getCurrentPR(), 0);
    
    goblin->dealDamage(5);
    
    goblin->calculateTurn(statsManager);
    
    // Post-Turn Stats
    EXPECT_EQ(statsManager->getCurrentHP(), 2);
    EXPECT_EQ(goblin->getHealth(), 13); 

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}