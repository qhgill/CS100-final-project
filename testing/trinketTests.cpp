#include <gtest/gtest.h>
#include "../header/trinket.h"

TEST(getterTests, getNameTest) {
    Trinket trink("necklace", 5, 5);
    std::string testName = trink.getName();

    EXPECT_EQ(testName, "necklace");
}

TEST(getterTests, getTypeTest) {
    Trinket trink("necklace", 5, 5);
    std::string testType = trink.getType();

    EXPECT_EQ(testType, "trinket");
}

TEST(getterTests, getLevelTest) {
    Trinket trink("necklace", 5, 5);
    int testLevel = trink.getLevel();

    EXPECT_EQ(testLevel, 5);
}

TEST(calcTest, calcValueTest) {
    Trinket trink("necklace", 5, 5);
    int testValue = trink.calcValue();

    EXPECT_EQ(testValue, 25);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}