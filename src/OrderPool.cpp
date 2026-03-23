#include "../include/OrderPool.h"

OrderPool::OrderPool(size_t capacity) {
    pool.resize(capacity);
    free_list.reserve(capacity);
    for (size_t i = 0; i < capacity; ++i) {
        free_list.push_back(&pool[i]);
    }
}

Order* OrderPool::allocate() {
    if (free_list.empty()) return nullptr; 
    Order* order = free_list.back();
    free_list.pop_back();
    return order;
}

void OrderPool::deallocate(Order* order) {
    order->prev = nullptr;
    order->next = nullptr;
    free_list.push_back(order);
}