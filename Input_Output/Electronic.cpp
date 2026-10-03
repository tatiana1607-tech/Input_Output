#include "Electronic.h"
#include <iomanip>

using namespace std;

Electronic::Electronic() : Toy(), battery("AA"), hasRemote(false) {}


Electronic::Electronic(const string& art, const string& n, double p, int m, const string& b, bool r)
    : Toy(art, n, p, m) {
    set_battery(b);
    set_hasRemote(r);
}

string Electronic::get_battery() const { return battery; }
bool Electronic::get_hasRemote() const { return hasRemote; }

void Electronic::set_battery(const string& b) { battery = b; }
void Electronic::set_hasRemote(bool r) { hasRemote = r; }

string Electronic::get_type() const { return "Ёлектронна€"; }

void Electronic::print(ostream& os) const {
    os << setw(10) << get_article()
        << setw(22) << get_name()
        << setw(10) << get_price()
        << setw(8) << get_minAge()
        << setw(14) << get_type()
        << setw(18) << ("батарейки: " + battery)
        << setw(14) << ("пульт: " + string(hasRemote ? "да" : "нет"));
}

void Electronic::input(istream& is) {
    Toy::input(is);
    cout << "¬ведите тип батареек: ";
    is >> ws;
    getline(is, battery);
    int remoteVal = readInt(is, "ѕульт ƒ” (1 - есть, 0 - нет): ");
    set_hasRemote(remoteVal != 0);
}