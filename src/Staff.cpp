#include "../include/Staff.h"
#include <iostream>
using namespace std;

Staff::Staff(string n) : Person(n) {}

void Staff::addMenuItem(vector<MenuItem>& menu) {
    string name, category;
    double price;

    cout << "Enter item name: ";
    cin >> name;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter category: ";
    cin >> category;

    menu.push_back(MenuItem(name, price, category));
    cout << "Item added!\n";
}
