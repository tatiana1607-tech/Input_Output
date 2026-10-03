#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <windows.h>
#include "Person.h"
#include "Worker.h"
#include "Manager.h"
#include "Territory.h"
#include "ServiceTeam.h"
#include "Exceptions.h"

using namespace std;


Worker* workers[100];
int workersCount = 0;

Manager* managers[100];
int managersCount = 0;

Territory* territories[100];
int territoriesCount = 0;

ServiceTeam* teams[100];
int teamsCount = 0;


void myTerminate() {
    cerr << "\n============================================================" << endl;
    cerr << "    ПРОГРАММА АВАРИЙНО ЗАВЕРШЕНА (terminate вызван)        " << endl;
    cerr << "     Необработанное исключение!                              " << endl;
    cerr << "===============================================================" << endl;
    exit(1);
}


int getIntInput(const string& prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ошибка! Введите число: ";
    }
    cin.ignore(10000, '\n');
    return value;
}

double getDoubleInput(const string& prompt) {
    double value;
    cout << prompt;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ошибка! Введите число: ";
    }
    cin.ignore(10000, '\n');
    return value;
}

string getStringInput(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    return value;
}


void allocateMemory() {
    cout << "\n=== ДЕМОНСТРАЦИЯ ИСКЛЮЧЕНИЯ ПРИ ВЫДЕЛЕНИИ ПАМЯТИ (new) ===" << endl;
    cout << "Попытка выделить огромный массив..." << endl;
    try {
        int* hugeArray = new int[1000000000];
        delete[] hugeArray;
        cout << "Память выделена успешно!" << endl;
    }
    catch (bad_alloc&) {
        cout << "→ Генерация bad_alloc, преобразуем в MemoryAllocationException" << endl;
        throw MemoryAllocationException();
    }
}


void innerFunction() {
    cout << "  Внутренняя функция генерирует исключение..." << endl;
    throw InvalidInputException("Ошибка во внутренней функции!");
}

void outerFunction() {
    try {
        innerFunction();
    }
    catch (InvalidInputException& e) {
        cout << "   Перехвачено на промежуточном уровне: " << e.what() << endl;
        cout << "   Перенаправляем исключение выше (throw без параметра)" << endl;
        throw;
    }
}


void showAllTeams() {
    if (teamsCount == 0) {
        cout << "Нет созданных команд!" << endl;
        return;
    }
    cout << "\n=== СПИСОК КОМАНД ===" << endl;
    for (int i = 0; i < teamsCount; i++) {
        cout << i + 1 << ". ";
        teams[i]->display();
    }
}
void showAllWorkers() {
    if (workersCount == 0) {
        cout << "Нет работников!" << endl;
        return;
    }
    cout << "\n=== СПИСОК РАБОТНИКОВ ===" << endl;
    for (int i = 0; i < workersCount; i++) {
        cout << i + 1 << ". ";
        workers[i]->display();
        cout << endl;
    }
}


void showAllManagers() {
    if (managersCount == 0) {
        cout << "Нет менеджеров!" << endl;
        return;
    }
    cout << "\n=== СПИСОК МЕНЕДЖЕРОВ ===" << endl;
    for (int i = 0; i < managersCount; i++) {
        cout << i + 1 << ". ";
        managers[i]->display();
        cout << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    
    set_terminate(myTerminate);

    
    Worker::resetNextId(1);
    Manager::resetNextId(1);

    int choice;

    cout << "\n=============================================================" << endl;
    cout << "       ЖИЛИЩНО-ЭКСПЛУАТАЦИОННАЯ СЛУЖБА                      " << endl;
    cout << "      Лабораторная работа №9: Обработка исключений          " << endl;
    cout << "===============================================================" << endl;

    do {
        cout << "\n==================== МЕНЮ ====================" << endl;
        cout << "1. Добавить работника" << endl;
        cout << "2. Добавить менеджера" << endl;
        cout << "3. Добавить территорию" << endl;
        cout << "4. Создать сервисную команду" << endl;
        cout << "5. Добавить работника в команду" << endl;
        cout << "6. Назначить менеджера команде" << endl;
        cout << "7. Выполнить обслуживание территории (МОЖЕТ ВЫЗВАТЬ АВАРИЮ)" << endl;
        cout << "8. Назначить работнику задание" << endl;
        cout << "9. Показать всех работников" << endl;
        cout << "10. Показать всех менеджеров" << endl;
        cout << "11. Показать все команды" << endl;
        cout << "12. Показать все территории" << endl;
        cout << "13. ВЫЗВАТЬ АВАРИЙНОЕ ЗАВЕРШЕНИЕ (НЕТ ОБРАБОТЧИКА)" << endl;
        cout << "14. Демонстрация исключения с operator new" << endl;
        cout << "15. Демонстрация перенаправления исключения" << endl;
        cout << "16. Выход" << endl;
        cout << "==============================================" << endl;

        choice = getIntInput("Ваш выбор: ");

        if (choice == 1) {
            try {
                cout << "\n--- ДОБАВЛЕНИЕ РАБОТНИКА ---" << endl;
                string name = getStringInput("Имя: ");
                int age = getIntInput("Возраст: ");
                string spec = getStringInput("Специализация: ");

                workers[workersCount] = new Worker(name, age, spec);
                cout << "✓ Работник добавлен! ID: " << workers[workersCount]->getWorkerId() << endl;
                workersCount++;
            }
            catch (InvalidInputException& e) {
                cout << "✗ ОШИБКА: " << e.what() << endl;
            }
        }
        else if (choice == 2) {
            try {
                cout << "\n--- ДОБАВЛЕНИЕ МЕНЕДЖЕРА ---" << endl;
                string name = getStringInput("Имя: ");
                int age = getIntInput("Возраст: ");
                string dept = getStringInput("Отдел: ");

                managers[managersCount] = new Manager(name, age, dept);
                cout << "✓ Менеджер добавлен! ID: " << managers[managersCount]->getManagerId() << endl;
                managersCount++;
            }
            catch (InvalidInputException& e) {
                cout << "✗ ОШИБКА: " << e.what() << endl;
            }
        }
        else if (choice == 3) {
            try {
                cout << "\n--- ДОБАВЛЕНИЕ ТЕРРИТОРИИ ---" << endl;
                string name = getStringInput("Название территории: ");
                double area = getDoubleInput("Площадь (кв.м): ");

                territories[territoriesCount] = new Territory(name, area);
                cout << " Территория добавлена!" << endl;
                territoriesCount++;
            }
            catch (InvalidInputException& e) {
                cout << " ОШИБКА В КОНСТРУКТОРЕ: " << e.what() << endl;

            }
        }
        else if (choice == 4) {
            try {
                cout << "\n--- СОЗДАНИЕ КОМАНДЫ ---" << endl;
                string teamName = getStringInput("Название команды: ");

                teams[teamsCount] = new ServiceTeam(teamName);
                cout << "✓ Команда создана!" << endl;
                teamsCount++;
            }
            catch (InvalidInputException& e) {
                cout << " ОШИБКА: " << e.what() << endl;
            }
        }
        else if (choice == 5) {
            if (teamsCount == 0) {
                cout << "Сначала создайте команду (пункт 4)!" << endl;
                continue;
            }
            if (workersCount == 0) {
                cout << "Нет работников для добавления!" << endl;
                continue;
            }

            showAllTeams();
            int ti = getIntInput("Выберите команду (номер): ") - 1;

            showAllWorkers();
            int wi = getIntInput("Выберите работника (номер): ") - 1;

            if (ti >= 0 && ti < teamsCount && wi >= 0 && wi < workersCount) {
                teams[ti]->addWorker(workers[wi]);
            }
            else {
                cout << "Неверный выбор!" << endl;
            }
        }
        else if (choice == 6) {
            if (teamsCount == 0) {
                cout << "Сначала создайте команду (пункт 4)!" << endl;
                continue;
            }
            if (managersCount == 0) {
                cout << "Нет менеджеров для назначения!" << endl;
                continue;
            }

            showAllTeams();
            int ti = getIntInput("Выберите команду (номер): ") - 1;

            showAllManagers();
            int mi = getIntInput("Выберите менеджера (номер): ") - 1;

            if (ti >= 0 && ti < teamsCount && mi >= 0 && mi < managersCount) {
                teams[ti]->setManager(managers[mi]);
                cout << " Менеджер назначен команде!" << endl;
            }
            else {
                cout << "Неверный выбор!" << endl;
            }
        }
        else if (choice == 7) {
            if (teamsCount == 0) {
                cout << "Нет созданных команд!" << endl;
                continue;
            }

            showAllTeams();
            int ti = getIntInput("Выберите команду для обслуживания (номер): ") - 1;

            if (ti >= 0 && ti < teamsCount) {
               
                cout << "\n ВНИМАНИЕ: Если команда пуста или нет менеджера - программа аварийно завершится!" << endl;
                cout << "Вы уверены? (1 - да / 0 - нет): ";
                int confirm;
                cin >> confirm;
                cin.ignore();
                if (confirm == 1) {
                    teams[ti]->performService(); 
                }
            }
        }
        else if (choice == 8) {
            if (teamsCount == 0) {
                cout << "Сначала создайте команду!" << endl;
                continue;
            }

            showAllTeams();
            int ti = getIntInput("Выберите команду: ") - 1;

            if (ti >= 0 && ti < teamsCount && teams[ti]->getWorkersCount() > 0) {
                cout << "Работники команды " << teams[ti]->getTeamName() << ":" << endl;
                for (int i = 0; i < teams[ti]->getWorkersCount(); i++) {
                    Worker* w = teams[ti]->getWorker(i);
                    cout << "  " << i + 1 << ". " << w->getName()
                        << " (" << w->getSpecialization() << ") - "
                        << (w->isAvailableForWork() ? "свободен" : "занят") << endl;
                }
                int wi = getIntInput("Выберите работника: ") - 1;
                string task = getStringInput("Введите задание: ");

                try {
                    teams[ti]->assignWorkerToTask(teams[ti]->getWorker(wi), task);
                    cout << "✓ Задание назначено!" << endl;
                }
                catch (CustomServiceException& e) {
                    cout << "✗ ПОЛЬЗОВАТЕЛЬСКОЕ ИСКЛЮЧЕНИЕ: " << e.what() << endl;
                }
            }
            else {
                cout << "В команде нет работников или неверный выбор!" << endl;
            }
        }
        else if (choice == 9) {
            showAllWorkers();
        }
        else if (choice == 10) {
            showAllManagers();
        }
        else if (choice == 11) {
            showAllTeams();
        }
        else if (choice == 12) {
            if (territoriesCount == 0) {
                cout << "Нет территорий!" << endl;
            }
            else {
                cout << "\n=== ТЕРРИТОРИИ ===" << endl;
                for (int i = 0; i < territoriesCount; i++) {
                    territories[i]->display();
                    cout << endl;
                }
            }
        }
        else if (choice == 13) {
            cout << "\n============================================================" << endl;
            cout << "       ГЕНЕРАЦИЯ НЕОБРАБАТЫВАЕМОГО ИСКЛЮЧЕНИЯ                 " << endl;
            cout << "     Будет вызвана функция terminate()                      " << endl;
            cout << "==============================================================" << endl;

            
            throw NoWorkersException(); 
        }
        else if (choice == 14) {
            try {
                allocateMemory();
            }
            catch (MemoryAllocationException& e) {
                cout << "✗ Перехвачено исключение: " << e.what() << endl;
            }
        }
        else if (choice == 15) {
            cout << "\n=== ДЕМОНСТРАЦИЯ ПЕРЕНАПРАВЛЕНИЯ ИСКЛЮЧЕНИЯ ===" << endl;
            try {
                outerFunction();
            }
            catch (InvalidInputException& e) {
                cout << "   Перехвачено на верхнем уровне: " << e.what() << endl;
                cout << "   Перенаправление исключения успешно!" << endl;
            }
        }
        else if (choice == 16) {
            cout << "Выход из программы..." << endl;
        }
        else {
            cout << "Неверный выбор!" << endl;
        }

    } while (choice != 16);

    
    for (int i = 0; i < workersCount; i++) delete workers[i];
    for (int i = 0; i < managersCount; i++) delete managers[i];
    for (int i = 0; i < territoriesCount; i++) delete territories[i];
    for (int i = 0; i < teamsCount; i++) delete teams[i];

    return 0;
}