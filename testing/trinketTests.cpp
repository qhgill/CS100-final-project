#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../header/item.h"
#include "../header/trinket.h"

TEST(getterTests, getNameTest) {
    Trinket trink("necklace", 5, 5);
    string testName = trink.getName();

    EXPECT_EQ(testName, "necklace");
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