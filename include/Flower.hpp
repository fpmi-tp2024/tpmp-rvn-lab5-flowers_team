#pragma once

#include <string>
class Flower
{
    private:
    int id_flower;
    std::string flower_name;
    std::string variety;
    int flower_cost;
    
    public:
    Flower() = default;
    Flower(int _id_flower, std::string _flower_name, std::string _variety, int _flower_cost) : id_flower(_id_flower), 
    flower_name(_flower_name), variety(_variety), flower_cost(_flower_cost){}
    ~Flower() = default;
    void SetIdFlower(int _id_flower);
    int GetIdFlower() const;
    void SetFlowerName(std::string _flower_name);
    std::string GetFlowerName() const;
    void SetVariety(std::string _variety);
    std::string GetVariety() const;
    void SetFlowerCost(int _flower_cost);
    int GetFlowerCost() const;
};