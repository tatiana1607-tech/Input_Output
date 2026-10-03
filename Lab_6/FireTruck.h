#pragma once
#include "GroundVehicle.h"
#include "SpecialVehicle.h"

class FireTruck : public GroundVehicle, public SpecialVehicle {
private:
    float waterTankVolume;
public:
    FireTruck();
    FireTruck(int id, int d, int m, int y, string mod, int mil,
        float w, string ch, bool s, string e, float wt);
    FireTruck(const FireTruck& other);
    ~FireTruck();

    float getWaterVolume() const;
    void setWaterVolume(float wt);

    bool isMaintenanceOverdue(int curD, int curM, int curY) override;
    void printInf() override;
    void saveToFile(ofstream& file) override;
    string getType() const override;
};