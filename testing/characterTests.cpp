#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../header/character.h"
using ::testing::Return;
using ::testing::InSequence;

class MockSpell: public Spell{
    public:
     MOCK_METHOD(void, doSpell,());
};

TEST(getterTests, getHpTest){
    Character char1(1,1,1,1,"class1", nullptr, nullptr, nullptr);
    int testHP = char1.getBaseHP();
    EXPECT_EQ(testHP, 1);
}

TEST(getterTests, getDamageTest){
    Character char1(1,1,1,1,"class1", nullptr, nullptr, nullptr);
    int testDamage = char1.getBaseDamage();
    EXPECT_EQ(testDamage, 1);
}

TEST(getterTests, getPRTest){
    Character char1(1,1,1,1,"class1", nullptr, nullptr, nullptr);
    int testPR = char1.getBasePhysicalResist();
    EXPECT_EQ(testPR, 1);
}

TEST(getterTests, getMRTest){
    Character char1(1,1,1,1,"class1", nullptr, nullptr, nullptr);
    int testMR = char1.getBaseMagicResist();
    EXPECT_EQ(testMR, 1);
}

TEST(getterTests, getClassNameTest){
    Character char1(1,1,1,1,"class1", nullptr, nullptr, nullptr);
    string testName = char1.getClassName();
    EXPECT_EQ(testName, "class1");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}