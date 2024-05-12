#pragma once

#include <string>
#include <SQLiteCpp/SQLiteCpp.h>
#include "User.hpp"

class AccessCommand
{
public:
    AccessCommand(std::string desc);
    std::string GetDescription() const;
    virtual User execute(SQLite::Database &db) = 0;
    virtual ~AccessCommand();

protected:
    std::string description;
};