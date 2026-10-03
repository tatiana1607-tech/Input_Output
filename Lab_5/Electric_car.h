#pragma once
#include "Vehicle.h"

class ElectroCar : public Vehicle {
private:
    float batteryCapacity;
    int range;
    float chargingTime;

public:
    ElectroCar();
    ElectroCar(int id, int d, int m, int y, string mod, int mil,
        float cap, int r, float ch);
    ElectroCar(const ElectroCar& other);
    ~ElectroCar();

    float getBatteryCapacity() const;
    int getRange() const;
    float getChargingTime() const;

    void setBatteryCapacity(float c);
    void setRange(int r);
    void setChargingTime(float t);

    bool isMaintenanceOverdue(int curD, int curM, int curY) override;
    void printInf() override;
    void saveToFile(ofstream& file) override;

    float calculateChargeCost(float pricePerKwh);
    float getChargingTimeForDistance(int distanceKm);
    string getType() const;
};
