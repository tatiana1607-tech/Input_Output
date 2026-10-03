#pragma once
#include "SmartPtr.h"
#include "MobilePhone.h"
#include "Customer.h"

class Purchase {
    SmartPointer<MobilePhone> phone;
    Customer customer;

public:
    Purchase(SmartPointer<MobilePhone> p, Customer c);

    double total() const;
    const MobilePhone& getPhone() const;
    const Customer& getCustomer() const;
};
