#pragma once
#include <iostream>
#include <string>

class Version {
private:
    std::string versionNumber;
    std::string releaseDate;
    double sizeMB;

public:
    Version();
    Version(const std::string& ver, const std::string& date, double size);

    std::string getVersionNumber() const;
    std::string getReleaseDate() const;
    double getSizeMB() const;

    void display() const;
};