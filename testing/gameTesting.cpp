#include <gtest/gtest.h>
#include "../header/game.h"

TEST(gameTests, constructorTest){
    EXPECT_NO_THROW({
        Game game1 = Game();
    });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}