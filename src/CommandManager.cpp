#include "../include/CommandManager.hpp"

#include <iostream>
CommandManager::CommandManager(std::string db_path) : db(db_path, SQLite::OPEN_READWRITE)
{
    InitAccessCommands();
}

void CommandManager::InitAccessCommands()
{
    access_command_table = {
        {1, std::make_shared<Authorization>()},
        {2, std::make_shared<Registration>()}};
}

void CommandManager::Start()
{
    int op_id = -1;
    User user{};
    while (true)
    {
        PrintAccessCommands();
        std::cin >> op_id;
        std::cin.get();
        if (!op_id)
            break;
        if (access_command_table.find(op_id) == access_command_table.end())
        {
            std::cout << "Invalid command. Please, try again!" << std::endl;
        }
        else
        {
            user = access_command_table[op_id]->execute(db);
            break;
        }
    }

    if (!op_id)
        return;
    // to do : menu for admin or menu for user according to role
}

void CommandManager::PrintAccessCommands()
{
    std::cout << "Access menu: " << std::endl;
    std::cout << "0. Exit" << std::endl;
    for (const auto &command : access_command_table)
    {
        std::cout << command.first << ". " << command.second->GetDescription() << std::endl;
    }
}