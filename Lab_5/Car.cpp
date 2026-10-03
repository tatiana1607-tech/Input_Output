#include "Car.h"
#include <iomanip>
#include<string>

Car::Car() : Vehicle(), engineType("бензин"), engineVolume(1.6), fuelConsumption(7.5) {}

Car::Car(int id, int d, int m, int y, string mod, int mil,
    string type, float volume, float cons)
    : Vehicle(id, d, m, y, mod, mil),
    engineType(type), engineVolume(volume), fuelConsumption(cons) {
}

Car::Car(const Car& other)
    : Vehicle(other),
    engineType(other.engineType),
    engineVolume(other.engineVolume),
    fuelConsumption(other.fuelConsumption) {
}

Car::~Car() {}

string Car::getEngineType() const { return engineType; }
float Car::getEngineVolume() const { return engineVolume; }
float Car::getFuelConsumption() const { return fuelConsumption; }

void Car::setEngineType(string type) { engineType = type; }
void Car::setEngineVolume(float volume) { engineVolume = volume; }
void Car::setFuelConsumption(float consumption) { fuelConsumption = consumption; }

bool Car::isMaintenanceOverdue(int curD, int curM, int curY) {
    return (curY > year + 1);
}

void Car::printInf() {
    string extra = "Двигатель: " + engineType +
        ", " + to_string(engineVolume) + " л, " +
        to_string(fuelConsumption) + " л/100км";

    cout << "| " << setw(4) << ID
        << " | " << setw(12) << "Автомобиль"
        << " | " << setw(14) << model
        << " | " << setw(8) << mileage
        << " | " << setw(38) << extra;
}


void Car::saveToFile(ofstream& file) {
    file << "Car\n";
    file << "ID: " << ID << "\n";
    file << "Модель: " << model << "\n";
    file << "Пробег: " << mileage << "\n";
    file << "Тип двигателя: " << engineType << "\n";
    file << "Объем двигателя: " << engineVolume << "\n";
    file << "Расход топлива: " << fuelConsumption << "\n";
    file << "Дата ТО (день месяц год): " << day << " " << month << " " << year << "\n";
    file << "---\n";
}

float Car::calculateTripCost(float distance, float pricePerLiter) {
    return (fuelConsumption / 100.0f) * distance * pricePerLiter;
}

string Car::getCategory() {
    if (engineVolume < 1.2) return "Микролитражный";
    if (engineVolume < 1.6) return "Малолитражный";
    if (engineVolume < 2.0) return "Средний";
    if (engineVolume < 3.0) return "Бизнес-класс";
    return "Премиальный / Спортивный";
}
string Car::getType() const  { return "Автомобиль"; } 