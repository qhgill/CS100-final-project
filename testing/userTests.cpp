#include <gtest/gtest.h>
#include "../header/user.h"

TEST(userConstructorTests, overloadedConstructorTest){
    
    Character* c = new Character();
    StatsManager* sm = new StatsManager();
    ItemManager* im = new ItemManager();

    User u(1, 2, 3, c, sm, im);

    EXPECT_EQ(u.getLevel(), 1);
    EXPECT_EQ(u.getXp(), 2);
    EXPECT_EQ(u.getEncounterCount(), 3);
    EXPECT_EQ(u.getCharacterClass(), c);
    EXPECT_EQ(u.getStatsManager(), sm);
    EXPECT_EQ(u.getItemManager(), im);
}

TEST(userGetterTests, getUserLevel){

    Character* c = new Character();
    StatsManager* sm = new StatsManager();
    ItemManager* im = new ItemManager();

    User u(1, 2, 3, c, sm, im);

    EXPECT_EQ(u.getLevel(), 1);
}

TEST(userGetterTests, getUserXp){
    
    Character* c = new Character();
    StatsManager* sm = new StatsManager();
    ItemManager* im = new ItemManager();

    User u(1, 2, 3, c, sm, im);
    EXPECT_EQ(u.getXp(), 2);
}

TEST(userGetterTests, getUserEncounterCount){
    
    Character* c = new Character();
    StatsManager* sm = new StatsManager();
    ItemManager* im = new ItemManager();

    User u(1, 2, 3, c, sm, im);
    
    EXPECT_EQ(u.getEncounterCount(), 3);
}


TEST(userGetterTests, getUserCharacterClass){
    
    Character* c = new Character();
    StatsManager* sm = new StatsManager();
    ItemManager* im = new ItemManager();

    User u(1, 2, 3, c, sm, im);

    EXPECT_EQ(u.getCharacterClass(), c);
}

TEST(userGetterTests, getUserStatsManager){
    

    Character* c = new Character();
    StatsManager* sm = new StatsManager();
    ItemManager* im = new ItemManager();

    User u(1, 2, 3, c, sm, im);

    EXPECT_EQ(u.getStatsManager(), sm);
}

TEST(userMethodTests, levelUp){
    User u(1, 5, 10, nullptr, nullptr, nullptr);
    u.levelUp();
    EXPECT_EQ(u.getLevel(), 2); 
    u.levelUp();
    EXPECT_EQ(u.getLevel(), 3);
}


TEST(userMethodTests, resetEncounterCount){
    User u(1, 5, 10, nullptr, nullptr, nullptr);
    u.incrementEncounterCount();
    EXPECT_EQ(u.getEncounterCount(), 11);
    u.resetEncounterCount();
    EXPECT_EQ(u.getEncounterCount(), 0);
}

TEST(userMethodTests, incrementEncounterCount){
    User u(1, 5, 10, nullptr, nullptr, nullptr);
    EXPECT_EQ(u.getEncounterCount(), 10);
    u.incrementEncounterCount();
    EXPECT_EQ(u.getEncounterCount(), 11);
}
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}