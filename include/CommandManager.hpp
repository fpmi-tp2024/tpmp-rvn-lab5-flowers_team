#pragma once

#include <map>
#include <memory>

#include "../include/Authorization.hpp"
#include "../include/Registration.hpp"
class CommandManager
{
private:
    void InitAccessCommands();
    void PrintAccessCommands();

public:
    CommandManager(std::string db_path);
    ~CommandManager();
    void Start();

private:
    std::map<int, std::shared_ptr<AccessCommand>> access_command_table;
    SQLite::Database db;
};