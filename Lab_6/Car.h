#pragma once
#include "GroundVehicle.h"

class Car : public GroundVehicle {
private:
    string engineType;
    float engineVolume;
    float fuelConsumption;

public:
    Car();
    Car(int id, int d, int m, int y, string mod, int mil, float w, string ch,
        string type, float volume, float cons);
    Car(const Car& other);
    ~Car();

    string getEngineType() const;
    float getEngineVolume() const;
    float getFuelConsumption() const;
    void setEngineType(string type);
    void setEngineVolume(float volume);
    void setFuelConsumption(float consumption);

    bool isMaintenanceOverdue(int curD, int curM, int curY) override;
    void printInf() override;
    void saveToFile(ofstream& file) override;

    float calculateTripCost(float distance, float pricePerLiter);
    string getCategory();
    string getType() const override;
};