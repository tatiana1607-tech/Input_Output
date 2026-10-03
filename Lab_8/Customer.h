#pragma once
#include <string>
using namespace std;

class Customer {
    string name;

public:
    Customer();
    Customer(string n);
    Customer(const Customer& obj);

    string getName() const;
};
