#include <iostream>
#include <string>
#include "../include/Registration.hpp"
#include "../include/Validator.hpp"

Registration::Registration() : AccessCommand("Registration") {}

bool Registration::AddUser(SQLite::Database &db, User &user)
{
    SQLite::Statement query(db, "INSERT INTO Users(login, password, role) VALUES(?, ?, ?) RETURNING id, login, password, role;");
    query.bind(1, user.GetLogin());
    query.bind(2, user.GetHashPassword());
    query.bind(3, user.GetUserRole() == User_Role::Simple_User ? "S" : "A");
    bool is_user_add = false;
    try
    {
        while (query.executeStep())
        {
            user.SetUserId(query.getColumn(0).getInt());
        }
        is_user_add = true;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: a user with this login exists. Please enter your credentials again!" << std::endl;
    }
    return is_user_add;
}

User Registration::execute(SQLite::Database &db)
{
    std::string login, password, hash_password;
    std::hash<std::string> hasher;
    User user{};
    user.SetUserRole(User_Role::Simple_User);

    while (true)
    {
        while (true)
        {
            std::cout << "Enter login: " << std::endl;
            std::getline(std::cin, login);
            if (!Validator::ValidateLogin(login))
            {
                std::cout << "Invalid login. Please, try again!" << std::endl;
            }
            else
                break;
        }

        while (true)
        {
            std::cout << "Enter password: " << std::endl;
            std::getline(std::cin, password);
            if (!Validator::ValidatePassword(password))
            {
                std::cout << "Invalid password. Please, try again!" << std::endl;
            }
            else
                break;
        }

        hash_password = std::to_string(hasher(password));

        user.SetUserLogin(login);
        user.SetUserHashPassword(hash_password);
        if (AddUser(db, user))
        {
            std::cout << "User added successfully!" << std::endl;
            break;
        }
    }

    return user;
}