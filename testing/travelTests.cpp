#include <gtest/gtest.h>
#include "../header/screens/screen.h"
#include "../header/screens/travel.h"

TEST(travelTests, displayTest){
    Screen* travel = new Travel("travelScreen.txt", nullptr);
    EXPECT_NO_THROW(travel->displayScreen());
}

TEST(travelTests, processOptionNot1or2){
    Screen* travel = new Travel("travelScreen.txt", nullptr);
    EXPECT_EQ(travel->processOption(0, true), travel);
}
//more tests later when other components are more implemented

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
