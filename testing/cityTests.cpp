#include <gtest/gtest.h>
#include "../header/screens/city.h"

TEST(cityTests, noThrowDisplayTest){
    User* testUser = new User();
    Screen* testCity = new City("cityScreen.txt", testUser);
    EXPECT_NO_THROW({testCity->displayScreen();});
}

TEST(cityTests, testOptionOne){
    User* testUser = new User();
    Screen* testCity = new City("cityScreen.txt", testUser);
    Screen* resultCity = testCity->processOption(1, true);
    EXPECT_EQ(testCity, resultCity);
}

TEST(cityTests, testOption2){
    User* testUser = new User();
    Screen* testCity = new City("cityScreen.txt", testUser);
    Screen* resultCity = testCity->processOption(2, true);
    EXPECT_EQ(testCity, resultCity);
}

TEST(cityTests, testOption3){
    User* testUser = new User();
    Screen* testCity = new City("cityScreen.txt", testUser);
    Screen* resultCity = testCity->processOption(3, true);
    EXPECT_EQ(testCity, resultCity);
}

TEST(cityTests, testOption4){
    User* testUser = new User();
    Screen* testCity = new City("cityScreen.txt", testUser);
    Screen* resultCity = testCity->processOption(4, true);
    EXPECT_EQ(testCity, resultCity);
}

TEST(cityTests, testOption5){
    User* testUser = new User();
    Screen* testCity = new City("cityScreen.txt", testUser);
    Screen* resultCity = testCity->processOption(5, true);
    EXPECT_EQ(testCity, resultCity);
}

TEST(cityTests, testOption6){
    User* testUser = new User();
    Screen* testCity = new City("cityScreen.txt", testUser);
    Screen* resultCity = testCity->processOption(6, true);
    EXPECT_NE(testCity, resultCity);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}