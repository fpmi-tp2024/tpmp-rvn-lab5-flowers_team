#pragma once

#include "AccessCommand.hpp"

class Registration : public AccessCommand
{
public:
    Registration();
    bool AddUser(SQLite::Database &db, User &user);
    User execute(SQLite::Database &db) override;
    ~Registration();
};
