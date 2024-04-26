#include <gtest/gtest.h>
#include "../include/Validator.hpp"
#include "../include/Registration.hpp"

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
TEST(ValidationTest, ValidLogin)
{
    ASSERT_TRUE(Validator::ValidateLogin("hello23"));
}
TEST(ValidationTest, InvalidLogin)
{
    ASSERT_FALSE(Validator::ValidateLogin("4567"));
    ASSERT_FALSE(Validator::ValidateLogin("HU@hhk"));
}
TEST(RegistrationTest, AddUser)
{
    SQLite::Database db("../db/flower.db", SQLite::OPEN_READWRITE);
    std::hash<std::string> hasher;
    std::string hash_password = std::to_string(hasher("wqr8t321"));
    std::string login = "valya234";
    Registration registration;
    User user{login, hash_password};
    ASSERT_TRUE(registration.AddUser(db,user));
}
TEST(RegistrationTest, AddExistingUser)
{
    SQLite::Database db("../db/flower.db", SQLite::OPEN_READWRITE);
    std::hash<std::string> hasher;
    std::string hash_password = std::to_string(hasher("12345678"));
    std::string login = "hello23";
    Registration registration;
    User user{login, hash_password};
    ASSERT_FALSE(registration.AddUser(db,user));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
