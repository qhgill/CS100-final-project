#include <gtest/gtest.h>
#include "../header/orcBoss.h"
#include "../header/statsManager.h"

TEST(getterTests, constructorInitializationTest) {
    OrcBoss orcBoss;

    EXPECT_EQ(orcBoss.getLevel(), 8);
    EXPECT_EQ(orcBoss.getHealth(), 100);
    EXPECT_EQ(orcBoss.getMaxHealth(), 100);
    EXPECT_EQ(orcBoss.getDamage(), 21);
    EXPECT_EQ(orcBoss.getMagicResist(), 3);
    EXPECT_EQ(orcBoss.getPhysicalResist(), 14);
    EXPECT_EQ(orcBoss.getName(), "General Bob");
}

TEST(OrcBossTest, CalculatePhaseOneTurnTest) {
    OrcBoss* orcBoss = new OrcBoss();
    StatsManager* statsManager = new StatsManager();
    Weapon* testWeapon = new Weapon();
    Armor* testArmor = new Armor();
    Trinket* testTrinket = new Trinket();
    statsManager->updateStats(1,1,1,1, testWeapon, testArmor, testTrinket, 1); 

    int initialHP = statsManager->getCurrentHP();
    int initialPR = statsManager->getCurrentPR();

    orcBoss->calculatePhaseOneTurn(statsManager);

    EXPECT_EQ(statsManager->getCurrentHP(), 0);
    EXPECT_EQ(statsManager->getCurrentPR(), 0);

    delete orcBoss;
    delete statsManager;
}

TEST(OrcBossTest, CalculatePhaseTwoTurnTest) {
    OrcBoss* orcBoss = new OrcBoss();
    StatsManager* statsManager = new StatsManager();
    Weapon* testWeapon = new Weapon();
    Armor* testArmor = new Armor();
    Trinket* testTrinket = new Trinket();
    statsManager->updateStats(1,1,1,1, testWeapon, testArmor, testTrinket, 1); 

    int initialHP = statsManager->getCurrentHP();
    int initialPR = statsManager->getCurrentPR();
    int initialMR = statsManager->getCurrentMR();

    orcBoss->calculatePhaseTwoTurn(statsManager);

    EXPECT_EQ(statsManager->getCurrentHP(), 0);
    EXPECT_EQ(statsManager->getCurrentPR(), 0);
    EXPECT_EQ(statsManager->getCurrentMR(), 0);
    
    delete orcBoss;
    delete statsManager;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}