#include "../include/NewOrderCostCalculator.hpp"
#include "../include/Composition.hpp"
#include "../include/User.hpp"
#include "../include/CompositionSelector.hpp"
#include <string>
#include <iostream>
#include <SQLiteCpp/Transaction.h>

NewOrderCostCalculator::NewOrderCostCalculator() : Command("New order cost calculator") {}
bool NewOrderCostCalculator::RegistrationNewOrder(SQLite::Database &db, Order &order, const int &composition_cost)
{
    SQLite::Transaction transaction(db);
    SQLite::Statement query(db, "INSERT INTO \"Order\" (composition_count,order_date,release_date,user_id,composition_id) VALUES(?, ?, ?, ?, ?) RETURNING id, composition_count, order_date, release_date, user_id, composition_id;");
    query.bind(1, order.GetCompositionCount());
    query.bind(2, order.GetOrderDate());
    query.bind(3, order.GetReleaseDate());
    query.bind(4, order.GetUserId());
    query.bind(5, order.GetCompositionId());
    bool is_order_add = false;
    try
    {
        while (query.executeStep())
        {
            order.SetIdOrder(query.getColumn(0).getInt());
        }
        order.SetCost(order.GetCompositionCount() * composition_cost);
        SQLite::Statement query1(db, "INSERT INTO Order_Cost(order_id, cost) VALUES(?, ?) RETURNING id, order_id, cost;");
        query1.bind(1, order.GetIdOrder());
        query1.bind(2, order.GetCost());
        while (query1.executeStep())
        {
            order.AddOrder(order.GetIdOrder(), order.GetCompositionId(), order.GetUserId(), order.GetOrderDate(), order.GetReleaseDate(), order.GetCompositionCount(), order.GetCost());
            is_order_add = true;
        }
        transaction.commit();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        transaction.rollback();
    }
    return is_order_add;
}
void NewOrderCostCalculator::execute(SQLite::Database &db, std::optional<User> user_info)
{
    std::string order_date, release_date, composition_name;
    int composition_count;
    Composition composition{};
    Order order{};
    CompositionSelector composition_selector{};

    while (true)
    {
        while (true)
        {
            std::cout << "Enter composition name: " << std::endl;
            std::getline(std::cin, composition_name);
            composition.SetCompositionName(composition_name);
            if (composition_selector.GetComposition(composition, db))
            {
                break;
            }
            std::cout << "No such composition. Please, try again!" << std::endl;
        }
        order.SetCompositionId(composition.GetIdComposition());
        std::cout << "Enter composition count: " << std::endl;
        std::cin >> composition_count;
        order.SetCompositionCount(composition_count);

        std::cout << "Enter order date: " << std::endl;
        std::cin.get();
        std::getline(std::cin, order_date);
        order.SetOrderDate(order_date);

        std::cout << "Enter release date: " << std::endl;
        std::cin.get();
        std::getline(std::cin, release_date);
        order.SetReleaseDate(release_date);

        if (RegistrationNewOrder(db, order, composition.GetCompositionCost()))
        {
            std::cout << "Information about order " << std::endl;
            std::cout << "Composition name: " << composition.GetCompositionName() << std::endl;
            std::cout << order.toString() << std::endl;
            break;
        }
        std::cout << "Incorrect data. Please, try again" << std::endl;
    }
}