#pragma once
#include "Person.h"
#include "Worker.h"

class Manager : public Person {
private:
    int managerId;
    string department;
    Worker* team[10];
    int teamSize;
    static int nextId;

public:
    Manager();
    Manager(string n, int a, string dept);
    Manager(const Manager& other);
    ~Manager();

    int getManagerId() const;
    string getDepartment() const;
    void addWorker(Worker* w);
    void removeWorker(Worker* w);
    int getTeamSize() const;
    Worker* getWorker(int index) const;
    void manageTeam();

    void display() const override;
    string getType() const override;

    static void resetNextId(int start);
};