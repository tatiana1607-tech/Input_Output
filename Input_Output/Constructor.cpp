#include "Constructor.h"
#include <iomanip>

using namespace std;

Constructor::Constructor() : Toy(), pieces(0), series("Стандарт") {}


Constructor::Constructor(const string& art, const string& n, double p, int m, int pc, const string& s)
    : Toy(art, n, p, m) {
    set_pieces(pc);
    set_series(s);
}

int Constructor::get_pieces() const { return pieces; }
string Constructor::get_series() const { return series; }

void Constructor::set_pieces(int pc) {
    if (pc >= 0) {
        pieces = pc;
    }
    else {
        pieces = 0;
    }
}

void Constructor::set_series(const string& s) { series = s; }

string Constructor::get_type() const { return "Конструктор"; }

void Constructor::print(ostream& os) const {
    os << setw(10) << get_article()
        << setw(22) << get_name()
        << setw(10) << get_price()
        << setw(8) << get_minAge()
        << setw(14) << get_type()
        << setw(18) << ("деталей: " + to_string(pieces))
        << setw(14) << ("серия: " + series);
}

void Constructor::input(istream& is) {
    Toy::input(is);
    set_pieces(readInt(is, "Введите количество деталей: "));
    cout << "Введите серию: ";
    is >> ws;
    getline(is, series);
}