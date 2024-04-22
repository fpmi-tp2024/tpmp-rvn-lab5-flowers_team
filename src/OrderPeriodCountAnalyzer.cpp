#include "../include/OrderPeriodCountAnalyzer.hpp"
#include <string>
#include <iostream>

OrderPeriodCountAnalyzer::OrderPeriodCountAnalyzer() : Command("Order period count analyzer") {}

void OrderPeriodCountAnalyzer::execute(SQLite::Database &db , std::optional<User>user_info){
    SQLite::Statement query(db, "SELECT count(*) FROM Order_cost oc JOIN \"Order\" o ON oc.order_id = o.id WHERE o.release_date BETWEEN ? AND ?;");
    std::string begin_date, end_date;
    std::cout<<"Input begin period date: "<<std::endl;
    std::getline(std::cin,begin_date);
    std::cout<<"Input end period date: "<<std::endl;
    std::getline(std::cin,end_date);
    query.bind(1,begin_date);
    query.bind(2,end_date);
    int total_count = 0;
    try
    {
        while (query.executeStep())
        {
            total_count = query.getColumn(0);
        }
        std::cout<<"Total order count = "<<total_count<<std::endl;
        
    }
    catch(const std::exception& e)
    {
         std::cout << e.what() << std::endl;
    }
    
}