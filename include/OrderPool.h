#pragma once
#include <vector>
#include "Order.h"

class OrderPool {
private:
    std::vector<Order> pool;
    std::vector<Order*> free_list;

public:
    explicit OrderPool(size_t capacity);
    Order* allocate();
    void deallocate(Order* order);
};