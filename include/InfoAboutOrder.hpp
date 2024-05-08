#pragma once

#include "../include/Command.hpp"

class InfoAboutOrder : public Command
{
    public:
    InfoAboutOrder();
    void execute(SQLite::Database &db, std::optional<User> user_info = std::nullopt) override;
    ~InfoAboutOrder() = default;
};