#pragma once

#include <string>
#include <SQLiteCpp/SQLiteCpp.h>
#include "../include/User.hpp"
class Command
{
protected:
    std::string description;

public:
    Command(std::string desc) : description(desc) {}

    std::string GetDescription() const { return description; }

    virtual void execute(SQLite::Database &db, std::optional<User>user_info = std::nullopt ) = 0;
    virtual ~Command() = default;

};