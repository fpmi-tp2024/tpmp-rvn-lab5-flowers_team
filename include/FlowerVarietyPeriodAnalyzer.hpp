#pragma once
#include "../include/Command.hpp"

class FlowerVarietyPeriodAnalyzer: public Command
{
public:
    FlowerVarietyPeriodAnalyzer();
    void execute(SQLite::Database &db , std::optional<User>user_info = std::nullopt) override;
    ~FlowerVarietyPeriodAnalyzer() = default;
};