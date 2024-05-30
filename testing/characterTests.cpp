#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../header/character.h"
using ::testing::Return;
using ::testing::InSequence;

class SpellChildStub: public Spell{
    public:
        SpellChildStub(){}
        MOCK_METHOD((void), doSpell, (int&, int&, int, int&, Enemy*), (override));
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
    std::string testName = char1.getClassName();
    EXPECT_EQ(testName, "class1");
}

TEST(getterTests, getFirstSpellTest){
    Spell* spellTester = new SpellChildStub();
    Character char1(1,1,1,1,"class1", spellTester, nullptr, nullptr);
    Spell* returnTester = char1.getFirstSpell();
    EXPECT_EQ(spellTester, returnTester);
}

TEST(getterTests, getSecondSpellTest){
    Spell* spellTester = new SpellChildStub();
    Character char1(1,1,1,1,"class1", nullptr, spellTester, nullptr);
    Spell* returnTester = char1.getSecondSpell();
    EXPECT_EQ(spellTester, returnTester);
}

TEST(getterTests, getThirdSpellTest){
    Spell* spellTester = new SpellChildStub();
    Character char1(1,1,1,1,"class1", nullptr, nullptr, spellTester);
    Spell* returnTester = char1.getThirdSpell();
    EXPECT_EQ(spellTester, returnTester);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}