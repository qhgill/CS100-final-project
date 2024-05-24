#include <gtest/gtest.h>
#include "../header/user.h"

TEST(userConstructorTests, overloadedConstructorTest){
    
    Character* c = new Character();
    StatsManager* sm = new StatsManager();
    ItemManager* im = new ItemManager();
    EncounterManager* em = new EncounterManager();

    User u(1, 2, em, c, sm, im);

    EXPECT_EQ(u.getLevel(), 1);
    EXPECT_EQ(u.getXp(), 2);
    EXPECT_EQ(u.getEncounterManager(), em);
    EXPECT_EQ(u.getCharacterClass(), c);
    EXPECT_EQ(u.getStatsManager(), sm);
    EXPECT_EQ(u.getItemManager(), im);
}

TEST(userGetterTests, getUserLevel){
    Character* c = new Character();
    StatsManager* sm = new StatsManager();
    ItemManager* im = new ItemManager();
    EncounterManager* em = new EncounterManager();
    User u(1, 2, em, c, sm, im);
    EXPECT_EQ(u.getLevel(), 1);
}

TEST(userGetterTests, getUserXp){
    
    Character* c = new Character();
    StatsManager* sm = new StatsManager();
    ItemManager* im = new ItemManager();
    EncounterManager* em = new EncounterManager();
    User u(1, 2, em, c, sm, im);
    EXPECT_EQ(u.getXp(), 2);
}


TEST(userGetterTests, getUserEncounterManager){
    Character* c = new Character();
    StatsManager* sm = new StatsManager();
    EncounterManager* em = new EncounterManager();
    User u(1, 2, em, c, sm, nullptr);
    EXPECT_EQ(u.getEncounterManager(), em);
}



TEST(userGetterTests, getUserCharacterClass){
    Character* c = new Character();
    StatsManager* sm = new StatsManager();
    ItemManager* im = new ItemManager();
    EncounterManager* em = new EncounterManager();
    User u(1, 2, em, c, sm, im);
    EXPECT_EQ(u.getCharacterClass(), c);
}

TEST(userGetterTests, getUserStatsManager){
    

    Character* c = new Character();
    StatsManager* sm = new StatsManager();
    ItemManager* im = new ItemManager();
    EncounterManager* em = new EncounterManager();
    User u(1, 2, em, c, sm, im);
    EXPECT_EQ(u.getStatsManager(), sm);
}

TEST(userMethodTests, levelUp){
    User u(1, 5, nullptr, nullptr, nullptr, nullptr);
    u.levelUp();
    EXPECT_EQ(u.getLevel(), 2); 
    u.levelUp();
    EXPECT_EQ(u.getLevel(), 3);
}

}
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}