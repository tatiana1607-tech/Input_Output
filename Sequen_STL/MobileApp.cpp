#include "MobileApp.h"

MobileApp::MobileApp(const std::string& n, double r, double p, Developer* dev, const SystemRequirements& req)
    : name(n), rating(r), price(p), leadDeveloper(dev), requirements(req) {
}

MobileApp::~MobileApp() {}

std::string MobileApp::getName() const { return name; }
double MobileApp::getRating() const { return rating; }
double MobileApp::getPrice() const { return price; }
Developer* MobileApp::getLeadDeveloper() const { return leadDeveloper; }

void MobileApp::setName(const std::string& n) { name = n; }
void MobileApp::setRating(double r) { rating = r; }
void MobileApp::setPrice(double p) { price = p; }
void MobileApp::setLeadDeveloper(Developer* dev) { leadDeveloper = dev; }

void MobileApp::addVersion(const Version& ver) {
    versions.push_back(ver);
}

void MobileApp::printTableRow(std::ostream& os) const {
    os << "| " << std::left << std::setw(20) << name
        << " | " << std::right << std::setw(7) << std::fixed << std::setprecision(1) << rating
        << " | " << std::setw(15) << std::fixed << std::setprecision(2) << price << " руб."
        << " | " << std::left << std::setw(20) << (leadDeveloper ? leadDeveloper->getFullName() : "Не назначен")
        << " | " << std::left << std::setw(8) << (versions.empty() ? "N/A" : versions.back().getVersionNumber());
}

bool MobileApp::operator<(const MobileApp& other) const {
    return rating < other.rating;
}

bool MobileApp::operator==(const MobileApp& other) const {
    return name == other.name;
}