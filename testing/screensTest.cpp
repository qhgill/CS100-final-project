#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../header/screens/screen.h"
#include "../header/screens/city.h"

TEST(screenAbstractTest, constructorTest){
    EXPECT_NO_THROW(Screen* testscreen = new City("filename", nullptr););
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
