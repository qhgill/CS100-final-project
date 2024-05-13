#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../header/character.h"
using ::testing::Return;
using ::testing::InSequence;

class MockSpell: public spell{
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
}

TEST(getterTests, getPRTest){
    Character char1(1,1,1,1,"class1", nullptr, nullptr, nullptr);
}

TEST(getterTests, getMRTest){
    Character char1(1,1,1,1,"class1", nullptr, nullptr, nullptr);
}

TEST(getterTests, getClassNameTest){
    Character char1(1,1,1,1,"class1", nullptr, nullptr, nullptr);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}