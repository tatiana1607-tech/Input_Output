#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include <windows.h>


#include "Car.h"
#include "Bicycle.h"
#include "Electric_car.h"
#include "Chek1.h"

using namespace std;


void setRussianLocale() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

void printMenu() {
    cout << "\n=============================================================\n";
    cout << "                         МЕНЮ\n";
    cout << "=============================================================\n";
    cout << "1. Добавить автомобиль\n";
    cout << "2. Добавить велосипед\n";
    cout << "3. Добавить электромобиль\n";
    cout << "4. Показать все транспортные средства\n";
    cout << "5. Проверить просрочку ТО\n";
    cout << "6. Сохранить данные в файл\n";
    cout << "7. Дополнительные функции\n";
    cout << "0. Выход\n";
    cout << "=============================================================\n";
}

void printSubMenu() {
    cout << "\n==================== ДОПОЛНИТЕЛЬНЫЕ ФУНКЦИИ ====================\n";
    cout << "1. Категория автомобиля\n";
    cout << "2. Стоимость поездки автомобиля\n";
    cout << "3. Категория велосипеда\n";
    cout << "4. Проверка подходит ли велосипед по росту\n";
    cout << "5. Стоимость полной зарядки электромобиля\n";
    cout << "6. Время зарядки электромобиля для заданного расстояния\n";
    cout << "0. Назад\n";
    cout << "================================================================\n";
}

void printTableHeader() {
    cout << "\n";
    cout << "==========================================================================================================\n";
    cout << "| " << setw(4) << "ID"
        << " | " << setw(12) << "Тип"
        << " | " << setw(14) << "Модель"
        << " | " << setw(8) << "Пробег"
        << " | " << setw(38) << "Доп. параметры"
        << " | " << setw(12) << "Статус ТО" << " |\n";
    cout << "==========================================================================================================\n";
}


void printTableSeparator() {
    cout << "----------------------------------------------------------------------------------------------------------\n";
}

Vehicle* createCar() {
    int id = getValidInt("Введите ID: ");

    string model;
    cout << "Введите модель: ";
    getline(cin, model);

    int mileage = getValidInt("Введите пробег: ");
    int d = getValidIntInRange("День ТО: ",1,31);
    int m = getValidIntInRange("Месяц ТО: ",1,12);
    int y = getValidIntInRange("Год ТО: ",1990,2026);

    string type;
    cout << "Тип двигателя: ";
    getline(cin, type);

    double volume = getValidPositiveDouble("Объем двигателя: ");
    double cons = getValidPositiveDouble("Расход топлива: ");

    return new Car(id, d, m, y, model, mileage, type, volume, cons);
}

Vehicle* createBicycle() {
    int id = getValidInt("Введите ID: ");

    string model;
    cout << "Введите модель: ";
    getline(cin, model);

    int mileage = getValidInt("Введите пробег: ");
    int d = getValidIntInRange("День ТО: ", 1, 31);
    int m = getValidIntInRange("Месяц ТО: ", 1, 12);
    int y = getValidIntInRange("Год ТО: ", 1990, 2026);

    int speeds = getValidInt("Количество скоростей: ");

    string type;
    cout << "Тип велосипеда: ";
    getline(cin, type);

    string material;
    cout << "Материал рамы: ";
    getline(cin, material);

    string size;
    cout << "Размер рамы (S/M/L/XL): ";
    getline(cin, size);

    return new Bicycle(id, d, m, y, model, mileage, speeds, type, material, size);
}

Vehicle* createElectroCar() {
    int id = getValidInt("Введите ID: ");

    string model;
    cout << "Введите модель: ";
    getline(cin, model);
    int mileage = getValidInt("Введите пробег: ");
    int d = getValidIntInRange("День ТО: ", 1, 31);
    int m = getValidIntInRange("Месяц ТО: ", 1, 12);
    int y = getValidIntInRange("Год ТО: ", 1990, 2026);

    double cap = getValidPositiveDouble("Емкость батареи (кВтч): ");
    int range = getValidInt("Запас хода (км): ");
    double ch = getValidPositiveDouble("Время полной зарядки (часы): ");

    return new ElectroCar(id, d, m, y, model, mileage, cap, range, ch);
}

int main() {
    setRussianLocale();

    Vehicle* vehicles[100];
    int count = 0;
    int choice;

    do {
        printMenu();
        choice = getValidInt("Ваш выбор: ");

        switch (choice) {

        case 1:
            vehicles[count++] = createCar();
            break;

        case 2:
            vehicles[count++] = createBicycle();
            break;

        case 3:
            vehicles[count++] = createElectroCar();
            break;

        case 4: {
            if (count == 0) {
                cout << "Список пуст.\n";
                break;
            }

            printTableHeader();

            for (int i = 0; i < count; i++) {
                vehicles[i]->printInf();
                cout << " | " << setw(12) << "---" << " |\n";
                if (i < count - 1) printTableSeparator();
            }
            cout << "==========================================================================================================\n";
            cout << "Для проверки статуса ТО используйте пункт меню 5\n";
            break;
        }

        case 5: {
            if (count == 0) {
                cout << "Список пуст.\n";
                break;
            }

            int d = getValidInt("Введите текущий день: ");
            int m = getValidInt("Введите текущий месяц: ");
            int y = getValidInt("Введите текущий год: ");

            printTableHeader();

            for (int i = 0; i < count; i++) {
                vehicles[i]->printInf();
                bool overdue = vehicles[i]->isMaintenanceOverdue(d, m, y);
                cout << " | " << setw(12) << (overdue ? "ПРОСРОЧЕНО" : "В норме") << " |\n";
                if (i < count - 1) printTableSeparator();
            }
            cout << "==========================================================================================================\n";
            break;
        }

        case 6: {
            ofstream file("vehicles.txt");
            if (file.is_open()) {
                for (int i = 0; i < count; i++) {
                    vehicles[i]->saveToFile(file);
                }
                file.close();
                cout << "Данные сохранены в файл vehicles.txt\n";
            }
            else {
                cout << "Ошибка открытия файла!\n";
            }
            break;
        }

        case 7: {
            int sub;
            do {
                printSubMenu();
                sub = getValidInt("Ваш выбор: ");

                switch (sub) {

                case 1: { 
                    int id = getValidInt("Введите ID автомобиля: ");
                    for (int i = 0; i < count; i++) {
                        if (vehicles[i]->getType() == "Автомобиль" && vehicles[i]->getID() == id) {
                            Car* c = (Car*)vehicles[i];
                            cout << "Категория автомобиля: " << c->getCategory() << endl;
                        }
                    }
                    break;
                }

                case 2: {
                    int id = getValidInt("Введите ID автомобиля: ");
                    double dist = getValidPositiveDouble("Расстояние (км): ");
                    double price = getValidPositiveDouble("Цена топлива: ");

                    for (int i = 0; i < count; i++) {
                        if (vehicles[i]->getType() == "Автомобиль" && vehicles[i]->getID() == id) {
                            Car* c = (Car*)vehicles[i];
                            cout << "Стоимость поездки: "
                                << fixed << setprecision(2)
                                << c->calculateTripCost(dist, price) << " руб.\n";
                        }
                    }
                    break;
                }

                case 3: { 
                    int id = getValidInt("Введите ID велосипеда: ");
                    for (int i = 0; i < count; i++) {
                        if (vehicles[i]->getType() == "Велосипед" && vehicles[i]->getID() == id) {
                            Bicycle* b = (Bicycle*)vehicles[i];
                            cout << "Категория велосипеда: " << b->getCategory() << endl;
                        }
                    }
                    break;
                }

                case 4: { 
                    int id = getValidInt("Введите ID велосипеда: ");
                    int height = getValidInt("Введите рост (см): ");

                    for (int i = 0; i < count; i++) {
                        if (vehicles[i]->getType() == "Велосипед" && vehicles[i]->getID() == id) {
                            Bicycle* b = (Bicycle*)vehicles[i];
                            if (b->isSuitableForHeight(height))
                                cout << "Подходит по росту\n";
                            else
                                cout << "Не подходит по росту\n";
                        }
                    }
                    break;
                }

                case 5: { 
                    int id = getValidInt("Введите ID электромобиля: ");
                    double price = getValidPositiveDouble("Цена 1 кВтч: ");

                    for (int i = 0; i < count; i++) {
                        if (vehicles[i]->getType() == "Электроавтомобиль" && vehicles[i]->getID() == id) {
                            ElectroCar* e = (ElectroCar*)vehicles[i];
                            cout << "Стоимость полной зарядки: "
                                << fixed << setprecision(2)
                                << e->calculateChargeCost(price) << " руб.\n";
                        }
                    }
                    break;
                }

                case 6: { 
                    int id = getValidInt("Введите ID электромобиля: ");
                    int dist = getValidInt("Введите расстояние (км): ");

                    for (int i = 0; i < count; i++) {
                        if (vehicles[i]->getType() == "Электроавтомобиль" && vehicles[i]->getID() == id) {
                            ElectroCar* e = (ElectroCar*)vehicles[i];
                            float t = e->getChargingTimeForDistance(dist);
                            if (t < 0)
                                cout << "Недостаточно заряда.\n";
                            else
                                cout << "Время зарядки: " << fixed << setprecision(2) << t << " ч.\n";
                        }
                    }
                    break;
                }

                }

            } while (sub != 0);
            break;
        }

        case 0:
            cout << "Выход...\n";
            break;

        default:
            cout << "Неверный выбор!\n";
        }

    } while (choice != 0);

    for (int i = 0; i < count; i++)
        delete vehicles[i];

    return 0;
}