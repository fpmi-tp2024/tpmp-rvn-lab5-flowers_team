#include "../include/CompositionProfitAnalyzer.hpp"
#include <string>
#include <iostream>

CompositionProfitAnalyzer::CompositionProfitAnalyzer() : Command("Composition profit analyzer"){}

void CompositionProfitAnalyzer::execute(SQLite::Database &db , std::optional<User>user_info){
    SQLite::Statement query(db,"WITH tab1(comp_id, comp_count, total_cost) \
    AS (SELECT o.composition_id, SUM(o.composition_count), SUM(oc.cost) \
    FROM \"Order\" o JOIN Order_cost oc ON o.id = oc.order_id GROUP BY o.composition_id) \
    SELECT comp_id, comp_count, total_cost FROM tab1;");
    
    try
    {
        while (query.executeStep())
        {
            std::cout << "Profit by composition: ";
            std::cout << query.getColumnName(0) << ": "<<query.getColumn(0) << ", " << query.getColumnName(1) << ": " << query.getColumn(1) << ", " << query.getColumnName(2) << ": " << query.getColumn(2) << std::endl;
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

}