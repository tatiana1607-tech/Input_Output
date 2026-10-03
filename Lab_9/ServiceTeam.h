#pragma once
#include "Worker.h"
#include "Manager.h"

class ServiceTeam {
private:
    string teamName;
    Worker* workers[20];
    int workersCount;
    Manager* teamManager;

public:
    ServiceTeam();
    ServiceTeam(string name);
    ServiceTeam(const ServiceTeam& other);
    ~ServiceTeam();

    string getTeamName() const;
    void setManager(Manager* m);
    void addWorker(Worker* w);
    void removeWorker(Worker* w);
    int getWorkersCount() const;
    bool isEmpty() const;
    Worker* getWorker(int index) const;
    Manager* getManager() const;

    void assignWorkerToTask(Worker* w, const string& task);
    void performService();
    void display() const;
};