#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../header/bosspart1.h"
#include "../header/bosspart2.h"
#include "../header/bosspart3.h"
#include "../header/bosspart4.h"

TEST(getterTests, inheritanceTest) {
    BossPart1 tempBoss();

    ASSERT_EQ(tempBoss.getLevel(), 0);
    ASSERT_EQ(tempBoss.getHealth(), 0);
    ASSERT_EQ(tempBoss.getMaxHealth(), 0);
    ASSERT_EQ(tempBoss.getDamage(), 0);
    ASSERT_EQ(tempBoss.getMagicResist(), 0);
    ASSERT_EQ(tempBoss.getPhysicalResist(), 0);
    ASSERT_EQ(tempBoss.getStatus(), false);
    ASSERT_EQ(tempBoss.getName(), "");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
