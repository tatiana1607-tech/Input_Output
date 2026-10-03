#include "Sale.h"

Sale::Sale(SmartPointer<MobilePhone> p, Manager m)
    : phone(p), manager(m) {
}

const MobilePhone& Sale::getPhone() const { return *phone; }
const Manager& Sale::getManager() const { return manager; }
