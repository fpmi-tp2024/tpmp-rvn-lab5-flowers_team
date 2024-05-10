#include "../include/FlowerCostUpdate.hpp"
#include <string>
#include <iostream>
#include <SQLiteCpp/Transaction.h>
#include "../include/Composition.hpp"

FlowerCostUpdate::FlowerCostUpdate() : Command("Update flower cost") {}
bool FlowerCostUpdate::FindFlower(SQLite::Database &db, Flower &flower)
{
    SQLite::Statement query_flower(db, "SELECT id, flower_name, variety, flower_cost FROM Flower WHERE flower_name = ?;");
    query_flower.bind(1, flower.GetFlowerName());
    bool is_flower_find = false;
    try
    {
        while (query_flower.executeStep())
        {
            flower.SetIdFlower(query_flower.getColumn(0).getInt());
            flower.SetVariety(query_flower.getColumn(2).getString());
            flower.SetFlowerCost(query_flower.getColumn(3).getInt());
            is_flower_find = true;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return is_flower_find;
}
void FlowerCostUpdate::CompositionCostUpdate(SQLite::Database &db, Flower &flower, int &new_cost)
{
    int diff_sum = new_cost - flower.GetFlowerCost();
    flower.SetFlowerCost(new_cost);
    SQLite::Transaction transaction(db);
    try
    {

        SQLite::Statement query_flower_new_cost(db, "UPDATE Flower SET flower_cost = ? WHERE id = ?;");
        query_flower_new_cost.bind(1, flower.GetFlowerCost());
        query_flower_new_cost.bind(2, flower.GetIdFlower());
        query_flower_new_cost.exec();
        SQLite::Statement query_composition_cost(db, "WITH Composition_Flower_Count(id, flower_count) AS \
        (SELECT Composition_flower.composition_id, Composition_flower.flower_count FROM Composition_flower where id_flower = ?) \
        UPDATE Composition SET composition_cost = composition_cost + ? * Composition_Flower_Count.flower_count \
        FROM Composition_Flower_Count WHERE Composition.id = Composition_Flower_Count.id;");
        query_composition_cost.bind(1, flower.GetIdFlower());
        query_composition_cost.bind(2, diff_sum);
        query_composition_cost.exec();
        transaction.commit();
        std::cout<<"Cost for flower successfully updated!"<<std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        transaction.rollback();
        std::cout<<"Error with update flower cost"<<std::endl;
    }
}
void FlowerCostUpdate::execute(SQLite::Database &db, std::optional<User> user_info)
{

    Flower flower{};
    std::string flower_name;
    int new_cost;
    while (true)
    {
        std::cout << "Enter the name of the flower for which you want to change the price: " << std::endl;
        std::getline(std::cin, flower_name);
        flower.SetFlowerName(flower_name);
        std::cout << "Enter new cost for flower: " << std::endl;
        std::cin >> new_cost;
        if (FindFlower(db, flower))
        {
            break;
        }
        std::cout << "No such flower. Please, try again!" << std::endl;
    }
    CompositionCostUpdate(db,flower,new_cost);
}