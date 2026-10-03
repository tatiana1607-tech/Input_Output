#pragma once
#include "Vehicle.h"
#include <string>
using namespace std;

class SpecialVehicle : public virtual Vehicle {
protected:
    bool hasSiren;
    string equipment;
public:
    SpecialVehicle();
    SpecialVehicle(bool s, string e);
    SpecialVehicle(const SpecialVehicle& other);
    virtual ~SpecialVehicle();

    string getEquipment() const;
    bool getHasSiren() const;
    void setEquipment(string e);
    void setHasSiren(bool s);
};