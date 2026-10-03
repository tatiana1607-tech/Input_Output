#pragma once
#include "OrderItem.h"

class Order {
private:
    OrderItem** items;
    int count;
    int capacity;

    void ensureCapacity();

public:
    Order();
    Order(const Order& other);
    Order& operator=(const Order& other);
    ~Order();

    void addItem(OrderItem* item);
    double getFinalCost() const;
    void printReceipt() const;
    void clear();
};