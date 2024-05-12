#include "../include/User.hpp"

User::User(std::string _login, std::string _hash_password, User_Role _role) : login(_login),
                                                                              hash_password(_hash_password), role(_role) {}

void User::SetUserId(int id)
{
    user_id = id;
}

void User::SetUserLogin(std::string _login)
{
    login = _login;
}
void User::SetUserHashPassword(std::string _hash_password)
{
    hash_password = _hash_password;
}
void User::SetUserRole(User_Role _role)
{
    role = _role;
}
int User::GetUserId() const { return user_id; }
std::string User::GetLogin() const { return login; }
std::string User::GetHashPassword() const { return hash_password; }
User_Role User::GetUserRole() const { return role; }
User::~User() = default;