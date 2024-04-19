#pragma once

#include "../include/Command.hpp"

class CompositionSelector: public Command
{
    public:
    CompositionSelector();
    void execute(SQLite::Database &db , std::optional<User>user_info = std::nullopt) override;
    ~CompositionSelector() =default;
    
};