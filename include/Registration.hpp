#pragma once

#include "AccessCommand.hpp"

class Registration: public AccessCommand{
    public:
    Registration();
    User execute(SQLite::Database& db) override;
    ~Registration() = default;
};
