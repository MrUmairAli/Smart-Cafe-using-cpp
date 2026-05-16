#ifndef MENUITEM_H
#define MENUITEM_H
#include <string>
using namespace std;

class MenuItem {
public:
    string name;
    double price;
    string category;

    MenuItem(string n = "", double p = 0, string c = "");
    void display() const;
};
#endif
