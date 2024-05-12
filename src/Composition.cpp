#include <iostream>
#include "../include/Composition.hpp"

Composition::Composition() = default;
Composition::Composition(int _id_composition, std::string _composition_name, int _composition_cost) : id_composition(_id_composition),
                                                                                                      composition_name(_composition_name),
                                                                                                      composition_cost(_composition_cost) {}
void Composition::SetIdComposition(int _id_composition)
{
    id_composition = _id_composition;
}
int Composition::GetIdComposition() const
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
    flowers.emplace_back(Flower(_id_flower, _flower_name, _variety, _flower_cost), flower_count);
}

Composition::~Composition()
{
    flowers.clear();
}

std::ostream &operator<<(std::ostream &out, const Composition &composition)
{
    out << "Composition information:\n";
    out << "Composition id = " << composition.id_composition << '\n';
    out << "Composition name: " << composition.composition_name << '\n';
    out << "Composition cost: " << composition.composition_cost << "\n\n";
    if (composition.flowers.empty())
    {
        out << "No flowers in this composition!\n\n";
    }
    else
    {
        out << "All information about the flowers included in the composition:\n\n";
        for (const auto &flower_info : composition.flowers)
        {
            out << flower_info.first;
            out << "Flower count: " << flower_info.second << "\n\n";
        }
    }
    return out;
}