#include "FireTruck.h"
#include <iomanip>

FireTruck::FireTruck() : GroundVehicle(), SpecialVehicle(), waterTankVolume(100) {}

FireTruck::FireTruck(int id, int d, int m, int y, string mod, int mil,
    float w, string ch, bool s, string e, float wt)
    : Vehicle(id, d, m, y, mod, mil), GroundVehicle(w, ch), SpecialVehicle(s, e), waterTankVolume(wt) {
}

FireTruck::FireTruck(const FireTruck& other)
    : Vehicle(other), GroundVehicle(other), SpecialVehicle(other), waterTankVolume(other.waterTankVolume) {
}

FireTruck::~FireTruck() {}

float FireTruck::getWaterVolume() const { return waterTankVolume; }
void FireTruck::setWaterVolume(float wt) { waterTankVolume = wt; }

bool FireTruck::isMaintenanceOverdue(int curD, int curM, int curY) {
    if (curY > year + 1) return true;
    if (curY == year + 1 && curM > month) return true;
    if (curY == year + 1 && curM == month && curD > day) return true;
    return false;
}

void FireTruck::printInf() {
    cout << "| " << setw(4) << right << ID
        << " | " << setw(14) << left << "Пожарная"
        << " | " << setw(14) << left << model
        << " | " << setw(8) << right << mileage
        << " | " << setw(45) << left
        << ("Цистерна: " + to_string((int)waterTankVolume) + "л, Сирена: " +
            (getHasSiren() ? "есть" : "нет") + ", Оборудование: " + getEquipment() +
            ", Вес: " + to_string((int)getWeight()) + "кг, Шасси: " + getChassi());
}

void FireTruck::saveToFile(ofstream& file) {
    file << "FireTruck\n";
    file << "ID: " << ID << "\n";
    file << "Модель: " << model << "\n";
    file << "Пробег: " << mileage << "\n";
    file << "Вес: " << getWeight() << "\n";
    file << "Тип шасси: " << getChassi() << "\n";
    file << "Сирена: " << (getHasSiren() ? "есть" : "нет") << "\n";
    file << "Оборудование: " << getEquipment() << "\n";
    file << "Объем цистерны: " << waterTankVolume << "\n";
    file << "Дата ТО: " << day << " " << month << " " << year << "\n";
    file << "---\n";
}

string FireTruck::getType() const { return "Пожарная машина"; }