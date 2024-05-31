#include "gtest/gtest.h"
#include "../header/screens/characterSelect.h"

TEST(characterSelectTests, constructorTest){
    EXPECT_NO_THROW({CharacterSelect test("", new User());});
}

TEST(characterSelectTests, displayTest){
    CharacterSelect test("characterSelectScreen.txt", new User());
    EXPECT_NO_THROW({test.displayScreen();});
}

TEST(characterSelectTests, testOption1){
    User* testUser = new User();
    CharacterSelect test("characterSelectScreen.txt", testUser);
    Screen* testReturn = test.processOption(1, true);
    EXPECT_NE(testReturn, &test);
    EXPECT_EQ(testUser->getCharacterClass()->getClassName(), "Warrior");
}

TEST(characterSelectTests, testOption2){
    User* testUser = new User();
    CharacterSelect test("characterSelectScreen.txt", testUser);
    Screen* testReturn = test.processOption(2, true);
    EXPECT_NE(testReturn, &test);
    EXPECT_EQ(testUser->getCharacterClass()->getClassName(), "Mage");
}

TEST(characterSelectTests, testOption3){
    User* testUser = new User();
    CharacterSelect test("characterSelectScreen.txt", testUser);
    Screen* testReturn = test.processOption(3, true);
    EXPECT_NE(testReturn, &test);
    EXPECT_EQ(testUser->getCharacterClass()->getClassName(), "Rogue");
}

TEST(characterSelectTests, testOtherOption){
    User* testUser = new User();
    CharacterSelect test("characterSelectScreen.txt", testUser);
    Screen* testReturn = test.processOption(0, true);
    EXPECT_EQ(testReturn, &test);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}