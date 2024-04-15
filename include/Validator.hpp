#pragma once

#include <string>
#include <cctype>

class Validator
{
public:
    static bool ValidatePassword(std::string &password)
    {
        return password.size() >= 8;
    }
    static bool ValidateLogin(std::string &login)
    {
        for (const auto &ch : login)
        {
            if (!std::isdigit(ch) && !std::isalpha(ch))
            {
                return false;
            }
        }
        return login.size() >= 5;
    }
};