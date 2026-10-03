#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Toy.h"

using namespace std;

class ToyCatalog {
private:
    string filename;

public:
    ToyCatalog(const string& fn = "catalog_data.txt");

    void printTable(ostream& os = cout) const;

    void add(const Toy& t);
 bool removeByArticle(const string& art);
 bool editByArticle(const string& art);
void printFindByName(const string& part) const;
Toy* findByArticle(const string& art) const;
};