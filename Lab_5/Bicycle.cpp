#include "Bicycle.h"
#include <iomanip>
#include<string>

Bicycle::Bicycle() : Vehicle(), numberOfSpeeds(1), type("городской"),
material("алюминий"), frameSize("M") {
}

Bicycle::Bicycle(int id, int d, int m, int y, string mod, int mil,
    int speeds, string t, string mat, string size)
    : Vehicle(id, d, m, y, mod, mil),
    numberOfSpeeds(speeds), type(t), material(mat), frameSize(size) {
}

Bicycle::Bicycle(const Bicycle& other)
    : Vehicle(other),
    numberOfSpeeds(other.numberOfSpeeds),
    type(other.type),
    material(other.material),
    frameSize(other.frameSize) {
}

Bicycle::~Bicycle() {}

int Bicycle::getNumberOfSpeeds() const { return numberOfSpeeds; }

string Bicycle::getMaterial() const { return material; }
string Bicycle::getFrameSize() const { return frameSize; }

void Bicycle::setNumberOfSpeeds(int s) { numberOfSpeeds = s; }
void Bicycle::setType(string t) { type = t; }
void Bicycle::setMaterial(string m) { material = m; }
void Bicycle::setFrameSize(string s) { frameSize = s; }

bool Bicycle::isMaintenanceOverdue(int curD, int curM, int curY) {
    return (curY > year + 2);
}

void Bicycle::printInf() {
    string extra = "Скоростей: " + to_string(numberOfSpeeds) +
        ", Тип: " + type +
        ", Рама: " + material +
        ", Размер: " + frameSize;

    cout << "| " << setw(4) << ID
        << " | " << setw(12) << "Велосипед"
        << " | " << setw(14) << model
        << " | " << setw(8) << mileage
        << " | " << setw(38) << extra;
}


void Bicycle::saveToFile(ofstream& file) {
    file << "Bicycle\n";
    file << "ID: " << ID << "\n";
    file << "Модель: " << model << "\n";
    file << "Пробег: " << mileage << "\n";
    file << "Количество скоростей: " << numberOfSpeeds << "\n";
    file << "Тип велосипеда: " << type << "\n";
    file << "Материал рамы: " << material << "\n";
    file << "Размер рамы: " << frameSize << "\n";
    file << "Дата ТО (день месяц год): " << day << " " << month << " " << year << "\n";
    file << "---\n";
}

bool Bicycle::isSuitableForHeight(int heightCm) {
    if (frameSize == "S") return (heightCm >= 150 && heightCm <= 165);
    if (frameSize == "M") return (heightCm >= 165 && heightCm <= 178);
    if (frameSize == "L") return (heightCm >= 178 && heightCm <= 190);
    if (frameSize == "XL") return (heightCm >= 190);
    return false;
}

string Bicycle::getCategory() {
    if (numberOfSpeeds >= 21 && type == "горный")
        return "Профессиональный";
    else if (numberOfSpeeds >= 18)
        return "Любительский";
    else if (numberOfSpeeds >= 6)
        return "Стандартный";
    else
        return "Начальный";
}
string  Bicycle::getType() const  { return "Велосипед"; }