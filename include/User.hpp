#pragma once
#include <string>

enum class User_Role{Simple_User, Admin};

class User{

    private:
    int user_id;
    std::string login;
    std::string hash_password;
    User_Role role;
    
};