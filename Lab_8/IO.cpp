#include "IO.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

void IO::savePurchase(const Purchase& p) {
    ofstream f("purchases.txt", ios::app);
    const MobilePhone& ph = p.getPhone();
    const Customer& c = p.getCustomer();
    f << ph.getModel() << ' '
        << ph.getPrice() << ' '
        << ph.getQuantity() << ' '
        << c.getName() << ' '
        << p.total() << '\n';
}

void IO::printPurchases() {
    ifstream f("purchases.txt");
    if (!f.is_open()) {
        cout << "Покупок нет.\n";
        return;
    }

    cout << "---------------------------------------------------------------\n";
    cout << left << setw(18) << "Модель"
        << setw(10) << "Цена"
        << setw(10) << "Кол-во"
        << setw(15) << "Клиент"
        << setw(10) << "Сумма" << endl;
    cout << "---------------------------------------------------------------\n";

    string model, customer;
    double price, total;
    int qty;

    while (f >> model >> price >> qty >> customer >> total) {
        cout << left << setw(18) << model
            << setw(10) << price
            << setw(10) << qty
            << setw(15) << customer
            << setw(10) << total << endl;
    }

    cout << "---------------------------------------------------------------\n";
}

void IO::saveSale(const Sale& s) {
    ofstream f("sales.txt", ios::app);
    const MobilePhone& ph = s.getPhone();
    const Manager& m = s.getManager();
    f << ph.getModel() << '\t'
        << ph.getPrice() << '\t'
        << ph.getQuantity() << '\t'
        << m.getName() << '\n';
}

void IO::printSales() {
    ifstream f("sales.txt");
    if (!f.is_open()) {
        cout << "Продаж нет.\n";
        return;
    }

    cout << "---------------------------------------------------------------\n";
    cout << left << setw(18) << "Модель"
        << setw(10) << "Цена"
        << setw(10) << "Кол-во"
        << setw(15) << "Менеджер" << endl;
    cout << "---------------------------------------------------------------\n";

    string line;
    double totalSum = 0;

    while (getline(f, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string model, manager;
        double price;
        int qty;

        ss >> model >> price >> qty;
        getline(ss, manager);

       
        size_t pos = manager.find_first_not_of(" \t");
        if (pos != string::npos) {
            manager = manager.substr(pos);
        }
        else {
            manager = "";
        }

        cout << left << setw(18) << model
            << setw(10) << price
            << setw(10) << qty
            << setw(15) << manager << endl;

        totalSum += price * qty;
    }

    cout << "---------------------------------------------------------------\n";
    cout << "Общая сумма продаж: " << totalSum << " BYN\n";
    cout << "---------------------------------------------------------------\n";
}