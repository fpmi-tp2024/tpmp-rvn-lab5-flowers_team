#include <iostream>
#include "../include/CommandManager.hpp"

int main()
{
    CommandManager manager("db/flower.db");
    manager.Start();
    return 0;
}
