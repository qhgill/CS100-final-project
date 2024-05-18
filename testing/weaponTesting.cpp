#include <gtest/gtest.h>
#include "../header/weapon.h"

TEST(weaponGetterTests, getDamageTest){
    Weapon weapon(1, "Physical", "Fists", 2);
    EXPECT_EQ(weapon.getDamage(), 1);
}

TEST(weaponGetterTests, getDamageTypeTest){
    Weapon weapon(1, "Physical", "Fists", 2);
    EXPECT_STREQ(weapon.getDamageType().c_str(), string("Physical").c_str());
}

TEST(weaponGetterTests, getWeaponNameTest){
    Weapon weapon(1, "Physical", "Fists", 2);
    EXPECT_EQ(weapon.getLevel(), 2);
}

TEST(weaponGetterTests, getWeaponLevelTest){
    Weapon weapon(1, "Physical", "Fists", 2);
    EXPECT_EQ(weapon.calcDamage(2), 2);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}