#pragma once

#include <string>
#include <SQLiteCpp/SQLiteCpp.h>
#include "User.hpp"

class AccessCommand{

    protected:
    std::string description;

    public:
    AccessCommand(std::string desc): description(desc){}

    std::string GetDescription() const {return description;}

    virtual User execute(SQLite::Database& db) = 0;
    virtual ~AccessCommand() = default;
};