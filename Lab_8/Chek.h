#pragma once
#include<iostream>
using namespace std;


int getValidInt(const char* p) {
    int value;
    while (true) {
        cout << p;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка: введите корректное целое число!\n";
        }
        else {
            char c;
            if (cin.get(c) && c != '\n') {
                cout << "Ошибка! Обнаружены лишние символы! Введите только число.\n";
                cin.ignore(10000, '\n');
            }
            else {
                return value;
            }
        }
    }
}


double getValidDouble(const char* p) {
    double value;
    while (true) {
        cout << p;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка: введите корректное действительное число (используйте точку)!\n";
        }
        else {
            char c;
            if (cin.get(c) && c != '\n') {
                cout << "Ошибка! Обнаружены лишние символы! Введите только число.\n";
                cin.ignore(10000, '\n');
            }
            else {
                return value;
            }
        }
    }
}


int getValidIntInRange(const char* p, int min, int max) {
    while (true) {
        int value = getValidInt(p);
        if (value >= min && value <= max) {
            return value;
        }
        cout << "Ошибка: введите число от " << min << " до " << max << "!\n";
    }
}


double getValidDoubleInRange(const char* p, double min, double max) {
    while (true) {
        double value = getValidDouble(p);
        if (value >= min && value <= max) {
            return value;
        }
        cout << "Ошибка: введите число от " << min << " до " << max << "!\n";
    }
}


double getValidPositiveDouble(const char* p) {
    while (true) {
        double value = getValidDouble(p);
        if (value > 0) {
            return value;
        }
        cout << "Ошибка: введите положительное число!\n";
    }
}


double getValidNonNegativeDouble(const char* p) {
    while (true) {
        double value = getValidDouble(p);
        if (value >= 0) {
            return value;
        }
        cout << "Ошибка: введите неотрицательное число (a >= 0)!\n";
    }
}




