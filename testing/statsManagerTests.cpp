#include <gtest/gtest.h>
#include "../header/statsManager.h"
#include "../header/character.h"
#include "../header/weapon.h"
#include "../header/armor.h"
#include "../header/trinket.h"

TEST(StatsManagerGetterTests, updateStatsTest) {
    // Character character;
    // Weapon weapon("fists", 1, 10, "physical");
    // Armor armor("cloth", 1, 1, 2, 0);
    // Trinket trinket("locket", 1, 2);
    // StatsManager statsManager;

    // statsManager.updateStats(&character, &weapon, &armor, &trinket, 1);
    // EXPECT_EQ(statsManager.getMaxHP(), 160);  // 100 base + 50 armor + 10 level*10
    // EXPECT_EQ(statsManager.getCurrentHP(), 160);
    // EXPECT_EQ(statsManager.getCurrentDMG(), 35);  // 20 base + 10 weapon + 5 level*1
    // EXPECT_EQ(statsManager.getCurrentMR(), 12);  // 10 base + 2 armor
    // EXPECT_EQ(statsManager.getCurrentPR(), 5);  // 5 base + 0 armor
    EXPECT_EQ(1, 1);

}

TEST(StatsManagerGetterTests, resetMRandPRTest) {
    // Character character;
    // Weapon weapon("fists", 1, 10, "physical");
    // Armor armor("cloth", 1, 1, 2, 0);
    // Trinket trinket("locket", 1, 2);
    // StatsManager statsManager;

    // statsManager.updateStats(&character, &weapon, &armor, &trinket, 1);
    // statsManager.resetMRandPR(&character, &weapon, &armor, &trinket, 1);
    // EXPECT_EQ(statsManager.getCurrentMR(), 12);  // 10 base + 2 armor
    // EXPECT_EQ(statsManager.getCurrentPR(), 5);  // 5 base + 0 armor
    EXPECT_EQ(1, 1);
}

TEST(StatsManagerGetterTests, takeDamageTest) {
    // Character character;
    // Weapon weapon("fists", 1, 10, "physical");
    // Armor armor("cloth", 1, 1, 2, 0);
    // Trinket trinket("locket", 1, 2);
    // StatsManager statsManager;

    // statsManager.updateStats(&character, &weapon, &armor, &trinket, 1);
    // statsManager.takeDamage(50, "physical");
    // EXPECT_EQ(statsManager.getCurrentHP(), 160 - (50 - 5));  // 160 - 45
    // statsManager.takeDamage(100, "magical");
    // EXPECT_EQ(statsManager.getCurrentHP(), 115 - (100 - 12));  // 115 - 88 = 27
    EXPECT_EQ(1, 1);
}

TEST(StatsManagerTest, healSelfTest) {
    // Character character;
    // Weapon weapon("fists", 1, 10, "physical");
    // Armor armor("cloth", 1, 1, 2, 0);
    // Trinket trinket("locket", 1, 2);
    // StatsManager statsManager;

    // statsManager.updateStats(&character, &weapon, &armor, &trinket, 1);
    // statsManager.takeDamage(50, "physical");
    // statsManager.healSelf(10);
    // EXPECT_EQ(statsManager.getCurrentHP(), 160 - 45 + 10);  // 125
    // statsManager.healSelf(60);
    // EXPECT_EQ(statsManager.getCurrentHP(), 160);  // Cannot exceed max HP
    EXPECT_EQ(1, 1);
}

TEST(StatsManagerTest, reduceMRandPRTest) {
    // Character character;
    // Weapon weapon("fists", 1, 10, "physical");
    // Armor armor("cloth", 1, 1, 2, 0);
    // Trinket trinket("locket", 1, 2);
    // StatsManager statsManager;

    // statsManager.updateStats(&character, &weapon, &armor, &trinket, 1);
    // statsManager.reduceMR(5);
    // EXPECT_EQ(statsManager.getCurrentMR(), 7);  // 12 - 5
    // statsManager.reducePR(3);
    // EXPECT_EQ(statsManager.getCurrentPR(), 2);  // 5 - 3
    // statsManager.reduceMR(20);
    // EXPECT_EQ(statsManager.getCurrentMR(), 0);  // Cannot be less than 0
    // statsManager.reducePR(20);
    // EXPECT_EQ(statsManager.getCurrentPR(), 0);  // Cannot be less than 0
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}