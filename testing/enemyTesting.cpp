#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../header/enemy.h"
#include "../header/screen/city.h"
#include "../header/user.h"

TEST(enemyGetterTests, getLevelTest)
{
    //User user1, User class is not done
    City city1("Mushrooms", user1);
    Enemy char1(1, 1, 1, 1, 1, 1, false, "Bill", city1);
    EXPECT_EQ(char1.getLevel(), 1);
}

TEST(enemyGetterTests, getHealthTest)
{
    //User user1, User class is not done
    City city1("Mushrooms", user1);
    Enemy char1(1, 1, 1, 1, 1, 1, false, "Bill", city1);
    EXPECT_EQ(char1.getHealth(), 1);
}

TEST(enemyGetterTests, getMaxHealthTest)
{
    //User user1, User class is not done
    City city1("Mushrooms", user1);
    Enemy char1(1, 1, 1, 1, 1, 1, false, "Bill", city1);
    EXPECT_EQ(char1.getMaxHealth(), 1);
}

TEST(enemyGetterTests, getDamageTest)
{
    //User user1, User class is not done
    City city1("Mushrooms", user1);
    Enemy char1(1, 1, 1, 1, 1, 1, false, "Bill", city1);
    EXPECT_EQ(char1.getDamage(), 1);
}

TEST(enemyGetterTests, getMagicResistTest)
{
    //User user1, User class is not done
    City city1("Mushrooms", user1);
    Enemy char1(1, 1, 1, 1, 1, 1, false, "Bill", city1);
    EXPECT_EQ(char1.getMagicResist(), 1);
}

TEST(enemyGetterTests, getPhysicalResistTest)
{
    //User user1, User class is not done
    City city1("Mushrooms", user1);
    Enemy char1(1, 1, 1, 1, 1, 1, false, "Bill", city1);
    EXPECT_EQ(char1.getPhysicalResist(), 1);
}

TEST(enemyGetterTests, getStatusTest)
{
    //User user1, User class is not done
    City city1("Mushrooms", user1);
    Enemy char1(1, 1, 1, 1, 1, 1, false, "Bill", city1);
    EXPECT_TRUE(!(char1.getStatus()));
}

TEST(enemyGetterTests, getNameTest)
{
    //User user1, User class is not done
    City city1("Mushrooms", user1);
    Enemy char1(1, 1, 1, 1, 1, 1, false, "Bill", city1);
    EXPECT_EQ(char1.getName(), "Bill");
}

TEST(enemyGetterTests, getCityTest)
{
    //User user1, User class is not done
    City city1("Mushrooms", user1);
    Enemy char1(1, 1, 1, 1, 1, 1, false, "Bill", city1);
    EXPECT_EQ(char1.getCityName(), city1);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}