#include "SpecialVehicle.h"

SpecialVehicle::SpecialVehicle() : hasSiren(true), equipment("радиостанция") {}
SpecialVehicle::SpecialVehicle(bool s, string e) : hasSiren(s), equipment(e) {}
SpecialVehicle::SpecialVehicle(const SpecialVehicle& other) : hasSiren(other.hasSiren), equipment(other.equipment) {}
SpecialVehicle::~SpecialVehicle() {}

string SpecialVehicle::getEquipment() const { return equipment; }
bool SpecialVehicle::getHasSiren() const { return hasSiren; }
void SpecialVehicle::setEquipment(string e) { equipment = e; }
void SpecialVehicle::setHasSiren(bool s) { hasSiren = s; }