#include <gtest/gtest.h>
#include "../header/screens/screen.h"

TEST(travelTests, displayTest){
    Screen* travel = new Travel("travelScreen.txt", nullptr);
    EXPECT_NO_THROW(travel->displayScreen());
}

TEST(travelTests, processOptionNot1or2){
    bool dummyRunning = true;
    Screen* travel = new Travel("travelScreen.txt", nullptr);
    EXPECT_EQ(travel->processOption(0, dummyRunning), travel);
}

TEST(travelTests, processOption1){
    bool dummyRunning = true;
    Screen* travel = new Travel("travelScreen.txt", nullptr);
    EXPECT_NE(travel->processOption(1, dummyRunning), travel);
}

TEST(travelTests, processOption2){
    bool dummyRunning = true;
    Screen* travel = new Travel("travelScreen.txt", nullptr);
    EXPECT_NE(travel->processOption(2, dummyRunning), travel);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
