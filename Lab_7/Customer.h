#pragma once
#include <string>
using namespace std;

class Customer {
private:
    string name;         
    string phoneNumber;  

public:
   
    Customer();
    Customer(string n, string phone);
    Customer(const Customer& other);
    ~Customer();

    
    string get_name() const;
    string get_phoneNumber() const;


    void set_name(string n);
    void set_phoneNumber(string phone);
};

