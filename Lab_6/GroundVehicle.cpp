#include "GroundVehicle.h"

GroundVehicle::GroundVehicle() : weight(1000), chassiType("кузовное") {}
GroundVehicle::GroundVehicle(float w, string ch) : weight(w), chassiType(ch) {}
GroundVehicle::GroundVehicle(const GroundVehicle& other) : weight(other.weight), chassiType(other.chassiType) {}
GroundVehicle::~GroundVehicle() {}

string GroundVehicle::getChassi() const { return chassiType; }
float GroundVehicle::getWeight() const { return weight; }
void GroundVehicle::setChassi(string ch) { chassiType = ch; }
void GroundVehicle::setWeight(float w) { weight = w; }