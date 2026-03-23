#pragma once
#include <cstdint>

// We use a strictly typed enum rather than a boolean for safety and readability
enum class Side {
    Buy,
    Sell
};

struct Order {
    uint64_t order_id;  // 8 bytes: Unique identifier for the order
    uint32_t price;     // 4 bytes: Price in ticks/cents 
    uint32_t quantity;  // 4 bytes: Number of shares/contracts
    Side side;          // 1 byte (plus padding): Buy or Sell

    // Pointers for our custom Doubly-Linked List to achieve O(1) cancellations
    Order* next;        
    Order* prev;        

    // Constructor for blazing fast initialization
    Order(uint64_t id, Side s, uint32_t p, uint32_t q)
        : order_id(id), price(p), quantity(q), side(s), next(nullptr), prev(nullptr) {}
};