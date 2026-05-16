#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "../include/MenuItem.h"
#include "../include/Order.h"
#include "../include/Staff.h"

using namespace std;

void loadMenu(vector<MenuItem>& menu) {
    ifstream file("data/menu.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string name, category;
        double price;

        getline(ss, name, ',');
        ss >> price;
        ss.ignore();
        getline(ss, category);

        menu.push_back(MenuItem(name, price, category));
    }
}

void saveMenu(vector<MenuItem>& menu) {
    ofstream file("data/menu.txt");

    for (auto& item : menu) {
        file << item.name << "," << item.price << "," << item.category << endl;
    }
}

void displayMenu(vector<MenuItem>& menu) {
    for (auto& item : menu) {
        item.display();
    }
}

int main() {
    vector<MenuItem> menu;
    loadMenu(menu);

    Staff staff("Admin");
    Order order;

    int choice;

    do {
        cout << "\n1. Display Menu\n2. Add Item\n3. Order Item\n4. Remove Item\n5. Checkout\n6. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            displayMenu(menu);
        }
        else if (choice == 2) {
            staff.addMenuItem(menu);
        }
        else if (choice == 3) {
            string name;
            int qty;

            cout << "Enter item name: ";
            cin >> name;
            cout << "Enter quantity: ";
            cin >> qty;

            bool found = false;
            for (auto& item : menu) {
                if (item.name == name) {
                    order.addItem(item, qty);
                    found = true;
                }
            }

            if (!found) cout << "Item not found!\n";
        }
        else if (choice == 4) {
            string name;
            cout << "Enter item name to remove: ";
            cin >> name;
            order.removeItem(name);
        }
        else if (choice == 5) {
            try {
                order.calculateTotal();
            } catch (exception& e) {
                cout << e.what() << endl;
            }
        }

    } while (choice != 6);

    saveMenu(menu);
}
