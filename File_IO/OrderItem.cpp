#include "OrderItem.h"
#include <iomanip>

OrderItem::OrderItem(Toy* t, int qty) : toy(t) {
    set_quantity(qty);
}

Toy* OrderItem::get_toy() const { return toy; }
int OrderItem::get_quantity() const { return quantity; }

void OrderItem::set_quantity(int q) {
    quantity = (q > 0) ? q : 1;
}

double OrderItem::getTotalPrice() const {
    if (toy) {
        return toy->get_price() * quantity;
    }

    return 0.0;
}

void OrderItem::print(ostream& os) const {
    if (!toy) return;
    os << left << setw(12) << toy->get_article()
        << setw(25) << toy->get_name()
        << setw(10) << toy->get_price()
        << setw(8) << quantity
        << setw(10) << getTotalPrice() << "\n";
}