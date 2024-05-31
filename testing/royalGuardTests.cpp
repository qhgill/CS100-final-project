#include <gtest/gtest.h>

#include "../header/enemy.h"
#include "../header/royalGuard.h"
#include "../header/statsManager.h"
#include "../header/weapon.h"
#include "../header/trinket.h"
#include "../header/armor.h"
#include "../header/character.h"


TEST(getterTests, royalGuardInheritanceTest) {
    RoyalGuard guard(5, 5, 5, 5, 5, 5, false, "Knight guy");

    ASSERT_EQ(guard.getLevel(), 5);
    ASSERT_EQ(guard.getHealth(), 5);
    ASSERT_EQ(guard.getMaxHealth(), 5);
    ASSERT_EQ(guard.getDamage(), 5);
    ASSERT_EQ(guard.getMagicResist(), 5);
    ASSERT_EQ(guard.getPhysicalResist(), 5);
    ASSERT_EQ(guard.getStatus(), false);
    ASSERT_EQ(guard.getName(), "Knight guy");
}


TEST(calcTests, royalGuardCalcTurnTest) {
    RoyalGuard guard(4, 4, 4, 4, 4, 4, false, "Knight guy");

    Character character;
    Weapon weapon("knife", 5, 5, "physical");
    Armor armor("helmet", 1, 5, 1, 2);  
    Armor armorTwo("boots", 1, 5, 2, 1);         
    Trinket trinket("locket", 5, 5);  
    StatsManager* sm = new StatsManager();

    sm->updateStats(&character, &weapon, &armor, &trinket, 1);
    //  maxHP       =   characterBaseHealth + armorHealthBonus + (userLevel * 10) = 10 + 5 + (1 * 10) = 25

    //  currentMR   =   characterBaseMagicResist + armorMagicResistBonus = 1 + 2 = 3
    //  currentPR   =   characterBasePhysicalResist + armorPhysicalResistBonus = 1 + 1 = 2

    //  currentMR   =   characterBaseMagicResist + armorMagicResistBonus = 1 + 1 = 2
    //  currentPR   =   characterBasePhysicalResist + armorPhysicalResistBonus = 1 + 2 = 3

    guard.calculateTurn(sm);
    EXPECT_EQ(sm->getCurrentHP(), 23);

    sm->updateStats(&character, &weapon, &armorTwo, &trinket, 1);
    guard.calculateTurn(sm);
    EXPECT_EQ(sm->getCurrentHP(), 23);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
