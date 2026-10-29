#include "UtilityApp.h"
#include<string>
using namespace std;
UtilityApp::UtilityApp(const std::string& n, double r, double p, Developer* dev, bool sub, const std::string& osVer)
    : MobileApp(n, r, p, dev), isSubscriptionRequired(sub), targetOSVersion(osVer) {
}

bool UtilityApp::getIsSubscriptionRequired() const { return isSubscriptionRequired; }
std::string UtilityApp::getTargetOSVersion() const { return targetOSVersion; }

void UtilityApp::setIsSubscriptionRequired(bool sub) { isSubscriptionRequired = sub; }
void UtilityApp::setTargetOSVersion(const std::string& osVer) { targetOSVersion = osVer; }

void UtilityApp::printTableRow(ostream& os) const {
    
    string verStr = versions.empty() ? "N/A" : versions.back().getVersionNumber();

    
    string spec = "B2C | Подписка: " + string(isSubscriptionRequired ? "Да" : "Нет")
        + " | ОС: " + requirements.getOSVersion();

    os << "| " << left << setw(20) << name
        << " | " << right << setw(7) << fixed << setprecision(1) << rating
        << " | " << setw(16) << fixed << setprecision(2) << price
        << " | " << left << setw(20) << (leadDeveloper ? leadDeveloper->getFullName() : "Нет")
        << " | " << setw(8) << verStr
        << " | " << setw(43) << spec << " |\n";
}