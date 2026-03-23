#include "../include/LimitOrderBook.h"
#include <iostream>

LimitOrderBook::LimitOrderBook(size_t max_orders) : pool(max_orders) {
    price_levels.reserve(10000); 
    order_map.reserve(max_orders);
}

void LimitOrderBook::add_order(uint64_t id, uint64_t price, uint32_t qty, bool is_buy) {
    Order* order = pool.allocate();
    if (!order) {
        std::cout << "[ERROR] Memory pool exhausted.\n";
        return; 
    }

    order->id = id;
    order->price = price;
    order->qty = qty;
    order->is_buy = is_buy;

    price_levels[price].append(order);
    order_map[id] = order;

    std::cout << "[ADD] Order " << id << " added to book at price " << price << "\n";
}

void LimitOrderBook::cancel_order(uint64_t id) {
    auto it = order_map.find(id);
    if (it == order_map.end()) {
        std::cout << "[ERROR] Order " << id << " not found.\n";
        return;
    }

    Order* order = it->second;
    price_levels[order->price].remove(order); 
    order_map.erase(it);                      
    pool.deallocate(order);                   

    std::cout << "[CANCEL] Order " << id << " successfully canceled.\n";
}