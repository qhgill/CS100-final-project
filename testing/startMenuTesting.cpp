#include <gtest/gtest.h>
#include "../header/screens/screen.h"

TEST(startMenuTests, displayTest){
    User* testUser = new User();
    Screen* testScreen = new StartMenu("startMenu.txt", testUser);
    EXPECT_NO_THROW(testScreen->displayScreen(););
}

TEST(startMenuTests, testOption1){
    User* testUser = new User();
    bool testBool = true;
    Screen* testScreen = new StartMenu("startMenu.txt", testUser);
    Screen* resultScreen = testScreen->processOption(1, testBool);
    EXPECT_NE(testScreen, resultScreen);
}

TEST(startMenuTests, testOption2){
    User* testUser = new User();
    bool testBool = true;
    Screen* testScreen = new StartMenu("startMenu.txt", testUser);
    Screen* resultScreen = testScreen->processOption(2, testBool);
    EXPECT_EQ(testScreen, resultScreen);
}

TEST(startMenuTests, testOptionOther){
    User* testUser = new User();
    bool testBool = true;
    Screen* testScreen = new StartMenu("startMenu.txt", testUser);
    Screen* resultScreen = testScreen->processOption(0, testBool);
    EXPECT_EQ(testScreen, resultScreen);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
