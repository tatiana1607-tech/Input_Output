#pragma once
#include <string>
using namespace std;

class Phone {
private:
    string model;  
    double price;   

public:
    
    Phone();
    Phone(string m, double p);
    Phone(const Phone& other);
    ~Phone();

    
    string get_model() const;
    double get_price() const;

    
    void set_model(string m);
    void set_price(double p);
};

