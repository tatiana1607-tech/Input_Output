	#include "Customer.h"

	Customer::Customer() : name("") {}
	Customer::Customer(string n) : name(n) {}
	Customer::Customer(const Customer& obj) : name(obj.name) {}

	string Customer::getName() const { return name; }
