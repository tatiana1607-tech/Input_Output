#pragma once
#include <iostream>
#include <string>
#include <iomanip>

class Developer {
private:
    std::string fullName;
    std::string position;
    int experienceYears;

public:
    Developer();
    Developer(const std::string& name, const std::string& pos, int exp);

    std::string getFullName() const;
    std::string getPosition() const;
    int getExperience() const;

    void setFullName(const std::string& name);
    void setPosition(const std::string& pos);
    void setExperience(int exp);

    void printTableRow(std::ostream& os) const;

    bool operator<(const Developer& other) const;
    bool operator==(const Developer& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Developer& dev);
};