#include <gtest/gtest.h>
#include "../header/weapon.h"

TEST(weaponGetterTests, getDamageTest){
    Weapon weapon("fists", 1, 10, "physical");
    EXPECT_EQ(weapon.getDamage(), 10);
}
TEST(weaponGetterTests, getTypeTest) {
    Weapon weapon("fists", 1, 10, "physical");
    string testType = weapon.getType();
    EXPECT_EQ(testType, "weapon");
}

TEST(weaponGetterTests, getDamageTypeTest){
    Weapon weapon("fists", 1, 10, "physical");;
    EXPECT_STREQ(weapon.getDamageType().c_str(), string("physical").c_str());
}

TEST(weaponGetterTests, getWeaponNameTest){
    Weapon weapon("fists", 1, 10, "physical");
    EXPECT_EQ(weapon.getLevel(), 1);
}

TEST(weaponGetterTests, getWeaponLevelTest){
    Weapon weapon("fists", 1, 10, "physical");
    EXPECT_EQ(weapon.calcDamage(2), 20);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}