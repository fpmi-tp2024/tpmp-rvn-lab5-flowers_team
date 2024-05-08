#pragma once

#include <string>
#include <vector>
class Order{

    int id_order;
    int composition_id;
    int user_id;
    std::string order_date;
    std::string release_date;
    int composition_count;
    int cost;
    std::vector<Order>order;
public: 
    Order() = default;
    Order(int _id_order,int _composition_id, int _user_id, std::string _order_date,std::string _release_date, int _composition_count, double _cost): id_order(_id_order),
    composition_id(_composition_id), user_id(_user_id), order_date(_order_date), release_date(_release_date), composition_count(_composition_count), cost(_cost){}
    void AddOrder(int _id_order,int _composition_id, int _user_id, std::string _order_date,std::string _release_date, int _composition_count, double _cost);
    void SetIdOrder(int _id_order);
    int GetIdOrder() const;
    void SetCompositionId(int _composition_id);
    int GetCompositionId() const;
    void SetUserId(int _user_id);
    int GetUserId() const;
    void SetOrderDate(std::string _order_date);
    std::string GetOrderDate() const;
    void SetReleaseDate(std::string _release_date);
    std::string GetReleaseDate() const;
    void SetCompositionCount(int _composition_count);
    int GetCompositionCount() const;
    void SetCost(int _cost);
    int GetCost() const;
    std::string toString();
    ~Order() = default;
};