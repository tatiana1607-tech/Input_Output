#include "Territory.h"

Building::Building() : address(""), floors(0), area(0) {}

Building::Building(string addr, int f, double a) : address(addr), floors(f), area(a) {
    if (area <= 0) {
        throw InvalidInputException("Площадь здания должна быть положительной!");
    }
}

Building::Building(const Building& other) : address(other.address), floors(other.floors), area(other.area) {}
Building::~Building() {}

void Building::display() const {
    cout << "    Здание: " << address << ", " << floors << " эт., " << area << " кв.м";
}

Territory::Territory() : name(""), totalArea(0), buildingsCount(0) {}

Territory::Territory(string n, double area) : name(n), totalArea(area), buildingsCount(0) {
  
    if (area <= 0) {
        throw InvalidInputException("Площадь территории должна быть положительной!");
    }
}

Territory::Territory(const Territory& other) : name(other.name), totalArea(other.totalArea), buildingsCount(other.buildingsCount) {
    for (int i = 0; i < buildingsCount; i++) buildings[i] = other.buildings[i];
}

Territory::~Territory() {
    
}

string Territory::getName() const { return name; }
double Territory::getTotalArea() const { return totalArea; }

void Territory::addBuilding(string address, int floors, double area) {
    if (buildingsCount >= 10) {
        throw BuildingLimitException();
    }
    buildings[buildingsCount++] = Building(address, floors, area);
}

int Territory::getBuildingsCount() const { return buildingsCount; }

void Territory::display() const {
    cout << "Территория: " << name << ", площадь: " << totalArea << " кв.м, зданий: " << buildingsCount << endl;
    for (int i = 0; i < buildingsCount; i++) {
        buildings[i].display();
        cout << endl;
    }
}