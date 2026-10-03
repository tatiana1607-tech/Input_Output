#pragma once
#include "Toy.h"

using namespace std;

class ToyCatalog {
private:
    Toy** data;
    int count;
    int capacity;

    void ensureCapacity();

public:
    ToyCatalog();
    ToyCatalog(const ToyCatalog& other);
    ToyCatalog& operator=(const ToyCatalog& other);
    ~ToyCatalog();

    int getCount() const;

    void printTable(ostream& os = cout) const;
    void add(Toy* t);
    Toy* findByArticle(const string& art) const;

    void sortByPrice();
    void sortByName();

    void printFindByName(const string& part) const;
};