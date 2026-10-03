#pragma once
#include "OrderItem.h"

using namespace std;

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

    int getCount() const;
    void addItem(OrderItem* item);
    bool editQuantityByArticle(const string& art, int newQty);
    bool removeItemByArticle(const string& art);
    void printReceipt(ostream& os = cout) const;
    void clear();
};