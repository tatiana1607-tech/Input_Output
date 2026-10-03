#include "Worker.h"

int Worker::nextId = 1;

Worker::Worker() : Person(), workerId(0), specialization(""), isAvailable(true) {
    
}

Worker::Worker(string n, int a, string spec) : Person(n, a), workerId(nextId++), specialization(spec), isAvailable(true) {
    
    if (specialization.empty()) {
        throw InvalidInputException("Специализация не может быть пустой!");
    }
}

Worker::Worker(const Worker& other) : Person(other), workerId(other.workerId), specialization(other.specialization), isAvailable(other.isAvailable) {
    
}

Worker::~Worker() {
    
}

int Worker::getWorkerId() const { return workerId; }
string Worker::getSpecialization() const { return specialization; }
bool Worker::isAvailableForWork() const { return isAvailable; }
void Worker::setAvailable(bool available) { isAvailable = available; }

void Worker::performWork() {
    if (isAvailable) {
        cout << "   Рабочий " << name << " (" << specialization << ") выполняет работу" << endl;
    }
}

void Worker::display() const {
    Person::display();
    cout << ", ID:" << workerId << ", Спец.:" << specialization << (isAvailable ? " (свободен)" : " (занят)");
}

string Worker::getType() const { return "Рабочий"; }

void Worker::resetNextId(int start) { nextId = start; }