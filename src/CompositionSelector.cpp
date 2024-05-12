#include <iostream>
#include "../include/CompositionSelector.hpp"

CompositionSelector::CompositionSelector() : Command("Get info about composition\n") {}

bool CompositionSelector::GetComposition(Composition &composition, SQLite::Database &db)
{
    SQLite::Statement query(db, "SELECT id, composition_name, composition_cost FROM Composition WHERE composition_name = ?;");
    query.bind(1, composition.GetCompositionName());
    bool is_composition_find = false;
    try
    {
        while (query.executeStep())
        {
            composition.SetIdComposition(query.getColumn(0).getInt());
            composition.SetCompositionName(query.getColumn(1).getString());
            composition.SetCompositionCost(query.getColumn(2).getInt());
            is_composition_find = true;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    if (!is_composition_find)
    {
        std::cout << "No composition with name " << composition.GetCompositionName() << std::endl;
    }
    return is_composition_find;
}

bool CompositionSelector::GetFlowerComposition(Composition &composition, SQLite::Database &db)
{
    Flower flower{};
    SQLite::Statement query(db, "SELECT Flower.id, Flower.flower_name, Flower.variety, Flower.flower_cost, Composition_flower.flower_count \
    FROM Composition_flower INNER JOIN Flower ON Composition_flower.id_flower = Flower.id \
    WHERE Composition_flower.composition_id = ?;");
    query.bind(1, composition.GetIdComposition());
    bool is_flower_composition_find = false;
    try
    {
        while (query.executeStep())
        {
            flower.SetIdFlower(query.getColumn(0).getInt());
            flower.SetFlowerName(query.getColumn(1).getString());
            flower.SetVariety(query.getColumn(2).getString());
            flower.SetFlowerCost(query.getColumn(3).getInt());
            composition.AddFlower(flower.GetIdFlower(), flower.GetFlowerName(), flower.GetVariety(),
                                  flower.GetFlowerCost(), query.getColumn(4).getInt());
            is_flower_composition_find = true;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return is_flower_composition_find;
}

void CompositionSelector::execute(SQLite::Database &db, std::optional<User> user_info)
{
    std::string composition_name;
    Composition composition{};
    std::cout << "Enter composition name: " << std::endl;
    std::getline(std::cin, composition_name);
    std::cout << std::endl;
    composition.SetCompositionName(composition_name);

    if (GetComposition(composition, db))
    {
        GetFlowerComposition(composition, db);
        std::cout << composition << std::endl;
    }
}

CompositionSelector::~CompositionSelector() = default;