
#include "Sale.h"

Sale::Sale() : saleId(0), managerName(""), totalAmount(0.0), date("") {
}

Sale::Sale(int id, string manager, double amount, string d)
    : saleId(id), managerName(manager), totalAmount(amount), date(d) {
}

Sale::Sale(const Sale& other) {
    this->saleId = other.saleId;
    this->managerName = other.managerName;
    this->totalAmount = other.totalAmount;
    this->date = other.date;
}

Sale::~Sale() {
}

int Sale::get_saleId() const {
    return saleId;
}

string Sale::get_managerName() const {
    return managerName;
}

double Sale::get_totalAmount() const {
    return totalAmount;
}

string Sale::get_date() const {
    return date;
}

void Sale::set_saleId(int id) {
    this->saleId = id;
}

void Sale::set_managerName(string manager) {
    this->managerName = manager;
}

void Sale::set_totalAmount(double amount) {
    this->totalAmount = amount;
}

void Sale::set_date(string d) {
    this->date = d;
}

void Sale::printRow() const {
    cout << "| " << setw(8) << saleId
        << " | " << setw(15) << managerName
        << " | " << setw(12) << totalAmount
        << " | " << setw(12) << date << " |";
}

void Sale::printRowToFile(ofstream& file) const {
    file << "| " << setw(8) << saleId
        << " | " << setw(15) << managerName
        << " | " << setw(12) << totalAmount
        << " | " << setw(12) << date << " |";
}

double Sale::getSum() const {
    return totalAmount;
}

Sale& Sale::operator=(const Sale& other) {
    if (this != &other) {
        this->saleId = other.saleId;
        this->managerName = other.managerName;
        this->totalAmount = other.totalAmount;
        this->date = other.date;
    }
    return *this;
}