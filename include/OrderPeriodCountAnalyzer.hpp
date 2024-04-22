#pragma once
#include "../include/Command.hpp"

class OrderPeriodCountAnalyzer : public Command {

public:
    OrderPeriodCountAnalyzer();
    void execute(SQLite::Database &db , std::optional<User>user_info = std::nullopt) override;
    ~OrderPeriodCountAnalyzer() = default;
};