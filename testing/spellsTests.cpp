#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../header/spell.h"

class MockSpell: public Spell{
    public:
        MockSpell(const std::string& sc, int slt): Spell(sc, slt) {}
        MOCK_METHOD((void), doSpell, (int&, int&, int, int&, Enemy*), (override));
};

TEST(getterTests, getSpellClass){
    MockSpell mockSpell("Class1", 1);
    std::string spellClass = mockSpell.getSpellClass();
    EXPECT_TRUE(spellClass == "Class1");
}

TEST(getterTests, getSpellLevelThreshold){
    MockSpell mockSpell("Class1", 1);
    int spellLevelThreshold = mockSpell.getSpellLevelThreshold();
    EXPECT_EQ(spellLevelThreshold, 1);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
