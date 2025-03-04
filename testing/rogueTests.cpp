#include <gtest/gtest.h>
#include "../header/rogue.h"
#include "../header/orc.h"

TEST(rogueGetterTests, getHpTest){
    Rogue rogue;
    int testHP = rogue.getBaseHP();
    EXPECT_EQ(testHP, 10);
}

TEST(rogueGetterTests, getDamageTest){
    Rogue rogue;
    int testDamage = rogue.getBaseDamage();
    EXPECT_EQ(testDamage, 12);
}

TEST(rogueGetterTests, getPRTest){
    Rogue rogue;
    int testPR = rogue.getBasePhysicalResist();
    EXPECT_EQ(testPR, 3);
}

TEST(rogueGetterTests, getMRTest){
    Rogue rogue;
    int testMR = rogue.getBaseMagicResist();
    EXPECT_EQ(testMR, 2);
}

TEST(rogueGetterTests, getClassNameTest){
    Rogue rogue;
    std::string testName = rogue.getClassName();
    EXPECT_EQ(testName, "Rogue");
}

TEST(rogueSpellGetterTests, getFirstClassNameTest){
    Rogue rogue;
    Spell* returnedSpell = rogue.getFirstSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), std::string("Backstab").c_str());
}

TEST(rogueSpellGetterTests, getSecondClassNameTest){
    Rogue rogue;
    Spell* returnedSpell = rogue.getSecondSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), std::string("PickPocket").c_str());
}

TEST(rogueSpellGetterTests, getThirdClassNameTest){
    Rogue rogue;
    Spell* returnedSpell = rogue.getThirdSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), std::string("Cutthroat").c_str());
}

TEST(rogueSpellGetterTests, getFirstSpellLevelThreshold){
    Rogue rogue;
    Spell* returnedSpell = rogue.getFirstSpell();
    EXPECT_EQ(returnedSpell->getSpellLevelThreshold(), 1);
}

TEST(rogueSpellGetterTests, getSecondSpellLevelThreshold){
    Rogue rogue;
    Spell* returnedSpell = rogue.getSecondSpell();
    EXPECT_EQ(returnedSpell->getSpellLevelThreshold(), 2);
}

TEST(rogueSpellGetterTests, getThirdSpellLevelThreshold){
    Rogue rogue;
    Spell* returnedSpell = rogue.getThirdSpell();
    EXPECT_EQ(returnedSpell->getSpellLevelThreshold(), 3);
}

TEST(rogueSpellTests, testFirstDoSpell){
    Rogue rogue;
    int hp = 1;
    int gold = 1;
    int dmg = 1;
    Enemy* enemy = new Orc();
    EXPECT_NO_THROW(rogue.getFirstSpell()->doSpell(hp, dmg, 1, gold, enemy););
}

TEST(rogueSpellTests, testSecondDoSpell){
    Rogue rogue;
    int hp = 1;
    int gold = 1;
    int dmg = 1;
    Enemy* enemy = new Orc();
    EXPECT_NO_THROW(rogue.getSecondSpell()->doSpell(hp, dmg, 1, gold, enemy););
}

TEST(rogueSpellTests, testThirdDoSpell){
    Rogue rogue;
    int hp = 1;
    int gold = 1;
    int dmg = 1;
    Enemy* enemy = new Orc();
    EXPECT_NO_THROW(rogue.getThirdSpell()->doSpell(hp, dmg, 1, gold, enemy););
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}