#include "Vehicle.h"

Vehicle::Vehicle() : ID(0), day(1), month(1), year(2000), model("нет"), mileage(0) {}

Vehicle::Vehicle(int id, int d, int m, int y, string mod, int mil)
    : ID(id), day(d), month(m), year(y), model(mod), mileage(mil) {
}

Vehicle::Vehicle(const Vehicle& other)
    : ID(other.ID), day(other.day), month(other.month),
    year(other.year), model(other.model), mileage(other.mileage) {
}

Vehicle::~Vehicle() {}

int Vehicle::getID() const { return ID; }
int Vehicle::getDay() const { return day; }
int Vehicle::getMonth() const { return month; }
int Vehicle::getYear() const { return year; }
string Vehicle::getModel() const { return model; }
int Vehicle::getMileage() const { return mileage; }

void Vehicle::setID(int id) { ID = id; }
void Vehicle::setDate(int d, int m, int y) { day = d; month = m; year = y; }
void Vehicle::setModel(string mdl) { model = mdl; }
void Vehicle::setMileage(int mil) { mileage = mil; }
