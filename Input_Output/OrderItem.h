#pragma once
#include "Toy.h"

using namespace std;

class OrderItem {
private:
    const Toy* itemToy;
    int quantity;

public:
    OrderItem(const Toy* toy = nullptr, int qty = 1);
    OrderItem(const OrderItem& other);
    OrderItem& operator=(const OrderItem& other);
    ~OrderItem();

    string getArticle() const;
    int getQuantity() const;
    void setQuantity(int q);

    double getTotalPrice() const;
    void printItem(int index, ostream& os = cout) const;
};