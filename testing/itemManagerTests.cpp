#include <gtest/gtest.h>
#include "../header/user.h"
#include <../header/itemManager.h>



TEST(itemManagerConstructor, getterFunctionTests) {
    std::vector<Item*>* i = new std::vector<Item*>;
    Weapon* w = new Weapon("",0, 0, "");
    Armor* a = new Armor("", 0,0,0,0);
    Trinket* t = new Trinket("",0,0);

    ItemManager* im = new ItemManager(i, w, a, t);

    ASSERT_EQ(im->getInventory(), i);
    ASSERT_EQ(im->getEquippedWeapon(), w);
    ASSERT_EQ(im->getEquippedArmor(), a);
    ASSERT_EQ(im->getEquippedTrinket(), t);
}

TEST() {

}