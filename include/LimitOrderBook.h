#pragma once
#include <unordered_map>
#include "OrderPool.h"
#include "PriceLevel.h"

class LimitOrderBook {
private:
    OrderPool pool;
    std::unordered_map<uint64_t, PriceLevel> price_levels; 
    std::unordered_map<uint64_t, Order*> order_map; 

public:
    explicit LimitOrderBook(size_t max_orders);
    
    void add_order(uint64_t id, uint64_t price, uint32_t qty, bool is_buy);
    void cancel_order(uint64_t id);
};