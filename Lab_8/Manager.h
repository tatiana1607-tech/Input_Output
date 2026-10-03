#pragma once
#include <string>
using namespace std;

class Manager {
    string name;

public:
    Manager();
    Manager(string n);
    Manager(const Manager& obj);

    string getName() const;
};

