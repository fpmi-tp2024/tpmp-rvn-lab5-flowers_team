#include <string>
#include <vector>
#include "../include/InfoAboutOrder.hpp"
#include "../include/Order.hpp"

InfoAboutOrder::InfoAboutOrder() : Command("All information about the order") {}

void InfoAboutOrder::execute(SQLite::Database &db, std::optional<User> user_info)
{
    std::string date;
    std::vector<Order> orders_info;
    std::cout << "Enter the date to receive information on all orders" << std::endl;
    std::getline(std::cin, date);

    SQLite::Statement query(db, "SELECT id, composition_count, order_date, release_date, user_id, composition_id \
    FROM \"Order\" WHERE order_date = ?;");
    query.bind(1, date);
    try
    {
        while (query.executeStep())
        {
            int order_id = query.getColumn(0).getInt();
            int composition_count = query.getColumn(1).getInt();
            std::string order_date = query.getColumn(2).getString();
            std::string release_date = query.getColumn(3).getString();
            int user_id = query.getColumn(4).getInt();
            int composition_id = query.getColumn(5).getInt();

            SQLite::Statement cost_query(db, "SELECT cost FROM Order_Cost WHERE id = ?;");
            cost_query.bind(1, order_id);
            while (cost_query.executeStep())
            {
                int cost = cost_query.getColumn(0).getInt();
                orders_info.emplace_back(order_id, composition_id, user_id, order_date, release_date,
                                         composition_count, cost);
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    if (orders_info.empty())
    {
        std::cout << "No information available for the specified date" << std::endl;
    }
    else
    {
        std::cout << "All information about orders by date: " << date << std::endl;
        for (const auto &order : orders_info)
        {
            std::cout << order << std::endl;
        }
    }
}

InfoAboutOrder::~InfoAboutOrder() = default;