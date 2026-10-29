#pragma once
#include "MobileApp.h"

class EnterpriseApp : public MobileApp {
private:
    std::string clientCompanyName;
    std::string securityProtocol;

public:
    EnterpriseApp(const std::string& n = "Корп. Софт", double r = 0.0, double p = 0.0,
        Developer* dev = nullptr, const std::string& client = "Заказчик", const std::string& sec = "AES-256");

    std::string getClientCompanyName() const;
    std::string getSecurityProtocol() const;

    void setClientCompanyName(const std::string& client);
    void setSecurityProtocol(const std::string& sec);

    void printTableRow(std::ostream& os) const override;
};