#include <gtest/gtest.h>
#include "../include/Validator.hpp"

TEST(ValidationTest, ValidPassword)
{
    ASSERT_TRUE(Validator::ValidatePassword("12345678"));
}
TEST(ValidationTest, InvalidPassword)
{
    ASSERT_FALSE(Validator::ValidatePassword("15678"));
    ASSERT_FALSE(Validator::ValidatePassword("123"));
    ASSERT_FALSE(Validator::ValidatePassword("@dow3"));
}
TEST(ValidationTest, ValidationLogin)
{
    ASSERT_TRUE(Validator::ValidateLogin("hello23"));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
