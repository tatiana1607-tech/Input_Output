#pragma once
#include <string>
using namespace std;

class MobilePhone {
    string model;
    double price;
    int quantity;

public:
    MobilePhone();
    MobilePhone(string m, double p, int q);
    MobilePhone(const MobilePhone& obj);
    ~MobilePhone();

    void setModel(string m);
    void setPrice(double p);
    void setQuantity(int q);

    string getModel() const;
    double getPrice() const;
    int getQuantity() const;

    MobilePhone& operator=(const MobilePhone& other);
};