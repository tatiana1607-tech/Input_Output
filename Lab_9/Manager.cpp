#include "Manager.h"

int Manager::nextId = 1;

Manager::Manager() : Person(), managerId(0), department(""), teamSize(0) {
    
    for (int i = 0; i < 10; i++) team[i] = nullptr;
}

Manager::Manager(string n, int a, string dept) : Person(n, a), managerId(nextId++), department(dept), teamSize(0) {
   
    for (int i = 0; i < 10; i++) team[i] = nullptr;
    if (department.empty()) {
        throw InvalidInputException("Название отдела не может быть пустым!");
    }
}

Manager::Manager(const Manager& other) : Person(other), managerId(other.managerId), department(other.department), teamSize(other.teamSize) {
   
    for (int i = 0; i < teamSize; i++) team[i] = other.team[i];
    for (int i = teamSize; i < 10; i++) team[i] = nullptr;
}

Manager::~Manager() {
   
}

int Manager::getManagerId() const { return managerId; }
string Manager::getDepartment() const { return department; }

void Manager::addWorker(Worker* w) {
    if (w && teamSize < 10) {
        team[teamSize++] = w;
    }
}

void Manager::removeWorker(Worker* w) {
    for (int i = 0; i < teamSize; i++) {
        if (team[i] == w) {
            for (int j = i; j < teamSize - 1; j++) team[j] = team[j + 1];
            team[--teamSize] = nullptr;
            return;
        }
    }
}

int Manager::getTeamSize() const { return teamSize; }
Worker* Manager::getWorker(int index) const { return (index >= 0 && index < teamSize) ? team[index] : nullptr; }

void Manager::manageTeam() {
    cout << "   Менеджер " << name << " управляет командой из " << teamSize << " человек" << endl;
}

void Manager::display() const {
    Person::display();
    cout << ", Менеджер ID:" << managerId << ", Отдел:" << department << ", Команда:" << teamSize;
}

string Manager::getType() const { return "Менеджер"; }

void Manager::resetNextId(int start) { nextId = start; }