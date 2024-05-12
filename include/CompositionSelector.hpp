#pragma once

#include "../include/Command.hpp"
#include "../include/Composition.hpp"

class CompositionSelector : public Command
{
public:
    CompositionSelector();
    void execute(SQLite::Database &db, std::optional<User> user_info = std::nullopt) override;
    bool GetComposition(Composition &composition, SQLite::Database &db);
    bool GetFlowerComposition(Composition &composition, SQLite::Database &db);
    ~CompositionSelector();
};