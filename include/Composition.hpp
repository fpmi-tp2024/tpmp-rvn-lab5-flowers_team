#pragma once

#include "../include/Flower.hpp"
#include <string>
#include <vector>

class Composition
{
private:
    int id_composition;
    std::string composition_name;
    int composition_cost;
    std::vector<std::pair<Flower, int>> flowers;

public:
    Composition() = default;
    Composition(int _id_composition, std::string _composition_name, int _composition_cost) : id_composition(_id_composition),
    composition_name(_composition_name), composition_cost(_composition_cost) {}
    ~Composition();
    void AddFlower(int _id_flower, std::string _flower_name, std::string _variety, int _flower_cost, int flower_count);
    void SetIdComposition(int _id_composition);
    int GetIdComposition() const;
    void SetCompositionName(std::string _composition_name);
    std::string GetCompositionName() const;
    void SetCompositionCost(int _composition_cost);
    int GetCompositionCost() const;
    std::string toString();
};