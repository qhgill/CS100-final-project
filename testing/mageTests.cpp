#include <gtest/gtest.h>
#include "../header/mage.h"

TEST(mageGetterTests, getHpTest){
    Mage mage;
    int testHP = mage.getBaseHP();
    EXPECT_EQ(testHP, 7);
}

TEST(mageGetterTests, getDamageTest){
    Mage mage;
    int testDamage = mage.getBaseDamage();
    EXPECT_EQ(testDamage, 12);
}

TEST(mageGetterTests, getPRTest){
    Mage mage;
    int testPR = mage.getBasePhysicalResist();
    EXPECT_EQ(testPR, 5);
}

TEST(mageGetterTests, getMRTest){
    Mage mage;
    int testMR = mage.getBaseMagicResist();
    EXPECT_EQ(testMR, 5);
}

TEST(mageGetterTests, getClassNameTest){
    Mage mage;
    string testName = mage.getClassName();
    EXPECT_EQ(testName, "Mage");
}

TEST(mageSpellGetterTests, getFirstClassNameTest){
    Mage mage;
    Spell* returnedSpell = mage.getFirstSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), "Mage");
}

TEST(mageSpellGetterTests, getSecondClassNameTest){
    Mage mage;
    Spell* returnedSpell = mage.getSecondSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), "Mage");
}

TEST(mageSpellGetterTests, getThirdClassNameTest){
    Mage mage;
    Spell* returnedSpell = mage.getThirdSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), "Mage");
}

TEST(mageSpellGetterTests, getFirstSpellLevelThreshold){
    Mage mage;
    Spell* returnedSpell = mage.getFirstSpell();
    EXPECT_EQ(returnedSpell->getSpellLevelThreshold(), 1);
}

TEST(mageSpellGetterTests, getSecondSpellLevelThreshold){
    Mage mage;
    Spell* returnedSpell = mage.getSecondSpell();
    EXPECT_EQ(returnedSpell->getSpellLevelThreshold(), 2);
}

TEST(mageSpellGetterTests, getThirdSpellLevelThreshold){
    Mage mage;
    Spell* returnedSpell = mage.getThirdSpell();
    EXPECT_EQ(returnedSpell->getSpellLevelThreshold(), 3);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}