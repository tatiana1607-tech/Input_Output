#include "Toy.h"
#include <iomanip>

using namespace std;

int readInt(istream& is, const string& prompt) {
    int val;
    while (true) {
        cout << prompt;
        is >> val;

        if (is.good()) return val;
        if (is.eof()) return 0;

        if (is.fail() || is.bad()) {
            is.clear();
            while (is.get() != '\n' && !is.eof()) {}
            cout << "Ошибка ввода! Введите целое число.\n";
        }
    }
}

double readDouble(istream& is, const string& prompt) {
    double val;
    while (true) {
        cout << prompt;
        is >> val;

        if (is.good()) return val;
        if (is.eof()) return 0.0;

        if (is.fail() || is.bad()) {
            is.clear();
            while (is.get() != '\n' && !is.eof()) {}
            cout << "Ошибка ввода! Введите число.\n";
        }
    }
}
Toy::Toy() : article("0000"), name("Без названия"), price(0.0), minAge(0) {}

Toy::Toy(const string& art, const string& n, double p, int m) {
    set_article(art);
    set_name(n);
    set_price(p);
    set_minAge(m);
}

Toy::~Toy() {}

string Toy::get_article() const { return article; }
string Toy::get_name() const { return name; }
double Toy::get_price() const { return price; }
int Toy::get_minAge() const { return minAge; }

void Toy::set_article(const string& a) { article = a; }
void Toy::set_name(const string& n) { name = n; }

void Toy::set_price(double p) {
    if (p >= 0) {
        price = p;
    }
    else {
        price = 0.0;
    }
}

void Toy::set_minAge(int m) {
    if (m >= 0) {
        minAge = m;
    }
    else {
        minAge = 0;
    }
}

void Toy::input(istream& is) {
    cout << "Введите артикул: ";
    is >> ws;
    getline(is, article);

    cout << "Введите название: ";
    getline(is, name);

    set_price(readDouble(is, "Введите цену: "));
    set_minAge(readInt(is, "Введите минимальный возраст: "));
}

ostream& operator<<(ostream& os, const Toy& t) {
    t.print(os);
    return os;
}

istream& operator>>(istream& is, Toy& t) {
    t.input(is);
    return is;
}