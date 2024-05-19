#include <gtest/gtest.h>
#include "../header/user.h"

TEST(userConstructorTests, overloadedConstructorTest){
    std::vector<Item*>* i = new std::vector<Item*>;
    Weapon* w = new Weapon("",0, 0, "");
    Armor* a = new Armor("", 0,0,0,0);
    Trinket* t = new Trinket("",0,0);
    Character* c = new Character();
    StatsManager* sm = new StatsManager();

    User u(1, 2, 3, i, w, a, t, c, sm);

    EXPECT_EQ(u.getLevel(), 1);
    EXPECT_EQ(u.getXp(), 2);
    EXPECT_EQ(u.getEncounterCount(), 3);
    EXPECT_EQ(u.getInventory(), i);
    EXPECT_EQ(u.getCharacterClass(), c);
    EXPECT_EQ(u.getStatsManager(), sm);
}

TEST(userGetterTests, getUserLevel){
    std::vector<Item*>* i = new std::vector<Item*>;
    Weapon* w = new Weapon("",0, 0, "");
    Armor* a = new Armor("", 0,0,0,0);
    Trinket* t = new Trinket("",0,0);
    Character* c = new Character();
    StatsManager* sm = new StatsManager();

    User u(1, 2, 3, i, w, a, t, c, sm);

    EXPECT_EQ(u.getLevel(), 1);
}

TEST(userGetterTests, getUserXp){
    std::vector<Item*>* i = new std::vector<Item*>;
    Weapon* w = new Weapon("",0, 0, "");
    Armor* a = new Armor("", 0,0,0,0);
    Trinket* t = new Trinket("",0,0);
    Character* c = new Character();
    StatsManager* sm = new StatsManager();

    User u(1, 2, 3, i, w, a, t, c, sm);
    EXPECT_EQ(u.getXp(), 2);
}

TEST(userGetterTests, getUserEncounterCount){
    std::vector<Item*>* i = new std::vector<Item*>;
    Weapon* w = new Weapon("",0, 0, "");
    Armor* a = new Armor("", 0,0,0,0);
    Trinket* t = new Trinket("",0,0);
    Character* c = new Character();
    StatsManager* sm = new StatsManager();

    User u(1, 2, 3, i, w, a, t, c, sm);
    EXPECT_EQ(u.getEncounterCount(), 3);
}

TEST(userGetterTests, getUserInventory){
    std::vector<Item*>* i = new std::vector<Item*>;
    Weapon* w = new Weapon("",0, 0, "");
    Armor* a = new Armor("", 0,0,0,0);
    Trinket* t = new Trinket("",0,0);
    Character* c = new Character();
    StatsManager* sm = new StatsManager();

    User u(1, 2, 3, i, w, a, t, c, sm);
    EXPECT_EQ(u.getInventory(), i);
}

TEST(userGetterTests, getUserCharacterClass){
    std::vector<Item*>* i = new std::vector<Item*>;
    Weapon* w = new Weapon("",0, 0, "");
    Armor* a = new Armor("", 0,0,0,0);
    Trinket* t = new Trinket("",0,0);
    Character* c = new Character();
    StatsManager* sm = new StatsManager();

    User u(1, 2, 3, i, w, a, t, c, sm);
    EXPECT_EQ(u.getCharacterClass(), c);
}

TEST(userGetterTests, getUserStatsManager){
    std::vector<Item*>* i = new std::vector<Item*>;
    Weapon* w = new Weapon("",0, 0, "");
    Armor* a = new Armor("", 0,0,0,0);
    Trinket* t = new Trinket("",0,0);
    Character* c = new Character();
    StatsManager* sm = new StatsManager();

    User u(1, 2, 3, i, w, a, t, c, sm);
    EXPECT_EQ(u.getStatsManager(), sm);
}

TEST(userMethodTests, levelUp){
    User u(1, 5, 10, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
    u.levelUp();
    EXPECT_EQ(u.getLevel(), 2); 
    u.levelUp();
    EXPECT_EQ(u.getLevel(), 3);
}

TEST(userMethodTests, equipItem){
    User u(1, 5, 10, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
    Item* i = new Weapon("sword", 1, 2, "physical");
    EXPECT_NO_THROW(u.equipItem(i);); // More thought needed
    delete i;
}

TEST(userMethodTests, resetEncounterCount){
    User u(1, 5, 10, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
    u.incrementEncounterCount();
    EXPECT_EQ(u.getEncounterCount(), 11);
    u.resetEncounterCount();
    EXPECT_EQ(u.getEncounterCount(), 0);
}

TEST(userMethodTests, incrementEncounterCount){
    User u(1, 5, 10, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
    EXPECT_EQ(u.getEncounterCount(), 10);
    u.incrementEncounterCount();
    EXPECT_EQ(u.getEncounterCount(), 11);
}
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}