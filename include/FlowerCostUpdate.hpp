#pragma once

#include "../include/Command.hpp"
#include "../include/Flower.hpp"

class FlowerCostUpdate : public Command
{
public:
    FlowerCostUpdate();
    bool FindFlower(SQLite::Database &db, Flower &flower);
    void CompositionCostUpdate(SQLite::Database &db, Flower &flower, int &new_cost);
    void execute(SQLite::Database &db, std::optional<User> user_info = std::nullopt) override;
    ~FlowerCostUpdate();
};