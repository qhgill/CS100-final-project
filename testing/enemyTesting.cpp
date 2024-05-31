#include <gtest/gtest.h>
#include "../header/enemy.h"

class MockEnemy: public Enemy{
    public: 
    MockEnemy(int lvl, int hp, int mxhp, int dmg, int mr, int pr, bool isdead, std::string name):Enemy(lvl, hp, mxhp, dmg, mr, pr, isdead, name){}
    MOCK_METHOD((void), calculateTurn, (StatsManager*), (override));
};

TEST(enemyGetterTests, getLevelTest)
{
    MockEnemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getLevel(), 1);
}

TEST(enemyGetterTests, getHealthTest)
{
    MockEnemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getHealth(), 1);
}

TEST(enemyGetterTests, getMaxHealthTest)
{
    MockEnemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getMaxHealth(), 1);
}

TEST(enemyGetterTests, getDamageTest)
{
    MockEnemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getDamage(), 1);
}

TEST(enemyGetterTests, getMagicResistTest)
{
    MockEnemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getMagicResist(), 1);
}

TEST(enemyGetterTests, getPhysicalResistTest)
{
    MockEnemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getPhysicalResist(), 1);
}

TEST(enemyGetterTests, getStatusTest)
{
    MockEnemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_TRUE(!(monster1.getStatus()));
}

TEST(enemyGetterTests, getNameTest)
{
    MockEnemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getName(), "Bill");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}