#include "../include/PriceLevel.h"

void PriceLevel::append(Order* order) {
    order->next = nullptr;
    order->prev = tail;
    if (tail) tail->next = order;
    else head = order;
    tail = order;
    total_volume += order->qty;
}

void PriceLevel::remove(Order* order) {
    if (order->prev) order->prev->next = order->next;
    else head = order->next;

    if (order->next) order->next->prev = order->prev;
    else tail = order->prev;
    
    total_volume -= order->qty;
}