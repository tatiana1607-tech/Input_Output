#include "Customer.h"

Customer::Customer() : name(""), phoneNumber("") {
}

Customer::Customer(string n, string phone) : name(n), phoneNumber(phone) {
}

Customer::Customer(const Customer& other) {
    this->name = other.name;
    this->phoneNumber = other.phoneNumber;
}

Customer::~Customer() {
}

string Customer::get_name() const {
    return name;
}

string Customer::get_phoneNumber() const {
    return phoneNumber;
}

void Customer::set_name(string n) {
    this->name = n;
}

void Customer::set_phoneNumber(string phone) {
    this->phoneNumber = phone;
}