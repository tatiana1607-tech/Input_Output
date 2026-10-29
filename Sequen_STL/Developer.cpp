#include "Developer.h"

Developer::Developer() : fullName("Не указано"), position("Junior Dev"), experienceYears(0) {}

Developer::Developer(const std::string& name, const std::string& pos, int exp)
    : fullName(name), position(pos), experienceYears(exp) {
}

std::string Developer::getFullName() const { return fullName; }
std::string Developer::getPosition() const { return position; }
int Developer::getExperience() const { return experienceYears; }

void Developer::setFullName(const std::string& name) { fullName = name; }
void Developer::setPosition(const std::string& pos) { position = pos; }
void Developer::setExperience(int exp) { experienceYears = exp; }

void Developer::printTableRow(std::ostream& os) const {
    os << "| " << std::left << std::setw(25) << fullName
        << " | " << std::setw(20) << position
        << " | " << std::right << std::setw(12) << experienceYears << " |\n";
}

bool Developer::operator<(const Developer& other) const {
    return experienceYears < other.experienceYears;
}

bool Developer::operator==(const Developer& other) const {
    return fullName == other.fullName;
}

std::ostream& operator<<(std::ostream& os, const Developer& dev) {
    dev.printTableRow(os);
    return os;
}