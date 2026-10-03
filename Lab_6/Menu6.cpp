#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include<cstdlib>
#include <windows.h>
#include "Car.h"
#include "FireTruck.h"
#include "Chek.h"

using namespace std;



string getValueFromLine(const string& line) {
    int colonPos = -1;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ':') {
            colonPos = i;
            break;
        }
    }

    if (colonPos != -1) {
        string value = "";
        for (int i = colonPos + 1; i < line.length(); i++) {
            if (line[i] != ' ' && line[i] != '\t') {
                value += line[i];
            }
            else if (value.length() > 0) {
               
                value += line[i];
            }
        }
        
        while (value.length() > 0 && (value[value.length() - 1] == ' ' || value[value.length() - 1] == '\t')) {
            value = value.substr(0, value.length() - 1);
        }
        return value;
    }
    return "";
}

Car* loadCarFromFile(ifstream& file) {
    int id = 0, day = 1, month = 1, year = 2000, mileage = 0;
    float weight = 1000;
    string model, chassiType, engineType;
    float engineVolume = 0, fuelConsumption = 0;

    string line;
    while (getline(file, line)) {
        if (line == "---") break;

        if (line.length() >= 3 && line.substr(0, 3) == "ID:") {
            id = atoi(getValueFromLine(line).c_str());
        }
        else if (line.length() >= 7 && line.substr(0, 7) == "Модель:") {
            model = getValueFromLine(line);
        }
        else if (line.length() >= 7 && line.substr(0, 7) == "Пробег:") {
            mileage = atoi(getValueFromLine(line).c_str());
        }
        else if (line.length() >= 5 && line.substr(0, 5) == "Вес:") {
            weight = atof(getValueFromLine(line).c_str());
        }
        else if (line.length() >= 11 && line.substr(0, 11) == "Тип шасси:") {
            chassiType = getValueFromLine(line);
        }
        else if (line.length() >= 15 && line.substr(0, 15) == "Тип двигателя:") {
            engineType = getValueFromLine(line);
        }
        else if (line.length() >= 16 && line.substr(0, 16) == "Объем двигателя:") {
            engineVolume = atof(getValueFromLine(line).c_str());
        }
        else if (line.length() >= 16 && line.substr(0, 16) == "Расход топлива:") {
            fuelConsumption = atof(getValueFromLine(line).c_str());
        }
        else if (line.length() >= 9 && line.substr(0, 9) == "Дата ТО:") {
            string dateStr = getValueFromLine(line);
            
            int space1 = -1, space2 = -1;
            for (int i = 0; i < dateStr.length(); i++) {
                if (dateStr[i] == ' ') {
                    if (space1 == -1) space1 = i;
                    else if (space2 == -1) space2 = i;
                }
            }
            if (space1 != -1) {
                string dayStr = dateStr.substr(0, space1);
                if (space2 != -1) {
                    string monthStr = dateStr.substr(space1 + 1, space2 - space1 - 1);
                    string yearStr = dateStr.substr(space2 + 1);
                    day = atoi(dayStr.c_str());
                    month = atoi(monthStr.c_str());
                    year = atoi(yearStr.c_str());
                }
            }
        }
    }
    return new Car(id, day, month, year, model, mileage, weight, chassiType, engineType, engineVolume, fuelConsumption);
}

FireTruck* loadFireTruckFromFile(ifstream& file) {
    int id = 0, day = 1, month = 1, year = 2000, mileage = 0;
    float weight = 1000, waterVolume = 0;
    string model, chassiType, equipment;
    bool hasSiren = false;

    string line;
    while (getline(file, line)) {
        if (line == "---") break;

        if (line.length() >= 3 && line.substr(0, 3) == "ID:") {
            id = atoi(getValueFromLine(line).c_str());
        }
        else if (line.length() >= 7 && line.substr(0, 7) == "Модель:") {
            model = getValueFromLine(line);
        }
        else if (line.length() >= 7 && line.substr(0, 7) == "Пробег:") {
            mileage = atoi(getValueFromLine(line).c_str());
        }
        else if (line.length() >= 5 && line.substr(0, 5) == "Вес:") {
            weight = atof(getValueFromLine(line).c_str());
        }
        else if (line.length() >= 11 && line.substr(0, 11) == "Тип шасси:") {
            chassiType = getValueFromLine(line);
        }
        else if (line.length() >= 8 && line.substr(0, 8) == "Сирена:") {
            string sirenStr = getValueFromLine(line);
            hasSiren = (sirenStr == "есть");
        }
        else if (line.length() >= 13 && line.substr(0, 13) == "Оборудование:") {
            equipment = getValueFromLine(line);
        }
        else if (line.length() >= 17 && line.substr(0, 17) == "Объем цистерны:") {
            waterVolume = atof(getValueFromLine(line).c_str());
        }
        else if (line.length() >= 9 && line.substr(0, 9) == "Дата ТО:") {
            string dateStr = getValueFromLine(line);
           
            int space1 = -1, space2 = -1;
            for (int i = 0; i < dateStr.length(); i++) {
                if (dateStr[i] == ' ') {
                    if (space1 == -1) space1 = i;
                    else if (space2 == -1) space2 = i;
                }
            }
            if (space1 != -1) {
                string dayStr = dateStr.substr(0, space1);
                if (space2 != -1) {
                    string monthStr = dateStr.substr(space1 + 1, space2 - space1 - 1);
                    string yearStr = dateStr.substr(space2 + 1);
                    day = atoi(dayStr.c_str());
                    month = atoi(monthStr.c_str());
                    year = atoi(yearStr.c_str());
                }
            }
        }
    }
    return new FireTruck(id, day, month, year, model, mileage, weight, chassiType, hasSiren, equipment, waterVolume);
}

int loadAllFromFile(Vehicle* vehicles[], int maxCount, const string& filename) {
    ifstream file(filename.c_str());
    if (!file.is_open()) {
        cout << "Файл " << filename << " не найден. Будет создан новый при сохранении.\n";
        return 0;
    }

    int count = 0;
    string line;

    while (getline(file, line) && count < maxCount) {
        if (line == "Car") {
            Car* car = loadCarFromFile(file);
            if (car) vehicles[count++] = car;
        }
        else if (line == "FireTruck") {
            FireTruck* ft = loadFireTruckFromFile(file);
            if (ft) vehicles[count++] = ft;
        }
    }
    file.close();

    if (count > 0) {
        cout << "Загружено " << count << " транспортных средств из файла " << filename << "\n";
    }
    return count;
}


Vehicle* createCar() {
    int id = getValidInt("Введите ID: ");
    cin.ignore();

    string model;
    cout << "Введите модель: ";
    getline(cin, model);

    int mileage = getValidInt("Введите пробег: ");
    int d = getValidIntInRange("День ТО: ", 1, 31);
    int m = getValidIntInRange("Месяц ТО: ", 1, 12);
    int y = getValidIntInRange("Год ТО: ", 1990, 2026);

    float weight = getValidPositiveDouble("Введите вес (кг): ");
    cin.ignore();

    string chassiType;
    cout << "Введите тип шасси: ";
    getline(cin, chassiType);

    string engineType;
    cout << "Тип двигателя: ";
    getline(cin, engineType);

    double volume = getValidPositiveDouble("Объем двигателя (л): ");
    double cons = getValidPositiveDouble("Расход топлива (л/100км): ");

    return new Car(id, d, m, y, model, mileage, weight, chassiType, engineType, volume, cons);
}

Vehicle* createFireTruck() {
    int id = getValidInt("Введите ID: ");
    cin.ignore();

    string model;
    cout << "Введите модель: ";
    getline(cin, model);

    int mileage = getValidInt("Введите пробег: ");
    int d = getValidIntInRange("День ТО: ", 1, 31);
    int m = getValidIntInRange("Месяц ТО: ", 1, 12);
    int y = getValidIntInRange("Год ТО: ", 1990, 2026);

    float weight = getValidPositiveDouble("Введите вес (кг): ");
    cin.ignore();

    string chassiType;
    cout << "Введите тип шасси: ";
    getline(cin, chassiType);

    int sirenChoice;
    cout << "Сирена (1-есть / 0-нет): ";
    cin >> sirenChoice;
    bool hasSiren = (sirenChoice == 1);
    cin.ignore();

    string equipment;
    cout << "Оборудование: ";
    getline(cin, equipment);

    float waterVolume = getValidPositiveDouble("Введите объём цистерны (л): ");

    return new FireTruck(id, d, m, y, model, mileage, weight, chassiType, hasSiren, equipment, waterVolume);
}



void printMenu() {
    cout << "\n=============================================================\n";
    cout << "                         МЕНЮ\n";
    cout << "=============================================================\n";
    cout << "1. Добавить автомобиль\n";
    cout << "2. Добавить пожарную машину\n";
    cout << "3. Показать все транспортные средства\n";
    cout << "4. Проверить просрочку ТО\n";
    cout << "5. Сохранить данные в файл\n";
    cout << "6. Загрузить данные из файла\n";
    cout << "0. Выход\n";
    cout << "=============================================================\n";
}

void printTableHeader() {
    cout << "\n";
    cout << "==================================================================================================================\n";
    cout << "| " << setw(4) << "ID"
        << " | " << setw(14) << "Тип"
        << " | " << setw(14) << "Модель"
        << " | " << setw(8) << "Пробег"
        << " | " << setw(65) << "Доп. параметры"
        << " | " << setw(12) << "Статус ТО" << " |\n";
    cout << "==================================================================================================================\n";
}



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Vehicle* vehicles[100];
    int count = 0;
    int choice;

    
    count = loadAllFromFile(vehicles, 100, "vehicle2.txt");

    do {
        printMenu();
        choice = getValidIntInRange("Ваш выбор: ", 0, 6);

        switch (choice) {
        case 1:
            if (count < 100) {
                vehicles[count++] = createCar();
                cout << "Автомобиль успешно добавлен!\n";
            }
            else {
                cout << "Достигнут максимум (100)!\n";
            }
            break;

        case 2:
            if (count < 100) {
                vehicles[count++] = createFireTruck();
                cout << "Пожарная машина успешно добавлена!\n";
            }
            else {
                cout << "Достигнут максимум (100)!\n";
            }
            break;

        case 3:
            if (count == 0) {
                cout << "Список пуст.\n";
                break;
            }
            printTableHeader();
            for (int i = 0; i < count; i++) {
                vehicles[i]->printInf();
                cout << " | " << setw(12) << "---" << " |\n";
                if (i < count - 1)
                    cout << "------------------------------------------------------------------------------------------------------------------\n";
            }
            cout << "==================================================================================================================\n";
            break;

        case 4:
            if (count == 0) {
                cout << "Список пуст.\n";
                break;
            }
            {
                int d = getValidIntInRange("Введите текущий день: ", 1, 31);
                int m = getValidIntInRange("Введите текущий месяц: ", 1, 12);
                int y = getValidIntInRange("Введите текущий год: ", 2000, 2030);

                printTableHeader();
                for (int i = 0; i < count; i++) {
                    vehicles[i]->printInf();
                    bool overdue = vehicles[i]->isMaintenanceOverdue(d, m, y);
                    cout << " | " << setw(12) << (overdue ? "ПРОСРОЧЕНО" : "В норме") << " |\n";
                    if (i < count - 1)
                        cout << "------------------------------------------------------------------------------------------------------------------\n";
                }
                cout << "==================================================================================================================\n";
            }
            break;

        case 5: {
            ofstream file("vehicle2.txt");
            if (file.is_open()) {
                for (int i = 0; i < count; i++) {
                    vehicles[i]->saveToFile(file);
                }
                file.close();
                cout << "Данные сохранены в файл vehicle2.txt\n";
            }
            else {
                cout << "Ошибка открытия файла!\n";
            }
            break;
        }

        case 6: {
            cout << "Внимание! Загрузка из файла перезапишет текущие данные.\n";
            int confirm = getValidIntInRange("Продолжить? (1-Да / 0-Нет): ", 0, 1);
            if (confirm == 1) {
                for (int i = 0; i < count; i++) {
                    delete vehicles[i];
                }
                count = loadAllFromFile(vehicles, 100, "vehicle2.txt");
            }
            break;
        }

        case 0:
            cout << "Выход\n";
            break;
        }
    } while (choice != 0);

    for (int i = 0; i < count; i++)
        delete vehicles[i];

    return 0;
}