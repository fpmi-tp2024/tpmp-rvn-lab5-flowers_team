#pragma once
#include "../include/Command.hpp"

class OrderPeriodProfitAnalyzer : public Command {

public:
    OrderPeriodProfitAnalyzer();
    void execute(SQLite::Database &db , std::optional<User>user_info = std::nullopt) override;
    ~OrderPeriodProfitAnalyzer() = default;
};