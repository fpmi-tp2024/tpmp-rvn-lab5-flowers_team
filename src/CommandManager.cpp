#include <iostream>
#include "../include/CommandManager.hpp"

CommandManager::CommandManager(std::string db_path) : db(db_path, SQLite::OPEN_READWRITE)
{
    InitAccessCommands();
    InitCommandsSimpleUser();
    InitCommandsAdmin();
}

void CommandManager::InitAccessCommands()
{
    access_command_table = {
        {1, std::make_shared<Authorization>()},
        {2, std::make_shared<Registration>()}};
}

void CommandManager::InitCommandsSimpleUser()
{
    simple_user_command_table = {
        {1, std::make_shared<CompositionMaxDemandAnalyzer>()},
        {2, std::make_shared<InfoAboutOrder>()},
        {3, std::make_shared<NewOrderCostCalculator>()}};
}
void CommandManager::InitCommandsAdmin()
{
    admin_command_table = {
        {1, std::make_shared<CompositionSelector>()},
        {2, std::make_shared<CompositionProfitAnalyzer>()},
        {3, std::make_shared<CompositionMaxDemandAnalyzer>()},
        {4, std::make_shared<InfoAboutOrder>()},
        {5, std::make_shared<NewOrderCostCalculator>()},
        {6, std::make_shared<OrderPeriodCountAnalyzer>()},
        {7, std::make_shared<OrderPeriodProfitAnalyzer>()},
        {8, std::make_shared<FlowerCostUpdate>()}};
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
    if (user.GetUserRole() == User_Role::Admin)
    {
        CommandsWorker(admin_command_table, user);
    }
    else
    {
        CommandsWorker(simple_user_command_table, user);
    }
}

void CommandManager::PrintAccessCommands() const
{
    std::cout << "Access menu: " << std::endl;
    std::cout << "0. Exit" << std::endl;
    for (const auto &command : access_command_table)
    {
        std::cout << command.first << ". " << command.second->GetDescription() << std::endl;
    }
}

void CommandManager::PrintCommands(const std::map<int, std::shared_ptr<Command>> &commands) const
{
    std::cout << "Commands menu: " << std::endl;
    std::cout << "0. Exit" << std::endl;
    for (const auto &command : commands)
    {
        std::cout << command.first << ". " << command.second->GetDescription() << std::endl;
    }
}

void CommandManager::CommandsWorker(const std::map<int, std::shared_ptr<Command>> &commands, const User &user)
{
    int op_id = -1;
    while (true)
    {
        PrintCommands(commands);
        std::cin >> op_id;
        std::cin.get();
        if (!op_id)
            break;
        if (commands.find(op_id) == commands.end())
        {
            std::cout << "Invalid command. Please, try again!" << std::endl;
        }
        else
        {
            commands.at(op_id)->execute(db, user);
        }
    }
}
CommandManager::~CommandManager() = default;