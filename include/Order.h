#ifndef ORDER_H
#define ORDER_H
#include "MenuItem.h"
#include <vector>

class Order {
private:
    std::vector<MenuItem> items;
    std::vector<int> quantity;

public:
    void addItem(MenuItem item, int qty);
    void removeItem(std::string itemName);
    double calculateTotal();
};
#endif
