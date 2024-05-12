#include "../include/Command.hpp"

Command::Command(std::string desc) : description(desc) {}
std::string Command::GetDescription() const { return description; }
Command::~Command() = default;