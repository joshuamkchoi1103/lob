#include <iostream>
#include "order.h"

int main() {
    std::cout << "Matching Engine Initialized." << std::endl;

    // Simulate an incoming order: ID 1, Buy, Price 15025 ($150.25), Quantity 100
    Order my_first_order(1, Side::Buy, 15025, 100);

    std::cout << "Order ID: " << my_first_order.order_id 
              << " | Size: " << my_first_order.quantity 
              << " | Price: " << my_first_order.price << std::endl;

    return 0;
}