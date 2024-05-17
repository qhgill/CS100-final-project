#include <gtest/gtest.h>
#include "../header/user.h"

TEST(userGetterTests, getUserLevel){
    User u;
    EXPECT_EQ(u.getLevel(), 1);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}