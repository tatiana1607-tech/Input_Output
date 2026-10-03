#include "Purchase.h"

Purchase::Purchase(SmartPointer<MobilePhone> p, Customer c)
    : phone(p), customer(c) {
}

double Purchase::total() const {
    return phone->getPrice() * phone->getQuantity();
}

const MobilePhone& Purchase::getPhone() const { return *phone; }
const Customer& Purchase::getCustomer() const { return customer; }
