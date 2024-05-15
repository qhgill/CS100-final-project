#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../header/weapon.h"

TEST(weaponGetterTests, getDamageTest){
    Item* item1 = new Item("spear");
    Weapon char1(1, "physical", item1);
    EXPECT_EQ(char1.getDamage(), 1);
}

TEST(weaponGetterTests, getDamageTypeTest){
    Item* item1 = new Item("spear");
    Weapon char1(1, "physical", item1);
    EXPECT_EQ(char1.getDamageType(), "physical");
}

TEST(weaponGetterTests, getDamageTypeTest){
    Item* item1 = new Item("spear");
    Weapon char1(1, "physical", item1);
    EXPECT_EQ(char1.calcDamage(2), 2);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}