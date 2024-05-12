#pragma once

#include "AccessCommand.hpp"

class Authorization : public AccessCommand
{
public:
    Authorization();
    bool FindUser(SQLite::Database &db, User &user);
    User execute(SQLite::Database &db) override;
    ~Authorization();
};
