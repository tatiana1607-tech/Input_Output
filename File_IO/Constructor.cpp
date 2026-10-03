#include "Constructor.h"
#include <iomanip>

Constructor::Constructor() : Toy(), piecesCount(0), series("Стандарт") {}

Constructor::Constructor(const string& art, const string& n, double p, int m, int pc, const string& s)
    : Toy(art, n, p, m) {
    set_piecesCount(pc);
    set_series(s);
}

int Constructor::get_piecesCount() const { return piecesCount; }
string Constructor::get_series() const { return series; }

void Constructor::set_piecesCount(int p) { piecesCount = (p >= 0) ? p : 0; }
void Constructor::set_series(const string& s) { series = s; }

string Constructor::get_type() const { return "Конструктор"; }

void Constructor::print(ostream& os) const {
    os << left << setw(14) << get_type()
        << setw(12) << article
        << setw(25) << name
        << setw(10) << price
        << setw(10) << minAge
        << "Деталей: " << setw(15) << piecesCount
        << "Серия: " << series << "\n";
}

void Constructor::input(istream& is) {
    Toy::input(is);
    set_piecesCount(readInt(is, "Введите количество деталей: "));
    cout << "Введите серию: ";
    is >> ws;
    getline(is, series);
}

void Constructor::saveToFile(ofstream& ofs) const {
    ofs << get_type() << "\n";
    Toy::saveToFile(ofs);
    ofs << piecesCount << "\n" << series << "\n";
}

void Constructor::loadFromFile(ifstream& ifs) {
    Toy::loadFromFile(ifs);
    ifs >> piecesCount;
    ifs.ignore(10000, '\n'); 

    getline(ifs >> ws, series);
    if (!series.empty() && series.back() == '\r') series.pop_back();
}