#include <gtest/gtest.h>
#include "../header/item.h"
#include "../header/armor.h"

TEST(getterTests, getNameTest) {
    Armor testArmor("helmet", 5, 5, 5, 5);
    std::string testName = testArmor.getName();

    EXPECT_EQ(testName, "helmet");
}

TEST(getterTests, getTypeTest) {
    Armor testArmor("helmet", 5, 5, 5, 5);
    std::string testType = testArmor.getType();
    EXPECT_EQ(testType, "armor");
}


TEST(getterTests, getLevelTest) {
    Armor testArmor("helmet", 5, 5, 5, 5);
    int testLevel = testArmor.getLevel();

    EXPECT_EQ(testLevel, 5);
}

TEST(getterTests, getHealthTest) {
    Armor testArmor("helmet", 5, 5, 5, 5);
    int test = testArmor.getHealth();

    EXPECT_EQ(test, 5);
}
TEST(getterTests, getPhyResTest) {
    Armor testArmor("helmet", 5, 5, 5, 5);
    int test = testArmor.getPhyRes();

    EXPECT_EQ(test, 5);
}
TEST(getterTests, getMagResTest) {
    Armor testArmor("helmet", 5, 5, 5, 5);
    int test = testArmor.getMagRes();

    EXPECT_EQ(test, 5);
}
TEST(calcTest, calcPhyDamageTest) {
    Armor testArmor("helmet", 5, 5, 5, 5);
    int testDamage = testArmor.calcPhyDamage(10);

    EXPECT_EQ(testDamage, 7);
}

TEST(calcTest, calcMagDamageTest) {
    Armor testArmor("helmet", 5, 5, 5, 5);
    int testDamage = testArmor.calcMagDamage(10);

    EXPECT_EQ(testDamage, 7);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
