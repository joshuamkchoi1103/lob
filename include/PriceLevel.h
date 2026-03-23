#pragma once
#include "Order.h"

struct PriceLevel {
    Order* head = nullptr;
    Order* tail = nullptr;
    uint64_t total_volume = 0;

    void append(Order* order);
    void remove(Order* order);
};