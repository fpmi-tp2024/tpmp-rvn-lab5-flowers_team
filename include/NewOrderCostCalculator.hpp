#pragma once
#include "../include/Command.hpp"
#include "../include/Order.hpp"
class NewOrderCostCalculator: public Command
{
    public:
    NewOrderCostCalculator();
    bool RegistrationNewOrder(SQLite::Database &db, Order &order,const int &composition_cost);

    void execute(SQLite::Database &db , std::optional<User>user_info = std::nullopt) override;
    ~NewOrderCostCalculator() = default;
};