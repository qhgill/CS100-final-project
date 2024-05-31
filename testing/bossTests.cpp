#include <gtest/gtest.h>
#include "../header/bosspart1.h"
#include "../header/bosspart2.h"
#include "../header/bosspart3.h"
#include "../header/finalBoss.h"
#include "../header/statsManager.h"
#include "../header/weapon.h"
#include "../header/trinket.h"
#include "../header/armor.h"
#include "../header/character.h"



TEST(getterTests, inheritanceTest) {
    BossPart1 tempBoss;

    ASSERT_EQ(tempBoss.getLevel(), 0);
    ASSERT_EQ(tempBoss.getHealth(), 0);
    ASSERT_EQ(tempBoss.getMaxHealth(), 0);
    ASSERT_EQ(tempBoss.getDamage(), 0);
    ASSERT_EQ(tempBoss.getMagicResist(), 0);
    ASSERT_EQ(tempBoss.getPhysicalResist(), 0);
    ASSERT_EQ(tempBoss.getStatus(), false);
    ASSERT_EQ(tempBoss.getName(), "");
}

TEST(getterTests, finalBossInheritanceTest) {
    FinalBoss tempBoss(5, 5, 5, 5, 5, 5, false, "Joe");

    ASSERT_EQ(tempBoss.getLevel(), 5);
    ASSERT_EQ(tempBoss.getHealth(), 5);
    ASSERT_EQ(tempBoss.getMaxHealth(), 5);
    ASSERT_EQ(tempBoss.getDamage(), 5);
    ASSERT_EQ(tempBoss.getMagicResist(), 5);
    ASSERT_EQ(tempBoss.getPhysicalResist(), 5);
    ASSERT_EQ(tempBoss.getStatus(), false);
    ASSERT_EQ(tempBoss.getName(), "Joe");
}

TEST(calcTests, finalBossCalculateTurnTest) {
  FinalBoss tempBoss(10, 10, 10, 10, 10, 10, false, "Captain Hook");

  Character character;
  Weapon weapon("knife", 5, 5, "physical");
  Armor armor("helmet", 5, 5, 5, 5);           
  Trinket trinket("locket", 5, 5);  
  StatsManager* sm;

  sm->updateStats(&character, &weapon, &armor, &trinket, 1);
  //  maxHP       =   characterBaseHealth + armorHealthBonus + (userLevel * 10) = 10 + 5 + (1 * 10) = 25

  //  currentMR   =   characterBaseMagicResist + armorMagicResistBonus = 1 + 5 = 6
  //  currentPR   =   characterBasePhysicalResist + armorPhysicalResistBonus = 1 + 5 = 6

  tempBoss.calculateTurn(sm);
  ASSERT_EQ(sm->getCurrentHP(), 21);

  tempBoss.dealDamage(8);
  sm->updateStats(&character, &weapon, &armor, &trinket, 1);
  tempBoss.calculateTurn(sm);
  ASSERT_EQ(sm->getCurrentHP(), 13);

}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
