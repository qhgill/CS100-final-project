#include <gtest/gtest.h>
#include "../header/screens/screen.h"

TEST(mainMenuTests, constructorTest){
    EXPECT_NO_THROW({
        InGameMenu* menuTest = new InGameMenu("gameMenuScreen.txt", new User());
    });
}

TEST(mainMenuTests, displayTest){
    User* testUser = new User();
    InGameMenu* menuTest = new InGameMenu("gameMenuScreen.txt", testUser);
    EXPECT_NO_THROW({
        menuTest->displayScreen();
    });
}

TEST(mainMenuTests, processOptionOneTest){
    User* testUser = new User();
    bool testBool = true;
    Screen* menuTest = new InGameMenu("gameMenuScreen.txt", testUser);
    Screen* testScreen = menuTest->processOption(1, testBool);
    EXPECT_NE(testScreen, menuTest);
}

TEST(mainMenuTests, processOptionTwoTest){
    User* testUser = new User();
    bool testBool = true;
    Screen* menuTest = new InGameMenu("gameMenuScreen.txt", testUser);
    Screen* testScreen = menuTest->processOption(2, testBool);
    EXPECT_NE(testScreen, menuTest);
}

TEST(mainMenuTests, processOptionThreeTest){
    User* testUser = new User();
    bool testBool = true;
    Screen* menuTest = new InGameMenu("gameMenuScreen.txt", testUser);
    Screen* testScreen = menuTest->processOption(3, testBool);
    EXPECT_NE(testScreen, menuTest);
}

TEST(mainMenuTests, processOptionOtherTest){
    User* testUser = new User();
    bool testBool = true;
    Screen* menuTest = new InGameMenu("gameMenuScreen.txt", testUser);
    Screen* testScreen = menuTest->processOption(4, testBool);
    EXPECT_EQ(testScreen, menuTest);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}