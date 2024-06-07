#include <gtest/gtest.h>
#include "../header/mage.h"
#include "../header/orc.h"

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
    std::string testName = mage.getClassName();
    EXPECT_EQ(testName, std::string("Mage").c_str());;
}

TEST(mageSpellGetterTests, getFirstClassNameTest){
    Mage mage;
    Spell* returnedSpell = mage.getFirstSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), std::string("ArcaneBlast").c_str());;
}

TEST(mageSpellGetterTests, getSecondClassNameTest){
    Mage mage;
    Spell* returnedSpell = mage.getSecondSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), std::string("LifeLeech").c_str());;
}

TEST(mageSpellGetterTests, getThirdClassNameTest){
    Mage mage;
    Spell* returnedSpell = mage.getThirdSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), std::string("Incinerate").c_str());;
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

TEST(mageSpellTests, testFirstDoSpell){
    Mage mage;
    int hp = 1;
    int gold = 1;
    int dmg = 1;
    Enemy* enemy = new Orc();
    EXPECT_NO_THROW(mage.getFirstSpell()->doSpell(hp, dmg, 1, gold, enemy););
}

TEST(mageSpellTests, testSecondDoSpell){
    Mage mage;
    int hp = 1;
    int gold = 1;
    int dmg = 1;
    Enemy* enemy = new Orc();
    EXPECT_NO_THROW(mage.getSecondSpell()->doSpell(hp, dmg, 1, gold, enemy););
}

TEST(mageSpellTests, testThirdDoSpell){
    Mage mage;
    int hp = 1;
    int gold = 1;
    int dmg = 1;
    Enemy* enemy = new Orc();
    EXPECT_NO_THROW(mage.getThirdSpell()->doSpell(hp, dmg, 1, gold, enemy););
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}