#pragma once

#include <string>
#include <vector>
#include "../include/Flower.hpp"

class Composition
{
public:
    Composition();
    Composition(int _id_composition, std::string _composition_name, int _composition_cost);
    void AddFlower(int _id_flower, std::string _flower_name, std::string _variety, int _flower_cost, int flower_count);
    void SetIdComposition(int _id_composition);
    void SetCompositionName(std::string _composition_name);
    void SetCompositionCost(int _composition_cost);
    int GetIdComposition() const;
    std::string GetCompositionName() const;
    int GetCompositionCost() const;
    ~Composition();

    friend std::ostream &operator<<(std::ostream &out, const Composition &composition);

private:
    int id_composition;
    int composition_cost;
    std::string composition_name;
    std::vector<std::pair<Flower, int>> flowers;
};