#pragma once
#include "../include/Command.hpp"

class CompositionProfitAnalyzer: public Command
{
    public:
    CompositionProfitAnalyzer();
    void execute(SQLite::Database &db , std::optional<User>user_info = std::nullopt) override;
    ~CompositionProfitAnalyzer() = default;
};