#pragma once
#include "SmartPtr.h"
#include "MobilePhone.h"
#include "Manager.h"

class Sale {
    SmartPointer<MobilePhone> phone;
    Manager manager;

public:
    Sale(SmartPointer<MobilePhone> p, Manager m);

    const MobilePhone& getPhone() const;
    const Manager& getManager() const;
};
