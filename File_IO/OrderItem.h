#pragma once
#include "Toy.h"

class OrderItem {
private:
    Toy* toy;
    int quantity;

public:
    OrderItem(Toy* t = nullptr, int qty = 1);

    Toy* get_toy() const;
    int get_quantity() const;
    void set_quantity(int q);

    double getTotalPrice() const;
    void print(ostream& os) const;
};