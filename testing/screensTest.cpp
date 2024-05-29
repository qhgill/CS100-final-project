#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../header/screens/screen.h"
#include "../header/screens/city.h"
#include "../header/user.h"

class MockScreen : public Screen{
  public:
    MockScreen(std::string filename, User* user): Screen(filename, user){}
    MOCK_METHOD((Screen*), processOption, (int, bool), (override));
    MOCK_METHOD((void), displayScreen, (), (override));
};

TEST(screenAbstractTest, constructorTest){
    EXPECT_NO_THROW(Screen* testscreen = new MockScreen("filename", nullptr););
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
