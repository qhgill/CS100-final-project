#include <gtest/gtest.h>
#include "../header/user.h"
#include <../header/itemManager.h>
//using std::vector;


TEST(itemManagerConstructor, getterFunctionTests) {
    vector<Weapon*>* weapons = new vector<Weapon*>;
    vector<Armor*>* armors = new vector<Armor*>;
    vector<Trinket*>* trinkets = new vector<Trinket*>;
    Weapon* w = new Weapon("",0, 0, "");
    Armor* a = new Armor("", 0,0,0,0);
    Trinket* t = new Trinket("",0,0);

    ItemManager* im = new ItemManager(weapons, armors, trinkets, w, a, t);

    EXPECT_EQ(im->getWeaponInventory(), weapons);
    EXPECT_EQ(im->getEquippedWeapon(), w);
    EXPECT_EQ(im->getEquippedArmor(), a);
    EXPECT_EQ(im->getEquippedTrinket(), t);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}