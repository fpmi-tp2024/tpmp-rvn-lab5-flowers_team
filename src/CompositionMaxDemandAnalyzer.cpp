#include "../include/CompositionMaxDemandAnalyzer.hpp"
#include <string>
#include <iostream>

CompositionMaxDemandAnalyzer::CompositionMaxDemandAnalyzer() : Command("Composition maximum demand analyzer"){}

void CompositionMaxDemandAnalyzer::execute(SQLite::Database &db , std::optional<User>user_info){
    SQLite::Statement query(db,"SELECT id, composition_name, composition_cost FROM Composition WHERE id = (SELECT composition_id FROM \"Order\" GROUP BY composition_id ORDER BY SUM(composition_count) DESC LIMIT 1);");
    try
    {
        std::cout << "Information about the most popular composition: " << std::endl;
        while (query.executeStep())
        {
            std::cout << query.getColumnName(0) << ": "<<query.getColumn(0) << ", " << query.getColumnName(1) << ": " << query.getColumn(1) << ", " << query.getColumnName(2) << ": " << query.getColumn(2) << std::endl;
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

}