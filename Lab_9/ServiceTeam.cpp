#include "ServiceTeam.h"
#include "Exceptions.h"

ServiceTeam::ServiceTeam() : teamName(""), workersCount(0), teamManager(nullptr) {
    for (int i = 0; i < 20; i++) workers[i] = nullptr;
}

ServiceTeam::ServiceTeam(string name) : teamName(name), workersCount(0), teamManager(nullptr) {
    cout << "  [Конструктор ServiceTeam: " << name << "]" << endl;
    for (int i = 0; i < 20; i++) workers[i] = nullptr;
    if (teamName.empty()) {
        throw InvalidInputException("Название команды не может быть пустым!");
    }
}

ServiceTeam::ServiceTeam(const ServiceTeam& other) : teamName(other.teamName), workersCount(other.workersCount), teamManager(other.teamManager) {
    for (int i = 0; i < workersCount; i++) workers[i] = other.workers[i];
    for (int i = workersCount; i < 20; i++) workers[i] = nullptr;
}

ServiceTeam::~ServiceTeam() {
    
}

string ServiceTeam::getTeamName() const { return teamName; }
void ServiceTeam::setManager(Manager* m) { teamManager = m; }

void ServiceTeam::addWorker(Worker* w) {
    if (w && workersCount < 20) {
        workers[workersCount++] = w;
        cout << "  Работник " << w->getName() << " добавлен в команду " << teamName << endl;
    }
}

void ServiceTeam::removeWorker(Worker* w) {
    for (int i = 0; i < workersCount; i++) {
        if (workers[i] == w) {
            for (int j = i; j < workersCount - 1; j++) workers[j] = workers[j + 1];
            workers[--workersCount] = nullptr;
            return;
        }
    }
}

int ServiceTeam::getWorkersCount() const { return workersCount; }
bool ServiceTeam::isEmpty() const { return workersCount == 0; }
Worker* ServiceTeam::getWorker(int index) const { return (index >= 0 && index < workersCount) ? workers[index] : nullptr; }
Manager* ServiceTeam::getManager() const { return teamManager; }

void ServiceTeam::assignWorkerToTask(Worker* w, const string& task) {
    if (!w) {
        throw CustomServiceException("Работник не существует!");
    }
    if (!w->isAvailableForWork()) {
        throw CustomServiceException("Работник " + w->getName() + " уже занят!");
    }
    w->setAvailable(false);
    cout << "  Работнику " << w->getName() << " поручено задание: " << task << endl;
}

void ServiceTeam::performService() {
    cout << "\n=== ВЫПОЛНЕНИЕ ОБСЛУЖИВАНИЯ КОМАНДОЙ " << teamName << " ===" << endl;

    
    if (isEmpty()) {
        throw NoWorkersException();
    }

    if (!teamManager) {
        throw NoManagerException();
    }

    teamManager->manageTeam();

    cout << "  Работники приступают к работе:" << endl;
    for (int i = 0; i < workersCount; i++) {
        if (workers[i]) {
            workers[i]->performWork();
        }
    }
    cout << "  Обслуживание территории завершено!" << endl;
}

void ServiceTeam::display() const {
    cout << "Команда: " << teamName << ", работников: " << workersCount;
    if (teamManager) cout << ", менеджер: " << teamManager->getName();
    else cout << ", менеджер: не назначен";
    cout << endl;
}