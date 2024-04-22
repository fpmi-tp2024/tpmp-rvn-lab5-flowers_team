#include "../include/FlowerVarietyPeriodAnalyzer.hpp"
#include <string>
#include <iostream>

FlowerVarietyPeriodAnalyzer::FlowerVarietyPeriodAnalyzer() : Command("Flower variety period analyzer"){}

void FlowerVarietyPeriodAnalyzer::execute(SQLite::Database &db , std::optional<User>user_info){
    SQLite::Statement query(db,"SELECT f.variety AS variety_name, SUM(cf.flower_count * o.composition_count) AS flower_count FROM \"Order\" o JOIN Composition_flower cf ON o.composition_id = cf.composition_id JOIN Flower f ON cf.id_flower = f.id WHERE o.release_date BETWEEN ? AND ? GROUP BY f.variety;");
    std::string begin_date, end_date;
    std::cout<<"Input begin period date: "<<std::endl;
    std::getline(std::cin,begin_date);
    std::cout<<"Input end period date: "<<std::endl;
    std::getline(std::cin,end_date);
    query.bind(1,begin_date);
    query.bind(2,end_date);
    try
    {
        while (query.executeStep())
        {
            std::cout<<query.getColumnName(0)<<": "<<query.getColumn(0)<<", "<<query.getColumnName(1)<<": "<<query.getColumn(1)<<std::endl;
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}