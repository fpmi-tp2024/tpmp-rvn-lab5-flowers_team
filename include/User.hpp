#pragma once
#include <string>

enum class User_Role
{
    Simple_User,
    Admin
};

class User
{

private:
    int user_id;
    std::string login;
    std::string hash_password;
    User_Role role;

public:
    User() = default;
    User(std::string _login, std::string _hash_password, User_Role _role = User_Role::Simple_User) : login(_login), hash_password(_hash_password), role(_role) {}
    void SetUserId(int id);
    void SetUserLogin(std::string _login);
    void SetUserHashPassword(std::string _hash_password);
    void SetUserRole(User_Role _role);
    int GetUserId() const;
    std::string GetLogin() const;
    std::string GetHashPassword() const;
    User_Role GetUserRole() const;
    ~User() = default;
};