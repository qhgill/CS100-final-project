#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../header/enemy.h"
using ::testing::Return;
using ::testing::InSequence;

TEST(enemyGetterTests, getLevelTest)
{
    City city1("Mushrooms");
    Enemy char1(1, 1, 1, 1, 1, 1, false, "Bill", city1);
    EXPECT_EQ(char1.getLevel(), 1);
}

TEST(enemyGetterTests, getHealthTest)
{
    City city1("Mushrooms");
    Enemy char1(1, 1, 1, 1, 1, 1, false, "Bill", city1);
    EXPECT_EQ(char1.getHealth(), 1);
}

TEST(enemyGetterTests, getMaxHealthTest)
{
    City city1("Mushrooms");
    Enemy char1(1, 1, 1, 1, 1, 1, false, "Bill", city1);
    EXPECT_EQ(char1.getMaxHealth(), 1);
}

TEST(enemyGetterTests, getDamageTest)
{
    City city1("Mushrooms");
    Enemy char1(1, 1, 1, 1, 1, 1, false, "Bill", city1);
    EXPECT_EQ(char1.getDamage(), 1);
}

TEST(enemyGetterTests, getMagicResistTest)
{
    City city1("Mushrooms");
    Enemy char1(1, 1, 1, 1, 1, 1, false, "Bill", city1);
    EXPECT_EQ(char1.getMagicResist(), 1);
}

TEST(enemyGetterTests, getPhysicalResistTest)
{
    City city1("Mushrooms");
    Enemy char1(1, 1, 1, 1, 1, 1, false, "Bill", city1);
    EXPECT_EQ(char1.getPhysicalResist(), 1);
}

TEST(enemyGetterTests, getStatusTest)
{
    City city1("Mushrooms");
    Enemy char1(1, 1, 1, 1, 1, 1, false, "Bill", city1);
    EXPECT_TRUE(!(char1.getStatus()));
}

TEST(enemyGetterTests, getNameTest)
{
    City city1("Mushrooms");
    Enemy char1(1, 1, 1, 1, 1, 1, false, "Bill", city1);
    EXPECT_EQ(char1.getName(), "Bill");
}

TEST(enemyGetterTests, getCityTest)
{
    City city1("Mushrooms");
    Enemy char1(1, 1, 1, 1, 1, 1, false, "Bill", city1);
    EXPECT_EQ(char1.getCityName(), city1);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}