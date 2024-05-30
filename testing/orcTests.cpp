#include <gtest/gtest.h>
#include "../header/orc.h"

TEST(getterTests, constructorInitializationTest) {
    Orc orc;

    EXPECT_EQ(orc.getLevel(), 3);
    EXPECT_EQ(orc.getHealth(), 60);
    EXPECT_EQ(orc.getMaxHealth(), 60);
    EXPECT_EQ(orc.getDamage(), 8);
    EXPECT_EQ(orc.getMagicResist(), 3);
    EXPECT_EQ(orc.getPhysicalResist(), 8);
    EXPECT_EQ(orc.getName(), std::string("Orc").c_str());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}