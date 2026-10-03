#include "ToyCatalog.h"
#include "SoftToy.h"
#include "Electronic.h"
#include "Constructor.h"
#include <iostream>
#include <cstdio>

ToyCatalog::ToyCatalog(const string& fn) : filename(fn) {}

void ToyCatalog::add(const Toy& t) {
    ofstream ofs(filename, ios::out | ios::app);// посмотреть про open() 
    if (!ofs.is_open()) {
        cerr << "Ошибка открытия файла для записи!\n";
        return;
    }
    t.saveToFile(ofs);
    ofs.close();
    cout << "Товар успешно добавлен в файл!\n";
}

void ToyCatalog::printTable(ostream& os) const {
    ifstream ifs(filename);
    if (!ifs.is_open()) {
        os << "Файл каталога не найден или пуст.\n";
        return;
    }

    os << "\n-------------------------------- КАТАЛОГ ТОВАРОВ --------------------------------\n";
    string type;
    int count = 0;

    while (getline(ifs >> ws, type)) {
        if (!type.empty() && type.back() == '\r') type.pop_back();

        Toy* newToy = nullptr;
        if (type == "Мягкая") newToy = new SoftToy();
        else if (type == "Электронная") newToy = new Electronic();
        else if (type == "Конструктор") newToy = new Constructor();

        if (newToy) {
            newToy->loadFromFile(ifs);
            os << *newToy;
            delete newToy;
            count++;
        }
    }

    if (count == 0) os << "Каталог пуст.\n";
    os << "---------------------------------------------------------------------------------\n";
    ifs.close();
}

bool ToyCatalog::editByArticle(const string& art) {
    ifstream ifs(filename);
    if (!ifs.is_open()) return false;

    ofstream tempOfs("temp.txt");
    string type;
    bool found = false;

    while (getline(ifs >> ws, type)) {
        if (!type.empty() && type.back() == '\r') type.pop_back();

        Toy* t = nullptr;
        if (type == "Мягкая") t = new SoftToy();
        else if (type == "Электронная") t = new Electronic();
        else if (type == "Конструктор") t = new Constructor();

        if (t) {
            t->loadFromFile(ifs);
            if (t->get_article() == art) {
                found = true;
                cout << "\nНайден товар для редактирования:\n";
                cin >> *t;
            }
           
            t->saveToFile(tempOfs);
            delete t;
        }
    }

    ifs.close();
    tempOfs.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    return found;
}

bool ToyCatalog::removeByArticle(const string& art) {
    ifstream ifs(filename);
    if (!ifs.is_open()) return false;

    ofstream tempOfs("temp.txt");
    string type;
    bool found = false;

    while (getline(ifs >> ws, type)) {
        if (!type.empty() && type.back() == '\r') type.pop_back();

        Toy* t = nullptr;
        if (type == "Мягкая") t = new SoftToy();
        else if (type == "Электронная") t = new Electronic();
        else if (type == "Конструктор") t = new Constructor();

        if (t) {
            t->loadFromFile(ifs);
            if (t->get_article() == art) {
                found = true;
            }
            else {
               
                t->saveToFile(tempOfs);
            }
            delete t;
        }
    }

    ifs.close();
    tempOfs.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    return found;
}

void ToyCatalog::printFindByName(const string& part) const {
    ifstream ifs(filename);
    if (!ifs.is_open()) return;

    string type;
    bool found = false;
    cout << "\n--- Результаты поиска по запросу: \"" << part << "\" ---\n";

    while (getline(ifs >> ws, type)) {
        if (!type.empty() && type.back() == '\r') type.pop_back();

        Toy* t = nullptr;
        if (type == "Мягкая") t = new SoftToy();
        else if (type == "Электронная") t = new Electronic();
        else if (type == "Конструктор") t = new Constructor();

        if (t) {
            t->loadFromFile(ifs);
            if (t->get_name().find(part) != string::npos) {
                cout << *t;
                found = true;
            }
            delete t;
        }
    }
    if (!found) cout << "Совпадений не найдено.\n";
    ifs.close();
}

Toy* ToyCatalog::findByArticle(const string& art) const {
    ifstream ifs(filename);
    if (!ifs.is_open()) return nullptr;

    string type;
    while (getline(ifs >> ws, type)) {
        if (!type.empty() && type.back() == '\r') type.pop_back();

        Toy* t = nullptr;
        if (type == "Мягкая") t = new SoftToy();
        else if (type == "Электронная") t = new Electronic();
        else if (type == "Конструктор") t = new Constructor();

        if (t) {
            t->loadFromFile(ifs);
            if (t->get_article() == art) {
                ifs.close();
                return t;
            }
            delete t;
        }
    }
    ifs.close();
    return nullptr;
}