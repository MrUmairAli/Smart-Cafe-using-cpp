#ifndef STAFF_H
#define STAFF_H
#include "Person.h"
#include "MenuItem.h"
#include <vector>

class Staff : public Person {
public:
    Staff(string n);
    void addMenuItem(std::vector<MenuItem>& menu);
};
#endif
