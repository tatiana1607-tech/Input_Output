#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Vehicle {
protected:
    int ID;
    int day, month, year;
    string model;
    int mileage;

public:
    Vehicle();
    Vehicle(int id, int d, int m, int y, string mod, int mil);
    Vehicle(const Vehicle& other);
    virtual ~Vehicle();

    int getID() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    string getModel() const;
    int getMileage() const;

    void setID(int id);
    void setDate(int d, int m, int y);
    void setModel(string mdl);
    void setMileage(int mil);

    virtual bool isMaintenanceOverdue(int curD, int curM, int curY) = 0;
    virtual void printInf() = 0;
    virtual void saveToFile(ofstream& file) = 0;
    virtual string getType() const = 0;
};