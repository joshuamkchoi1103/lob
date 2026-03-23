#pragma once
#include "order.h"

class PriceLevel {
private:
    Order* head;  // Points to the first order in line
    Order* tail;  // Points to the last order in line

public:
    uint32_t price;
    uint32_t total_volume; // Cache the total volume for fast lookups

    PriceLevel(uint32_t p) : head(nullptr), tail(nullptr), price(p), total_volume(0) {}

    // Add a new order to the back of the line: O(1) Time Complexity
    void append(Order* order) {
        if (!head) {
            head = order;
            tail = order;
        } else {
            tail->next = order;
            order->prev = tail;
            tail = order;
        }
        total_volume += order->quantity;
    }

    // Remove an order from anywhere in the line: O(1) Time Complexity
    void remove(Order* order) {
        if (order->prev) {
            order->prev->next = order->next;
        } else {
            head = order->next; // Order was the head
        }

        if (order->next) {
            order->next->prev = order->prev;
        } else {
            tail = order->prev; // Order was the tail
        }

        // Clean up the order's pointers
        order->next = nullptr;
        order->prev = nullptr;

        total_volume -= order->quantity;
    }

    // Helper to view the front of the line
    Order* get_head() const { return head; }
};