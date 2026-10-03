#include "Electric_car.h"
#include <iomanip>
#include<string>

ElectroCar::ElectroCar() : Vehicle(), batteryCapacity(50), range(200), chargingTime(5) {}

ElectroCar::ElectroCar(int id, int d, int m, int y, string mod, int mil,
    float cap, int r, float ch)
    : Vehicle(id, d, m, y, mod, mil),
    batteryCapacity(cap), range(r), chargingTime(ch) {
}

ElectroCar::ElectroCar(const ElectroCar& other)
    : Vehicle(other),
    batteryCapacity(other.batteryCapacity),
    range(other.range),
    chargingTime(other.chargingTime) {
}

ElectroCar::~ElectroCar() {}

float ElectroCar::getBatteryCapacity() const { return batteryCapacity; }
int ElectroCar::getRange() const { return range; }
float ElectroCar::getChargingTime() const { return chargingTime; }

void ElectroCar::setBatteryCapacity(float c) { batteryCapacity = c; }
void ElectroCar::setRange(int r) { range = r; }
void ElectroCar::setChargingTime(float t) { chargingTime = t; }

bool ElectroCar::isMaintenanceOverdue(int curD, int curM, int curY) {
    return (curY > year + 1);
}

void ElectroCar::printInf() {
    string extra = "Батарея: " + to_string(batteryCapacity) +
        " кВтч, Ход: " + to_string(range) +
        " км, Зарядка: " + to_string(chargingTime) + " ч";

    cout << "| " << setw(4) << ID
        << " | " << setw(12) << "Электроавто"
        << " | " << setw(14) << model
        << " | " << setw(8) << mileage
        << " | " << setw(38) << extra;
}

void ElectroCar::saveToFile(ofstream& file) {
    file << "ElectroCar\n";
    file << "ID: " << ID << "\n";
    file << "Модель: " << model << "\n";
    file << "Пробег: " << mileage << "\n";
    file << "Емкость батареи (кВтч): " << batteryCapacity << "\n";
    file << "Запас хода (км): " << range << "\n";
    file << "Время полной зарядки (ч): " << chargingTime << "\n";
    file << "Дата ТО (день месяц год): " << day << " " << month << " " << year << "\n";
    file << "---\n";
}

float ElectroCar::calculateChargeCost(float pricePerKwh) {
    return batteryCapacity * pricePerKwh;
}

float ElectroCar::getChargingTimeForDistance(int distanceKm) {
    if (distanceKm > range)
        return -1;
    return (float(distanceKm) / range) * chargingTime;
}
string ElectroCar::getType() const  { return "Электроавтомобиль"; }
