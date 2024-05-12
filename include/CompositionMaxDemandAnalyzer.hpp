#pragma once
#include "../include/Command.hpp"

class CompositionMaxDemandAnalyzer : public Command
{
public:
    CompositionMaxDemandAnalyzer();
    void execute(SQLite::Database &db, std::optional<User> user_info = std::nullopt) override;
    ~CompositionMaxDemandAnalyzer();
};