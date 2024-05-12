#include <string>
#include <iostream>
#include "../include/InfoAboutOrder.hpp"
#include "../include/Order.hpp"

InfoAboutOrder::InfoAboutOrder() : Command("All information about the order") {}

void InfoAboutOrder::execute(SQLite::Database &db, std::optional<User> user_info)
{
    std::string date;
    Order order{};
    std::cout << "Enter the date to receive information on all orders" << std::endl;
    std::getline(std::cin, date);

    SQLite::Statement query(db, "SELECT id, composition_count, order_date, release_date, user_id, composition_id \
    FROM \"Order\" WHERE order_date = ?;");
    query.bind(1, date);
    bool is_order_find = false;
    try
    {
        while (query.executeStep())
        {
            order.SetIdOrder(query.getColumn(0).getInt());
            order.SetCompositionCount(query.getColumn(1).getInt());
            order.SetOrderDate(query.getColumn(2).getString());
            order.SetReleaseDate(query.getColumn(3).getString());
            order.SetUserId(query.getColumn(4).getInt());
            order.SetCompositionId(query.getColumn(5).getInt());

            SQLite::Statement query1(db, "SELECT cost FROM Order_Cost WHERE id = ?;");
            query1.bind(1, order.GetIdOrder());
            while (query1.executeStep())
            {
                order.SetCost(query1.getColumn(0).getInt());
            }
            order.AddOrder(order.GetIdOrder(), order.GetCompositionId(), order.GetUserId(), order.GetOrderDate(),
                           order.GetReleaseDate(), order.GetCompositionCount(), order.GetCost());
            is_order_find = true;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    if (!is_order_find)
    {
        std::cout << "No information available for the specified date" << std::endl;
    }
    else
    {
        std::cout << "All information about orders by date: " << date << std::endl;
        std::cout << order.toString() << std::endl;
    }
}

InfoAboutOrder::~InfoAboutOrder() = default;