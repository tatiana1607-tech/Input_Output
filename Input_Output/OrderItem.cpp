#include "OrderItem.h"
#include <iomanip>

using namespace std;

OrderItem::OrderItem(const Toy* toy, int qty) : itemToy(toy) {
    setQuantity(qty);
}

OrderItem::OrderItem(const OrderItem& other) : itemToy(other.itemToy), quantity(other.quantity) {}

OrderItem& OrderItem::operator=(const OrderItem& other) {
    if (this != &other) {
        itemToy = other.itemToy;
        quantity = other.quantity;
    }
    return *this;
}

OrderItem::~OrderItem() {}

string OrderItem::getArticle() const {
    if (itemToy) return itemToy->get_article();
    return "";
}

int OrderItem::getQuantity() const {
    return quantity;
}

void OrderItem::setQuantity(int q) {
    if (q > 0) {
        quantity = q;
    }
    else {
        quantity = 1;
    }
}

double OrderItem::getTotalPrice() const {
    if (itemToy) return itemToy->get_price() * quantity;
    return 0.0;
}

void OrderItem::printItem(int index, ostream& os) const {
    if (!itemToy) return;
    os << setw(5) << index
        << setw(12) << itemToy->get_article()
        << setw(22) << itemToy->get_name()
        << setw(12) << itemToy->get_price()
        << setw(10) << quantity
        << setw(15) << getTotalPrice() << " руб.\n";
}