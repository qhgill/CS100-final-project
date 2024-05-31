#include <gtest/gtest.h>

#include "../header/enemy.h"
#include "../header/pirate.h"
#include "../header/statsManager.h"
#include "../header/weapon.h"
#include "../header/trinket.h"
#include "../header/armor.h"
#include "../header/character.h"


TEST(getterTests, pirateInheritanceTest) {
    Pirate pirate(5, 5, 5, 5, 5, 5, false, "Jack Sparrow");

    ASSERT_EQ(pirate.getLevel(), 5);
    ASSERT_EQ(pirate.getHealth(), 5);
    ASSERT_EQ(pirate.getMaxHealth(), 5);
    ASSERT_EQ(pirate.getDamage(), 5);
    ASSERT_EQ(pirate.getMagicResist(), 5);
    ASSERT_EQ(pirate.getPhysicalResist(), 5);
    ASSERT_EQ(pirate.getStatus(), false);
    ASSERT_EQ(pirate.getName(), "Jack Sparrow");
}


TEST(calcTests, pirateCalcTurnTest) {
    Pirate pirate(3, 3, 3, 3, 3, 3, false, "Jack Sparrow");

    Character character;
    Weapon weapon("knife", 5, 5, "physical");
    Armor armor("helmet", 1, 5, 1, 1);           
    Trinket trinket("locket", 5, 5);  
    StatsManager* sm = new StatsManager();

    sm->updateStats(&character, &weapon, &armor, &trinket, 1);
    //  maxHP       =   characterBaseHealth + armorHealthBonus + (userLevel * 10) = 10 + 5 + (1 * 10) = 25

    //  currentMR   =   characterBaseMagicResist + armorMagicResistBonus = 1 + 5 = 6
    //  currentPR   =   characterBasePhysicalResist + armorPhysicalResistBonus = 1 + 1 = 2

    pirate.calculateTurn(sm);
    EXPECT_EQ(sm->getCurrentHP(), 24);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
