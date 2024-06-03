#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../header/item.h"
using std::string;

class MockItem: public Item{
  public:
  MockItem(string name, int level, string type): Item(name, level, type){}
    MOCK_METHOD((int), calcValue, (), (override));
};

TEST(ItemTests, constructorTests)
{
    EXPECT_NO_THROW({
      MockItem testItem("name", 2, "weapon");
    });
}

TEST(ItemTests, getNameTest){
  MockItem testItem("name", 2, "weapon");
  EXPECT_EQ(testItem.getName(), "name");
}

TEST(ItemTests, getLevelTest){
  MockItem testItem("name", 2, "weapon");
  EXPECT_EQ(testItem.getLevel(), 2);
}

TEST(ItemTests, getTypeTest){
  MockItem testItem("name", 2, "weapon");
  EXPECT_EQ(testItem.getType(), "weapon");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
