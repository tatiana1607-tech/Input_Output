#pragma once
#include "Vehicle.h"

class Bicycle : public Vehicle {
private:
    int numberOfSpeeds;
    string type;
    string material;
    string frameSize;

public:
    Bicycle();
    Bicycle(int id, int d, int m, int y, string mod, int mil,
        int speeds, string t, string mat, string size);
    Bicycle(const Bicycle& other);
    ~Bicycle();

    int getNumberOfSpeeds() const;
    
    string getMaterial() const;
    string getFrameSize() const;

    void setNumberOfSpeeds(int s);
    void setType(string t);
    void setMaterial(string m);
    void setFrameSize(string s);

    bool isMaintenanceOverdue(int curD, int curM, int curY) override;
    void printInf() override;
    void saveToFile(ofstream& file) override;

    bool isSuitableForHeight(int heightCm);
    string getCategory();
    string getType() const;
};
