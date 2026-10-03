#include "Manager.h"

Manager::Manager() : name("") {}
Manager::Manager(string n) : name(n) {}
Manager::Manager(const Manager& obj) : name(obj.name) {}

string Manager::getName() const { return name; }
