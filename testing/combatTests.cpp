#include <gtest/gtest.h>
#include "../header/screens/screen.h"

TEST(combatTests, constructorTest){
    User* testUser = new User();
    EXPECT_NO_THROW({
        Screen* testCombat = new Combat("combatScreen.txt", testUser);
    }); 
}

TEST(combatTests, displayTest){
    User* testUser = new User();
    testUser->getCharacterClass() = new Warrior();
    Screen* testCombat = new Combat("combatScreen.txt", testUser);
    EXPECT_NO_THROW({
        testCombat->displayScreen();
    });
}

TEST(combatTests, testOptionOne){
    User* testUser = new User();
    bool dummyRunning = true;
    Combat* testCombat = new Combat("combatScreen.txt", testUser);
    Screen* equalTester = testCombat;
    Screen* resultScreen = testCombat->processOption(1, dummyRunning);
    EXPECT_EQ(testCombat->getUserLastMoveStr(), "you attacked the enemy with your weapon");
    EXPECT_EQ(equalTester, resultScreen);
}

TEST(combatTests, testOptionTwo){
    User* testUser = new User();
    bool dummyRunning = true;
    testUser->getCharacterClass() = new Warrior();
    Combat* testCombat = new Combat("combatScreen.txt", testUser);
    Screen* equalTester = testCombat;
    Screen* resultScreen = testCombat->processOption(2, dummyRunning);
    EXPECT_EQ(testCombat->getUserLastMoveStr(), "You used your first spell on the enemy!");
    EXPECT_EQ(equalTester, resultScreen);
}

TEST(combatTests, testOptionThreeLowLvl){
    User* testUser = new User();
    bool dummyRunning = true;
    testUser->getCharacterClass() =  new Warrior();
    Combat* testCombat = new Combat("combatScreen.txt", testUser);
    Screen* equalTester = testCombat;
    Screen* resultScreen = testCombat->processOption(3, dummyRunning);
    EXPECT_EQ(testCombat->getUserLastMoveStr(), "You tried to user your second spell on the enemy, but your level isn't high enough!");
    EXPECT_EQ(equalTester, resultScreen);
}

TEST(combatTests, testOptionThreeHighLvl){
    User* testUser = new User();
    bool dummyRunning = true;
    testUser->getCharacterClass() =  new Warrior();
    testUser->levelUp();
    Combat* testCombat = new Combat("combatScreen.txt", testUser);
    Screen* equalTester = testCombat;
    Screen* resultScreen = testCombat->processOption(3, dummyRunning);
    EXPECT_EQ(testCombat->getUserLastMoveStr(), "You used your second spell on the enemy!");
    EXPECT_EQ(equalTester, resultScreen);
}
TEST(combatTests, testOptionFourLowLvl){
    User* testUser = new User();
    bool dummyRunning = true;
    testUser->getCharacterClass() =  new Warrior();
    Combat* testCombat = new Combat("combatScreen.txt", testUser);
    Screen* equalTester = testCombat;
    Screen* resultScreen = testCombat->processOption(4, dummyRunning);
    EXPECT_EQ(testCombat->getUserLastMoveStr(), "You tried to user your third spell on the enemy, but your level isn't high enough!");
    EXPECT_EQ(equalTester, resultScreen);
}

TEST(combatTests, testOptionFourHighLvl){
    User* testUser = new User();
    bool dummyRunning = true;
    testUser->getCharacterClass() = new Warrior();
    testUser->levelUp();
    testUser->levelUp();
    Combat* testCombat = new Combat("combatScreen.txt", testUser);
    Screen* equalTester = testCombat;
    Screen* resultScreen = testCombat->processOption(4, dummyRunning);
    EXPECT_EQ(testCombat->getUserLastMoveStr(), "You used your third spell on the enemy!");
    EXPECT_EQ(equalTester, resultScreen);
}

TEST(combatTests, testOptionFive){
    User* testUser = new User();
    bool dummyRunning = true;
    testUser->getCharacterClass() =  new Warrior();
    Combat* testCombat = new Combat("combatScreen.txt", testUser);
    Screen* equalTester = testCombat;
    Screen* resultScreen = testCombat->processOption(5, dummyRunning);
    EXPECT_EQ(testCombat->getUserLastMoveStr(), "You tried to flee and failed!");
    EXPECT_EQ(equalTester, resultScreen);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}