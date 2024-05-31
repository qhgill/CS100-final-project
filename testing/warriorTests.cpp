#include <gtest/gtest.h>
#include "../header/warrior.h"

TEST(warriorGetterTests, getHpTest){
    Warrior warrior;
    int testHP = warrior.getBaseHP();
    EXPECT_EQ(testHP, 15);
}

TEST(warriorGetterTests, getDamageTest){
    Warrior warrior;
    int testDamage = warrior.getBaseDamage();
    EXPECT_EQ(testDamage, 7);
}

TEST(warriorGetterTests, getPRTest){
    Warrior warrior;
    int testPR = warrior.getBasePhysicalResist();
    EXPECT_EQ(testPR, 5);
}

TEST(warriorGetterTests, getMRTest){
    Warrior warrior;
    int testMR = warrior.getBaseMagicResist();
    EXPECT_EQ(testMR, 5);
}

TEST(warriorGetterTests, getClassNameTest){
    Warrior warrior;
    std::string testName = warrior.getClassName();
    EXPECT_EQ(testName, std::string("Warrior").c_str());
}

TEST(warriorSpellGetterTests, getFirstClassNameTest){
    Warrior warrior;
    Spell* returnedSpell = warrior.getFirstSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), std::string("Slam").c_str());
}

TEST(warriorSpellGetterTests, getSecondClassNameTest){
    Warrior warrior;
    Spell* returnedSpell = warrior.getSecondSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), std::string("Shatter").c_str());
}

TEST(warriorSpellGetterTests, getThirdClassNameTest){
    Warrior warrior;
    Spell* returnedSpell = warrior.getThirdSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), std::string("Bludgeon").c_str());
}

TEST(warriorSpellGetterTests, getFirstSpellLevelThreshold){
    Warrior warrior;
    Spell* returnedSpell = warrior.getFirstSpell();
    EXPECT_EQ(returnedSpell->getSpellLevelThreshold(), 1);
}

TEST(warriorSpellGetterTests, getSecondSpellLevelThreshold){
    Warrior warrior;
    Spell* returnedSpell = warrior.getSecondSpell();
    EXPECT_EQ(returnedSpell->getSpellLevelThreshold(), 2);
}

TEST(warriorSpellGetterTests, getThirdSpellLevelThreshold){
    Warrior warrior;
    Spell* returnedSpell = warrior.getThirdSpell();
    EXPECT_EQ(returnedSpell->getSpellLevelThreshold(), 3);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}