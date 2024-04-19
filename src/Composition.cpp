#include "../include/Composition.hpp"
#include <iostream>
void Composition::SetIdComposition(int _id_composition)
{
    id_composition = _id_composition;
}
int Composition::GetIdComposition()const
{
    return id_composition;
}
void Composition::SetCompositionName(std::string _composition_name)
{
    composition_name = _composition_name;
}
std::string Composition::GetCompositionName() const
{
    return composition_name;
}
void Composition::SetCompositionCost(int _composition_cost)
{
    composition_cost = _composition_cost;
}
int Composition::GetCompositionCost() const
{
    return composition_cost;
}

void Composition::AddFlower(int _id_flower, std::string _flower_name, std::string _variety, int _flower_cost, int flower_count) 
{
    flowers.emplace_back(Flower(_id_flower,_flower_name, _variety,_flower_cost), flower_count);
}

std::string Composition::toString() 
{
    std::string result;
    for (const auto& pair : flowers) {
        result += "Flower id = " + std::to_string(pair.first.GetIdFlower()) + "\n";
        result += "Flower name: " + pair.first.GetFlowerName() + "\n";
        result += "Flower variety: " + pair.first.GetVariety() + "\n";
        result += "Flower cost: " + std::to_string(pair.first.GetFlowerCost()) + "\n";
        result += "Flower count: " + std::to_string(pair.second) + "\n";
         result += "\n";
    }
    return result;
}
Composition:: ~Composition()
{
    flowers.clear();
}

    
