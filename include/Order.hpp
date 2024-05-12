#pragma once

#include <string>
#include <iostream>
class Order
{
public:
    Order();
    Order(int _id_order, int _composition_id, int _user_id,
          std::string _order_date, std::string _release_date, int _composition_count, int _cost);
    void SetIdOrder(int _id_order);
    void SetCompositionId(int _composition_id);
    void SetUserId(int _user_id);
    void SetOrderDate(std::string _order_date);
    void SetReleaseDate(std::string _release_date);
    void SetCompositionCount(int _composition_count);
    void SetCost(int _cost);
    int GetIdOrder() const;
    int GetCompositionId() const;
    int GetUserId() const;
    std::string GetOrderDate() const;
    std::string GetReleaseDate() const;
    int GetCompositionCount() const;
    int GetCost() const;
    ~Order();

    friend std::ostream &operator<<(std::ostream &out, const Order &order);

private:
    int id_order;
    int composition_id;
    int user_id;
    int composition_count;
    int cost;
    std::string order_date;
    std::string release_date;
};