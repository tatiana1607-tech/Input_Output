#include "MobilePhone.h"

MobilePhone::MobilePhone() : model(""), price(0), quantity(0) {}

MobilePhone::MobilePhone(string m, double p, int q)
    : model(m), price(p), quantity(q) {
}

MobilePhone::MobilePhone(const MobilePhone& obj)
    : model(obj.model), price(obj.price), quantity(obj.quantity) {
}

MobilePhone::~MobilePhone() {}

void MobilePhone::setModel(string m) { model = m; }
void MobilePhone::setPrice(double p) { price = p; }
void MobilePhone::setQuantity(int q) { quantity = q; }

string MobilePhone::getModel() const { return model; }
double MobilePhone::getPrice() const { return price; }
int MobilePhone::getQuantity() const { return quantity; }

MobilePhone& MobilePhone::operator=(const MobilePhone& other) {
    if (this != &other) {
        model = other.model;
        price = other.price;
        quantity = other.quantity;
    }
    return *this;
}