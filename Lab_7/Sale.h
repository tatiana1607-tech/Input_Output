#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Sale {
private:
    int saleId;          
    string managerName;   
    double totalAmount;   
    string date;          
public:
    
    Sale();
    Sale(int id, string manager, double amount, string d);
    Sale(const Sale& other);
    ~Sale();

    
    int get_saleId() const;
    string get_managerName() const;
    double get_totalAmount() const;
    string get_date() const;

   
    void set_saleId(int id);
    void set_managerName(string manager);
    void set_totalAmount(double amount);
    void set_date(string d);

   
    void printRow() const;
    void printRowToFile(ofstream& file) const;
    double getSum() const;

    
    Sale& operator=(const Sale& other);
};


