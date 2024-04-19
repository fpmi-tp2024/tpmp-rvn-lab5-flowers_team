#include "../include/CompositionSelector.hpp"
#include "../include/Composition.hpp"

#include <iostream>
CompositionSelector::CompositionSelector(): Command("Get info about composition\n"){}
void CompositionSelector::execute(SQLite::Database &db, std::optional<User> user_info)
{
    std::string composition_name;
    Flower flower{};
    Composition composition{};
    std::cout << "Enter composition name: " << std::endl;
    std::getline(std::cin, composition_name);

    SQLite::Statement query(db, "SELECT id, composition_name, composition_cost FROM Composition WHERE composition_name = ?;");
    query.bind(1, composition_name);
    bool is_composition_find = false;
    try
    {
        while (query.executeStep())
        {
            composition.SetIdComposition(query.getColumn(0).getInt());
            composition.SetCompositionName(query.getColumn(1).getString());
            composition.SetCompositionCost(query.getColumn(2).getInt());
        }
        is_composition_find = true;
    }
    catch (const std::exception &e)
    {
        std::cout << "No composition witn name " << composition_name << std::endl;
    }

    if (!is_composition_find)
        return;

    SQLite::Statement query_flower(db, "SELECT Flower.id, Flower.flower_name, Flower.variety, Flower.flower_cost, Composition_flower.flower_count FROM Composition_flower INNER JOIN Flower ON Composition_flower.id_flower = Flower.id WHERE Composition_flower.composition_id = ?;");
    query_flower.bind(1, composition.GetIdComposition());
    bool is_flower_composition_find = false;
    try
    {
        while (query_flower.executeStep())
        {
            flower.SetIdFlower(query_flower.getColumn(0).getInt());
            flower.SetFlowerName(query_flower.getColumn(1).getString());
            flower.SetVariety(query_flower.getColumn(2).getString());
            flower.SetFlowerCost(query_flower.getColumn(3).getInt());
            composition.AddFlower(flower.GetIdFlower(), flower.GetFlowerName(), flower.GetVariety(), flower.GetFlowerCost(), query_flower.getColumn(4).getInt());
        }
        is_flower_composition_find = true;
    }
    catch (const std::exception &e)
    {
        std::cout << "No information! " << std::endl;
    }

    if (!is_flower_composition_find)
        return;

    std::cout<<"Composition information"<<std::endl;
    std::cout << "Composition id = " << composition.GetIdComposition() << std::endl;
    std::cout << "Composition name: " << composition.GetCompositionName() << std::endl;
    std::cout<< "Composition cost: "<< composition.GetCompositionCost() << std::endl;
    std::cout<<std::endl;
    std::cout<<"All information about the colors included in the composition"<<std::endl;
    std::cout<< composition.toString()<<std::endl;

}