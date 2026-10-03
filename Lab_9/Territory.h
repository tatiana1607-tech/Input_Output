#pragma once
#include "Person.h"
#include "Exceptions.h"

class Building {
private:
    string address;
    int floors;
    double area;

public:
    Building();
    Building(string addr, int f, double a);
    Building(const Building& other);
    ~Building();
    void display() const;
};

class Territory {
private:
    string name;
    double totalArea;
    Building buildings[10];
    int buildingsCount;

public:
    Territory();
    Territory(string n, double area);
    Territory(const Territory& other);
    ~Territory();

    string getName() const;
    double getTotalArea() const;
    void addBuilding(string address, int floors, double area);
    int getBuildingsCount() const;
    void display() const;
};