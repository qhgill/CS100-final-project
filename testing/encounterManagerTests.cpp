#include <gtest/gtest.h>
#include "../header/encounterManager.h"

TEST(encounterManagerTests, defaultConstructorTest)
{
    EncounterManager encounterManager;
    EXPECT_EQ(encounterManager.getEncounterCount(), 0);
}

TEST(encounterManagerTests, parameterizedConstructorTest)
{
    EncounterManager encounterManager(1);
    EXPECT_EQ(encounterManager.getEncounterCount(), 1);
}

TEST(encounterManagerTests, resetEncounterTest)
{
    EncounterManager encounterManager(2);
    encounterManager.resetEncounterCount();
    EXPECT_EQ(encounterManager.getEncounterCount(), 0);
}

TEST(EncounterManagerTests, incrementEncounterTest)
{
    EncounterManager encounterManager;
    encounterManager.incrementEncounterCount();
    EXPECT_EQ(encounterManager.getEncounterCount(), 1);
}

TEST(EncounterManagerTests, getEncounterCount_ThrowTest)
{
    EncounterManager encounterManager;
    EXPECT_NO_THROW(encounterManager.getEncounterCount());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
