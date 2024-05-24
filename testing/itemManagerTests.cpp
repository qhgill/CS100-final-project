#include <gtest/gtest.h>
#include "../header/user.h"
#include <../header/itemManager.h>



TEST(itemManagerConstructor, getterFunctionTests) {
    std::vector<Item*>* i = new std::vector<Item*>;
    Weapon* w = new Weapon("",0, 0, "");
    Armor* a = new Armor("", 0,0,0,0);
    Trinket* t = new Trinket("",0,0);

    ItemManager* im = new ItemManager(i, w, a, t);

    EXPECT_EQ(im->getInventory(), i);
    EXPECT_EQ(im->getEquippedWeapon(), w);
    EXPECT_EQ(im->getEquippedArmor(), a);
    EXPECT_EQ(im->getEquippedTrinket(), t);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}