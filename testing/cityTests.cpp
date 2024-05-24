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
    City* testCity2 = new City("cityScreen.txt", testUser);
    Screen* resultCity = testCity->processOption(1, true);
    EXPECT_EQ(testCity, resultCity);
    resultCity = testCity2->processOption(1, true);
    EXPECT_TRUE(testCity2->getTavernUsed());
}

TEST(cityTests, testOption2){
    User* testUser = new User();
    Screen* testCity = new City("cityScreen.txt", testUser);
    City* testCity2 = new City("cityScreen.txt", testUser);
    Screen* resultCity = testCity->processOption(2, true);
    EXPECT_EQ(testCity, resultCity);
    resultCity = testCity2->processOption(2, true);
    EXPECT_EQ(testCity2->getCityWeapon(), nullptr);
}

TEST(cityTests, testOption3){
    User* testUser = new User();
    Screen* testCity = new City("cityScreen.txt", testUser);
    City* testCity2 = new City("cityScreen.txt", testUser);
    Screen* resultCity = testCity->processOption(3, true);
    EXPECT_EQ(testCity, resultCity);
    resultCity = testCity2->processOption(3, true);
    EXPECT_EQ(testCity2->getCityArmor(), nullptr);
}

TEST(cityTests, testOption4){
    User* testUser = new User();
    Screen* testCity = new City("cityScreen.txt", testUser);
    City* testCity2 = new City("cityScreen.txt", testUser);
    Screen* resultCity = testCity->processOption(4, true);
    EXPECT_EQ(testCity, resultCity);
    resultCity = testCity2->processOption(4, true);
    EXPECT_EQ(testCity2->getCityTrinket(), nullptr);
}

TEST(cityTests, testOption5){
    User* testUser = new User();
    Screen* testCity = new City("cityScreen.txt", testUser);
    Screen* resultCity = testCity->processOption(5, true);
    ItemManager* userItemManager = testUser->getItemManager();
    EXPECT_EQ(testCity, resultCity);
    EXPECT_TRUE(userItemManager->getWeaponInventory()->size() == 0 && userItemManager->getArmorInventory()->size() == 0 && userItemManager->getTrinketInventory()->size() == 0);
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