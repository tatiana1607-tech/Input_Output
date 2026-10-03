#pragma once
#include "Person.h"

class Worker : public Person {
private:
    int workerId;
    string specialization;
    bool isAvailable;
    static int nextId;

public:
    Worker();
    Worker(string n, int a, string spec);
    Worker(const Worker& other);
    ~Worker();

    int getWorkerId() const;
    string getSpecialization() const;
    bool isAvailableForWork() const;
    void setAvailable(bool available);
    void performWork();

    void display() const override;
    string getType() const override;

    static void resetNextId(int start);
};