
#include <iostream>
#include <string>
#include "../include/Authorization.hpp"

Authorization::Authorization() : AccessCommand("Authorization") {}

bool Authorization::FindUser(SQLite::Database &db, User &user)
{
    SQLite::Statement query(db, "SELECT id, login, password, role FROM Users WHERE login = ? AND password = ?;");
    query.bind(1, user.GetLogin());
    query.bind(2, user.GetHashPassword());
    bool is_user_found = false;
    try
    {
        while (query.executeStep())
        {
            user.SetUserId(query.getColumn(0).getInt());
            user.SetUserRole(query.getColumn(3).getString() == "S" ? User_Role::Simple_User : User_Role::Admin);
            is_user_found = true;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    if (!is_user_found)
        std::cout << "Error: there is no such user in the system. Please enter your credentials again!" << std::endl;
    return is_user_found;
}
User Authorization::execute(SQLite::Database &db)
{
    std::string login, password, hash_password;
    std::hash<std::string> hasher;
    User user{};

    while (true)
    {
        std::cout << "Enter login: " << std::endl;
        std::getline(std::cin, login);

        std::cout << "Enter password: " << std::endl;
        std::getline(std::cin, password);

        hash_password = std::to_string(hasher(password));

        user.SetUserLogin(login);
        user.SetUserHashPassword(hash_password);
        if (FindUser(db, user))
        {
            std::cout << "Authorization completed successfully!" << std::endl;
            break;
        }
    }

    return user;
}