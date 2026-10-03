#include "Electronic.h"
#include <iomanip>

Electronic::Electronic() : Toy(), batteryType("AA"), hasRemote(false) {}

Electronic::Electronic(const string& art, const string& n, double p, int m, const string& b, bool r)
    : Toy(art, n, p, m) {
    set_batteryType(b);
    set_hasRemote(r);
}

string Electronic::get_batteryType() const { return batteryType; }
bool Electronic::get_hasRemote() const { return hasRemote; }

void Electronic::set_batteryType(const string& b) { batteryType = b; }
void Electronic::set_hasRemote(bool r) { hasRemote = r; }

string Electronic::get_type() const { return "Электронная"; }

void Electronic::print(ostream& os) const {
    os << left << setw(14) << get_type()
        << setw(12) << article
        << setw(25) << name
        << setw(10) << price
        << setw(10) << minAge
        << "Батарейки: " << setw(12) << batteryType
        << "Пульт ДУ: " << (hasRemote ? "Да" : "Нет") << "\n";
}

void Electronic::input(istream& is) {
    Toy::input(is);
    cout << "Введите тип батареек: ";
    is >> ws;
    getline(is, batteryType);
    int remoteChoice = readInt(is, "Наличие пульта ДУ (1 - Да, 0 - Нет): ");
    hasRemote = (remoteChoice == 1);
}

void Electronic::saveToFile(ofstream& ofs) const {
    ofs << get_type() << "\n";
    Toy::saveToFile(ofs);
    ofs << batteryType << "\n" << (hasRemote ? 1 : 0) << "\n";
}

void Electronic::loadFromFile(ifstream& ifs) {
    Toy::loadFromFile(ifs);
    getline(ifs >> ws, batteryType);
    if (!batteryType.empty() && batteryType.back() == '\r') batteryType.pop_back();

    int remoteVal = 0;
    ifs >> remoteVal;
    ifs.ignore(10000, '\n'); 
    hasRemote = (remoteVal == 1);
}