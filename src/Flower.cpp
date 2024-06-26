#include "../include/Flower.hpp"
Flower::Flower() = default;
Flower::Flower(int _id_flower, std::string _flower_name, std::string _variety, int _flower_cost) : id_flower(_id_flower),
                                                                                                   flower_name(_flower_name),
                                                                                                   variety(_variety),
                                                                                                   flower_cost(_flower_cost) {}

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
Flower::~Flower() = default;

std::ostream &operator<<(std::ostream &out, const Flower &flower)
{
    out << "Flower id = " << flower.id_flower << '\n';
    out << "Flower name: " << flower.flower_name << '\n';
    out << "Flower variety: " << flower.variety << '\n';
    out << "Flower cost: " << flower.flower_cost << '\n';
    return out;
}