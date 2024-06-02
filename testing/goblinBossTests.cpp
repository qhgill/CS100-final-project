#include <gtest/gtest.h>
#include "../header/goblinBoss.h"
#include "../header/statsManager.h"

TEST(getterTests, constructorInitializationTest) 
{
    GoblinBoss goblinBoss;

    EXPECT_EQ(goblinBoss.getLevel(), 5);
    EXPECT_EQ(goblinBoss.getHealth(), 60);
    EXPECT_EQ(goblinBoss.getMaxHealth(), 60);
    EXPECT_EQ(goblinBoss.getDamage(), 12);
    EXPECT_EQ(goblinBoss.getMagicResist(), 10);
    EXPECT_EQ(goblinBoss.getPhysicalResist(), 15);
    EXPECT_EQ(goblinBoss.getName(), "Commander Joe");
}

TEST(GoblinBossTest, CalculatePhaseOneTurnTest) 
{
    GoblinBoss* goblinBoss = new GoblinBoss(); 
    StatsManager* statsManager = new StatsManager();
    statsManager->updateStats(1,10,1,1, nullptr, nullptr, nullptr, 1); 

    goblinBoss->dealDamage(15); //should put hp down to 45

    goblinBoss->calculatePhaseOneTurn(statsManager);

    EXPECT_EQ(statsManager->getCurrentHP(), 2);
    EXPECT_EQ(goblinBoss->getHealth(), 55);

    delete goblinBoss;
    delete statsManager;
}

TEST(GoblinBossTest, CalculatePhaseTwoTurnTest_HighHP) 
{
    GoblinBoss* goblinBoss = new GoblinBoss(); 
    StatsManager* statsManager = new StatsManager();
    statsManager->updateStats(1,10,1,1, nullptr, nullptr, nullptr, 1); 

    goblinBoss->dealDamage(15); //should put hp down to 45

    goblinBoss->calculatePhaseOneTurn(statsManager);

    EXPECT_EQ(statsManager->getCurrentHP(), 2);
    EXPECT_EQ(goblinBoss->getHealth(), 55);

    delete goblinBoss;
    delete statsManager;
}
TEST(OrcBossTest, CalculatePhaseTwoTurnTest_LowHP) 
{
    GoblinBoss* goblinBoss = new GoblinBoss();
    StatsManager* statsManager = new StatsManager();
    statsManager->updateStats(1,60,1,1, nullptr, nullptr, nullptr, 1);

    int initialHP = statsManager->getCurrentHP();

    goblinBoss->dealDamage(55);

    goblinBoss->calculatePhaseTwoTurn(statsManager);

    EXPECT_EQ(statsManager->getCurrentHP(), 10);
    EXPECT_EQ(statsManager->getCurrentPR(), 0);
    EXPECT_EQ(statsManager->getCurrentMR(), 0);
    EXPECT_EQ(goblinBoss->getHealth(), 55);
    
    delete goblinBoss;
    delete statsManager;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}