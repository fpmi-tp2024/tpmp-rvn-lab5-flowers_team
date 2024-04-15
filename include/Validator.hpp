#pragma once

#include <string>
#include <cctype>

class Validator
{
private:
    static const int kPasswordMinLength = 8;
    static const int kLoginMinLength = 5;

public:
    static bool ValidatePassword(std::string &password)
    {
        return password.size() >= kPasswordMinLength;
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
        return login.size() >= kLoginMinLength;
    }
};