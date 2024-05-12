#pragma once

#include <string>
#include <optional>
#include <SQLiteCpp/SQLiteCpp.h>
#include "../include/User.hpp"
class Command
{
public:
    Command(std::string desc);
    std::string GetDescription() const;
    virtual void execute(SQLite::Database &db, std::optional<User> user_info = std::nullopt) = 0;
    virtual ~Command();

protected:
    std::string description;
};