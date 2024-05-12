#include "../include/AccessCommand.hpp"

AccessCommand::AccessCommand(std::string desc) : description(desc) {}
std::string AccessCommand::GetDescription() const { return description; }
AccessCommand::~AccessCommand() = default;