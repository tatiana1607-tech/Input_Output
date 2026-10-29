#pragma once
#include "MobileApp.h"

class UtilityApp : public MobileApp {
private:
    bool isSubscriptionRequired;
    std::string targetOSVersion;

public:
    UtilityApp(const std::string& n = "Утилита", double r = 0.0, double p = 0.0,
        Developer* dev = nullptr, bool sub = false, const std::string& osVer = "Android 10+");

    bool getIsSubscriptionRequired() const;
    std::string getTargetOSVersion() const;

    void setIsSubscriptionRequired(bool sub);
    void setTargetOSVersion(const std::string& osVer);

    void printTableRow(std::ostream& os) const override;
};