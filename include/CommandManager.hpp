#pragma once

#include <map>
#include <memory>

#include "../include/Authorization.hpp"
#include "../include/Registration.hpp"
#include "../include/CompositionSelector.hpp"
#include "../include/CompositionProfitAnalyzer.hpp"
#include "../include/CompositionMaxDemandAnalyzer.hpp"
#include "../include/FlowerVarietyPeriodAnalyzer.hpp"
#include "../include/FlowerCostUpdate.hpp"
#include "../include/OrderPeriodCountAnalyzer.hpp"
#include "../include/OrderPeriodProfitAnalyzer.hpp"
#include "../include/InfoAboutOrder.hpp"
#include "../include/NewOrderCostCalculator.hpp"

class CommandManager
{
private:
    void InitAccessCommands();
    void PrintAccessCommands() const;
    void InitCommandsSimpleUser();
    void InitCommandsAdmin();
    void PrintCommands(const std::map<int, std::shared_ptr<Command>>& commands) const;
    void CommandsWorker(const std::map<int, std::shared_ptr<Command>>& commands, const User &user);
public:
    CommandManager(std::string db_path);
    ~CommandManager();
    void Start();

private:
    std::map<int, std::shared_ptr<AccessCommand>> access_command_table;
    std::map<int, std::shared_ptr<Command>> simple_user_command_table;
    std::map<int, std::shared_ptr<Command>> admin_command_table;
    SQLite::Database db;
};