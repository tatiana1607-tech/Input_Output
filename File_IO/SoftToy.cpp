#include "SoftToy.h"
#include <iomanip>

SoftToy::SoftToy() : Toy(), material("Неизвестно"), height(0) {}

SoftToy::SoftToy(const string& art, const string& n, double p, int m, const string& mat, int h)
    : Toy(art, n, p, m) {
    set_material(mat);
    set_height(h);
}

string SoftToy::get_material() const { return material; }
int SoftToy::get_height() const { return height; }

void SoftToy::set_material(const string& m) { material = m; }
void SoftToy::set_height(int h) { height = (h >= 0) ? h : 0; }

string SoftToy::get_type() const { return "Мягкая"; }

void SoftToy::print(ostream& os) const {
    os << left << setw(14) << get_type()
        << setw(12) << article
        << setw(25) << name
        << setw(10) << price
        << setw(10) << minAge
        << "Материал: " << setw(15) << material
        << "Высота: " << height << " см\n";
}

void SoftToy::input(istream& is) {
    Toy::input(is);
    cout << "Введите материал: ";
    is >> ws;
    getline(is, material);
    set_height(readInt(is, "Введите высоту (см): "));
}

void SoftToy::saveToFile(ofstream& ofs) const {
    ofs << get_type() << "\n";
    Toy::saveToFile(ofs);
    ofs << material << "\n" << height << "\n";
}

void SoftToy::loadFromFile(ifstream& ifs) {
    Toy::loadFromFile(ifs);
    getline(ifs >> ws, material);
    if (!material.empty() && material.back() == '\r') material.pop_back();

    ifs >> height;
    ifs.ignore(10000, '\n');
}