#include "../include/Flower.hpp"

void Flower::SetIdFlower(int _id_flower)
{
    id_flower = _id_flower;
}
int Flower::GetIdFlower() const
{
    return id_flower;
}
void Flower::SetFlowerName(std::string _flower_name)
{
    flower_name = _flower_name;
}
std::string Flower::GetFlowerName() const
{
    return flower_name;
}
void Flower::SetVariety(std::string _variety)
{
    variety = _variety;
}
std::string Flower::GetVariety() const
{
    return variety;
}
void Flower::SetFlowerCost(int _flower_cost)
{
    flower_cost = _flower_cost;
}
int Flower::GetFlowerCost() const 
{
    return flower_cost;
}