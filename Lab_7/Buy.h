#pragma once
#include <string>
#include <iostream>
#include<fstream>
#include <iomanip>
#include "Customer.h"
#include "Phone.h"

using namespace std;

class Buy {
private:
    Customer customer;  
    Phone phone;         
    int quantity;        
    string date;       

public:
   
    Buy();
    Buy(Customer c, Phone p, int q, string d);
    Buy(const Buy& other);
    ~Buy();

    
    Customer get_customer() const;
    Phone get_phone() const;
    int get_quantity() const;
    string get_date() const;

    
    void set_customer(Customer c);
    void set_phone(Phone p);
    void set_quantity(int q);
    void set_date(string d);

    
    double getTotalPrice() const;  
    void printRow() const;         
    void printRowToFile(ofstream& file) const;
    double getSum() const;         

    
    Buy& operator=(const Buy& other);
};


