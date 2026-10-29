#include "EnterpriseApp.h"
#include<string>
using namespace std;
EnterpriseApp::EnterpriseApp(const std::string& n, double r, double p, Developer* dev, const std::string& client, const std::string& sec)
    : MobileApp(n, r, p, dev), clientCompanyName(client), securityProtocol(sec) {
}

std::string EnterpriseApp::getClientCompanyName() const { return clientCompanyName; }
std::string EnterpriseApp::getSecurityProtocol() const { return securityProtocol; }

void EnterpriseApp::setClientCompanyName(const std::string& client) { clientCompanyName = client; }
void EnterpriseApp::setSecurityProtocol(const std::string& sec) { securityProtocol = sec; }

void EnterpriseApp::printTableRow(ostream& os) const {
    string verStr = versions.empty() ? "N/A" : versions.back().getVersionNumber();

    string spec = "B2B | Заказчик: " + clientCompanyName
        + " | Шифр: " + securityProtocol
        + " | Мин. ОЗУ: " + to_string(requirements.getMinRAM()) + "ГБ";

    os << "| " << left << setw(20) << name
        << " | " << right << setw(7) << fixed << setprecision(1) << rating
        << " | " << setw(16) << fixed << setprecision(2) << price
        << " | " << left << setw(20) << (leadDeveloper ? leadDeveloper->getFullName() : "Нет")
        << " | " << setw(8) << verStr
        << " | " << setw(43) << spec << " |\n";
}