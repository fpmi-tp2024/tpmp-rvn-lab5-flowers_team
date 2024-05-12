#pragma once

#include <string>
class Flower
{
public:
    Flower();
    Flower(int _id_flower, std::string _flower_name, std::string _variety, int _flower_cost);
    void SetIdFlower(int _id_flower);
    void SetFlowerName(std::string _flower_name);
    void SetVariety(std::string _variety);
    void SetFlowerCost(int _flower_cost);
    int GetIdFlower() const;
    std::string GetFlowerName() const;
    std::string GetVariety() const;
    int GetFlowerCost() const;
    ~Flower();

private:
    int id_flower;
    std::string flower_name;
    std::string variety;
    int flower_cost;
};