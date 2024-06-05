#include "gtest/gtest.h"
#include "../header/screens/screen.h"

TEST(characterSelectTests, constructorTest){
    EXPECT_NO_THROW({CharacterSelect test("", new User());});
}

TEST(characterSelectTests, displayTest){
    CharacterSelect test("characterSelectScreen.txt", new User());
    EXPECT_NO_THROW({test.displayScreen();});
}

TEST(characterSelectTests, testOption1){
    User* testUser = new User();
    bool dummyRunning = true;
    CharacterSelect test("characterSelectScreen.txt", testUser);
    Screen* testReturn = test.processOption(1, dummyRunning);
    EXPECT_NE(testReturn, &test);
    EXPECT_EQ(testUser->getCharacterClass()->getClassName(), "Warrior");
}

TEST(characterSelectTests, testOption2){
    User* testUser = new User();
    bool dummyRunning = true;
    CharacterSelect test("characterSelectScreen.txt", testUser);
    Screen* testReturn = test.processOption(2, dummyRunning);
    EXPECT_NE(testReturn, &test);
    EXPECT_EQ(testUser->getCharacterClass()->getClassName(), "Mage");
}

TEST(characterSelectTests, testOption3){
    User* testUser = new User();
    bool dummyRunning = true;
    CharacterSelect test("characterSelectScreen.txt", testUser);
    Screen* testReturn = test.processOption(3, dummyRunning);
    EXPECT_NE(testReturn, &test);
    EXPECT_EQ(testUser->getCharacterClass()->getClassName(), "Rogue");
}

TEST(characterSelectTests, testOtherOption){
    User* testUser = new User();
    bool dummyRunning = true;
    CharacterSelect test("characterSelectScreen.txt", testUser);
    Screen* testReturn = test.processOption(0, dummyRunning);
    EXPECT_EQ(testReturn, &test);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}