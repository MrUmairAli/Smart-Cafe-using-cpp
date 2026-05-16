#include "../include/MenuItem.h"
#include <iostream>
using namespace std;

MenuItem::MenuItem(string n, double p, string c) {
    name = n;
    price = p;
    category = c;
}

void MenuItem::display() const {
    cout << name << " (" << category << ") - Rs." << price << endl;
}
