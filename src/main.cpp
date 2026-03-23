#include "../include/LimitOrderBook.h"
#include <iostream>

int main() {
    std::cout << "--- HFT Matching Engine v2.0 (Zero-Allocation) ---\n";
    
    // Initialize the book with a pool of 1,000,000 pre-allocated orders
    LimitOrderBook lob(1000000);

    lob.add_order(1, 15025, 100, true);
    lob.add_order(2, 15025, 200, true);
    lob.add_order(3, 15030, 50, true);
    
    lob.cancel_order(2);
    lob.cancel_order(999); // Test error handling

    return 0;
}