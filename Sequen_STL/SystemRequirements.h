#pragma once
#include <iostream>
#include <string>

class SystemRequirements {
private:
    std::string osVersion;
    int minRAM_GB;
    double storageMB;

public:
    SystemRequirements();
    SystemRequirements(const std::string& os, int ram, double storage);

    std::string getOSVersion() const;
    int getMinRAM() const;
    double getStorageMB() const;

    void setOSVersion(const std::string& os);
    void setMinRAM(int ram);
    void setStorageMB(double storage);

    void display() const;
};