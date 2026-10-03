#pragma once
#include "Vehicle.h"
#include <string>
using namespace std;

class GroundVehicle : public virtual Vehicle {
protected:
    float weight;
    string chassiType;
public:
    GroundVehicle();
    GroundVehicle(float w, string ch);
    GroundVehicle(const GroundVehicle& other);
    virtual ~GroundVehicle();

    string getChassi() const;
    float getWeight() const;
    void setChassi(string ch);
    void setWeight(float w);
};