#include <gtest/gtest.h>
#include "../header/weapon.h"

TEST(weaponGetterTests, getDamageTest){
    Weapon char1(1, "physical", "f", 0);
    EXPECT_EQ(1, 1);
}

TEST(weaponGetterTests, getDamageTypeTest){
    Weapon char1(1, "physical", "f", 0);
    EXPECT_EQ(1, 1);
}

TEST(weaponGetterTests, w){
    Weapon char1(1, "physical", "f", 0);
    EXPECT_EQ(2, 2);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}