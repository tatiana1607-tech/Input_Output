#include "SoftToy.h"
#include <iomanip>

using namespace std;
SoftToy::SoftToy() : Toy(), material("ѕлюш"), height(0.0) {}

SoftToy::SoftToy(const string& art, const string& n, double p, int m, const string& mat, double h)
    : Toy(art, n, p, m) {
    set_material(mat);
    set_height(h);
}

string SoftToy::get_material() const { return material; }
double SoftToy::get_height() const { return height; }

void SoftToy::set_material(const string& mat) { material = mat; }
void SoftToy::set_height(double h) {
    if (h >= 0) {
        height = h;
    }
    else {
        height = 0.0;
    }
}

string SoftToy::get_type() const { return "ћ€гка€"; }

void SoftToy::print(ostream& os) const {
    os << setw(10) << get_article()
        << setw(22) << get_name()
        << setw(10) << get_price()
        << setw(8) << get_minAge()
        << setw(14) << get_type()
        << setw(18) << ("мат: " + material)
        << setw(14) << ("рост: " + to_string((int)height) + "см");
}

void SoftToy::input(istream& is) {
    Toy::input(is);
    cout << "¬ведите материал: ";
    is >> ws;
    getline(is, material);
    set_height(readDouble(is, "¬ведите высоту (см): "));
}