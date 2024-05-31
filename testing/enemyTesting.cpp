#include <gtest/gtest.h>
#include "../header/enemy.h"

TEST(enemyGetterTests, getLevelTest)
{
    Enemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getLevel(), 1);
}

TEST(enemyGetterTests, getHealthTest)
{
    Enemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getHealth(), 1);
}

TEST(enemyGetterTests, getMaxHealthTest)
{
    Enemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getMaxHealth(), 1);
}

TEST(enemyGetterTests, getDamageTest)
{
    Enemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getDamage(), 1);
}

TEST(enemyGetterTests, getMagicResistTest)
{
    Enemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getMagicResist(), 1);
}

TEST(enemyGetterTests, getPhysicalResistTest)
{
    Enemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getPhysicalResist(), 1);
}

TEST(enemyGetterTests, getStatusTest)
{
    Enemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_TRUE(!(monster1.getStatus()));
}

TEST(enemyGetterTests, getNameTest)
{
    Enemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getName(), "Bill");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}