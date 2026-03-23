#pragma once
#include <cstdint>

struct Order {
    uint64_t id;
    uint64_t price;
    uint32_t qty;
    bool is_buy;

    // Intrusive pointers
    Order* prev = nullptr;
    Order* next = nullptr;
};