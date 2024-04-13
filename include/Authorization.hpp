#pragma once

#include "AccessCommand.hpp"

class Authorization : public AccessCommand
{
public:
    Authorization();
    User execute(SQLite::Database &db) override;
    ~Authorization() = default;
};
