#include "SystemRequirements.h"

SystemRequirements::SystemRequirements()
    : osVersion("Android 10.0+"), minRAM_GB(4), storageMB(200.0) {
}

SystemRequirements::SystemRequirements(const std::string& os, int ram, double storage)
    : osVersion(os), minRAM_GB(ram), storageMB(storage) {
}

std::string SystemRequirements::getOSVersion() const { return osVersion; }
int SystemRequirements::getMinRAM() const { return minRAM_GB; }
double SystemRequirements::getStorageMB() const { return storageMB; }

void SystemRequirements::setOSVersion(const std::string& os) { osVersion = os; }
void SystemRequirements::setMinRAM(int ram) { minRAM_GB = ram; }
void SystemRequirements::setStorageMB(double storage) { storageMB = storage; }

void SystemRequirements::display() const {
    std::cout << osVersion << ", ÎÇÓ: " << minRAM_GB << "ÃÁ, Äèñê: " << storageMB << "ÌÁ";
}