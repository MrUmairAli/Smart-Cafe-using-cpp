#include "../include/Order.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void Order::addItem(MenuItem item, int qty) {
    items.push_back(item);
    quantity.push_back(qty);
}

void Order::removeItem(string itemName) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i].name == itemName) {
            items.erase(items.begin() + i);
            quantity.erase(quantity.begin() + i);
            cout << "Item removed!\n";
            return;
        }
    }
    cout << "Item not found!\n";
}

double Order::calculateTotal() {
    if (items.empty()) {
        throw runtime_error("Order is empty!");
    }

    double subtotal = 0;

    cout << "\n------ Smart Cafe ------\n";
    cout << "Item\tQty\tPrice\n";

    for (int i = 0; i < items.size(); i++) {
        double price = items[i].price * quantity[i];
        subtotal += price;
        cout << items[i].name << "\t" << quantity[i] << "\t" << price << endl;
    }

    double tax = subtotal * 0.05;
    double total = subtotal + tax;

    cout << "------------------------\n";
    cout << "Subtotal:\t" << subtotal << endl;
    cout << "Tax:\t\t" << tax << endl;
    cout << "Total:\t\t" << total << endl;

    return total;
}
