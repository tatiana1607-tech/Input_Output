#include "Buy.h"
#include <fstream>
#include<iomanip>
Buy::Buy() : customer(), phone(), quantity(0), date("") {
}

Buy::Buy(Customer c, Phone p, int q, string d)
    : customer(c), phone(p), quantity(q), date(d) {
}

Buy::Buy(const Buy& other) {
    this->customer = other.customer;
    this->phone = other.phone;
    this->quantity = other.quantity;
    this->date = other.date;
}

Buy::~Buy() {
}

Customer Buy::get_customer() const {
    return customer;
}

Phone Buy::get_phone() const {
    return phone;
}

int Buy::get_quantity() const {
    return quantity;
}

string Buy::get_date() const {
    return date;
}

void Buy::set_customer(Customer c) {
    this->customer = c;
}

void Buy::set_phone(Phone p) {
    this->phone = p;
}

void Buy::set_quantity(int q) {
    this->quantity = q;
}

void Buy::set_date(string d) {
    this->date = d;
}

double Buy::getTotalPrice() const {
    return phone.get_price() * quantity;  
}

double Buy::getSum() const {
    return getTotalPrice();
}

void Buy::printRow() const {
    cout << "| " << setw(20) << customer.get_name()
         << " | " << setw(20) << phone.get_model()
         << " | " << setw(8) << quantity
         << " | " << setw(10) << getTotalPrice()
         << " | " << setw(12) << date << " |";
}

void Buy::printRowToFile(ofstream& file) const {
    file << "| " << setw(20) << customer.get_name()
         << " | " << setw(20) << phone.get_model()
         << " | " << setw(8) << quantity
         << " | " << setw(10) << getTotalPrice()
         << " | " << setw(12) << date << " |";
}

Buy& Buy::operator=(const Buy& other) {
    if (this != &other) {
        this->customer = other.customer;
        this->phone = other.phone;
        this->quantity = other.quantity;
        this->date = other.date;
    }
    return *this;
}