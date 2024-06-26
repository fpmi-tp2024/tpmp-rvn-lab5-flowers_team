#include "../include/Order.hpp"
#include "../include/Composition.hpp"

Order::Order() = default;
Order::Order(int _id_order, int _composition_id, int _user_id,
             std::string _order_date, std::string _release_date,
             int _composition_count, int _cost) : id_order(_id_order),
                                                  composition_id(_composition_id), user_id(_user_id),
                                                  order_date(_order_date), release_date(_release_date),
                                                  composition_count(_composition_count), cost(_cost) {}
void Order::SetIdOrder(int _id_order)
{
    id_order = _id_order;
}
int Order::GetIdOrder() const
{
    return id_order;
}
void Order::SetCompositionId(int _composition_id)
{
    composition_id = _composition_id;
}
int Order::GetCompositionId() const
{
    return composition_id;
}
void Order::SetUserId(int _user_id)
{
    user_id = _user_id;
}
int Order::GetUserId() const
{
    return user_id;
}
void Order::SetOrderDate(std::string _order_date)
{
    order_date = _order_date;
}
std::string Order::GetOrderDate() const
{
    return order_date;
}
void Order::SetReleaseDate(std::string _release_date)
{
    release_date = _release_date;
}
std::string Order::GetReleaseDate() const
{
    return release_date;
}
void Order::SetCompositionCount(int _composition_count)
{
    composition_count = _composition_count;
}
int Order::GetCompositionCount() const
{
    return composition_count;
}
void Order::SetCost(int _cost)
{
    cost = _cost;
}
int Order::GetCost() const
{
    return cost;
}

Order::~Order() = default;

std::ostream &operator<<(std::ostream &out, const Order &order)
{
    out << "Order ID: " << order.id_order << '\n';
    out << "Composition ID: " << order.composition_id << '\n';
    out << "User ID: " << order.user_id << '\n';
    out << "Order date: " << order.order_date << '\n';
    out << "Release date: " << order.release_date << '\n';
    out << "Composition count: " << order.composition_count << '\n';
    out << "Order total cost: " << order.cost << "\n\n";
    return out;
}
