#include "../include/CommandManager.hpp"
#include <iostream>

int main()
{
    CommandManager manager("db/flower.db");
    manager.Start();
    return 0;
}
