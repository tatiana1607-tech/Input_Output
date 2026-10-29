#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <windows.h>

#include "Developer.h"
#include "MobileApp.h"
#include "UtilityApp.h"
#include "EnterpriseApp.h"

using namespace std;

void printCompactAppsTable(const map<string, MobileApp*>& appMap, ostream& os) {
    os << "+" << string(22, '-') << "+" << string(9, '-') << "+" << string(14, '-')
        << "+" << string(20, '-') << "+" << string(15, '-') << "+\n";
    os << "| " << left << setw(20) << "Название"
        << " | " << setw(7) << "Рейтинг"
        << " | " << setw(12) << "Цена"
        << " | " << setw(18) << "Разработчик"
        << " | " << setw(13) << "Тип (B2C/B2B)" << " |\n";
    os << "+" << string(22, '-') << "+" << string(9, '-') << "+" << string(14, '-')
        << "+" << string(20, '-') << "+" << string(15, '-') << "+\n";

    for (map<string, MobileApp*>::const_iterator it = appMap.begin(); it != appMap.end(); ++it) {
        if (it->second) {
            string typeStr = dynamic_cast<UtilityApp*>(it->second) ? "B2C (Утилита)" : "B2B (Корпор.)";
            os << "| " << left << setw(20) << it->second->getName()
                << " | " << right << setw(7) << fixed << setprecision(1) << it->second->getRating()
                << " | " << setw(12) << fixed << setprecision(2) << it->second->getPrice()
                << " | " << left << setw(18) << (it->second->getLeadDeveloper() ? it->second->getLeadDeveloper()->getFullName() : "Нет")
                << " | " << setw(13) << typeStr << " |\n";
        }
    }
    os << "+" << string(22, '-') << "+" << string(9, '-') << "+" << string(14, '-')
        << "+" << string(20, '-') << "+" << string(15, '-') << "+\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    map<string, MobileApp*> appMap;
    set<string> targetPlatforms;
    multiset<double> ratingMultiset;
    unordered_multimap<string, MobileApp*> devAppsMultiMap;

    list<Developer> staffList;
    staffList.push_back(Developer("Иванов Иван", "TeamLead iOS", 7));
    staffList.push_back(Developer("Петров Петр", "Senior Android Dev", 5));
    staffList.push_back(Developer("Сидорова Анна", "Middle Flutter Dev", 3));

    Developer* dev1 = &(*staffList.begin());
    Developer* dev2 = &(*(next(staffList.begin(), 1)));
    Developer* dev3 = &(*(next(staffList.begin(), 2)));

    UtilityApp* app1 = new UtilityApp("Fitness Tracker", 4.8, 0.0, dev1, true, "Android 11+");
    app1->addVersion(Version("1.0.0", "10.01.2026", 45.2));

    EnterpriseApp* app2 = new EnterpriseApp("SberBank Mobile", 4.9, 1500000.0, dev2, "ПАО Сбербанк", "ГОСТ-34.12");
    app2->addVersion(Version("2.4.0", "12.08.2026", 120.5));

    UtilityApp* app3 = new UtilityApp("Photo Editor Pro", 4.2, 299.0, dev1, false, "Android 9+");
    app3->addVersion(Version("1.2.0", "15.03.2026", 85.0));

    UtilityApp* app4 = new UtilityApp("Weather Forecast", 4.8, 0.0, dev3, false, "Android 8+");

    appMap[app1->getName()] = app1;
    appMap[app2->getName()] = app2;
    appMap[app3->getName()] = app3;
    appMap[app4->getName()] = app4;

    targetPlatforms.insert("Android");
    targetPlatforms.insert("iOS");
    targetPlatforms.insert("HarmonyOS");
    targetPlatforms.insert("Web App");

    ratingMultiset.insert(app1->getRating());
    ratingMultiset.insert(app2->getRating());
    ratingMultiset.insert(app3->getRating());
    ratingMultiset.insert(app4->getRating());

    devAppsMultiMap.insert(make_pair(dev1->getFullName(), app1));
    devAppsMultiMap.insert(make_pair(dev1->getFullName(), app3));
    devAppsMultiMap.insert(make_pair(dev2->getFullName(), app2));
    devAppsMultiMap.insert(make_pair(dev3->getFullName(), app4));

    int mainMenuChoice = -1;
    do {
        cout << "\n===================================================\n";
        cout << "                 ГЛАВНОЕ МЕНЮ  \n";
        cout << "===================================================\n";
        cout << " 1.Работа с map \n";
        cout << " 2.Работа с set \n";
        cout << " 3.Работа с multiset \n";
        cout << " 4.Работа с unordered_multimap \n";
        cout << " 0. Выход\n";
        cout << "---------------------------------------------------\n";
        cout << "Выберите контейнер для работы: ";
        cin >> mainMenuChoice;

        switch (mainMenuChoice) {
        case 1: {
            int subChoice = -1;
            do {
                cout << "\n----------------------------------------\n";
                cout << "       Работа с приложениями      \n";
                cout << "----------------------------------------\n";
                cout << " 1. Посмотреть компактный список\n";
                cout << " 2. Посмотреть полную информацию о конкретном приложении\n";
                cout << " 3. Добавить приложение\n";
                cout << " 4. Найти приложение по имени (find)\n";
                cout << " 5. Удалить приложение из map\n";
                cout << " 6. Сохранить каталог в файл\n";
                cout << " 0. Назад в главное меню\n";
                cout << "Выберите пункт: ";
                cin >> subChoice;

                switch (subChoice) {
                case 1: {
                    
                    printCompactAppsTable(appMap, cout);
                    break;
                }
                case 2: {
                    string name;
                    cout << "Введите название приложения для просмотра деталей: ";
                    cin.clear();
                    cin.ignore(32767, '\n');
                    getline(cin, name);

                    map<string, MobileApp*>::const_iterator it = appMap.find(name);
                    if (it != appMap.end() && it->second) {
                        cout << "\n--- ДЕТАЛЬНАЯ ИНФОРМАЦИЯ ---\n";
                        it->second->printTableRow(cout);
                    }
                    else {
                        cout << "Приложение не найдено.\n";
                    }
                    break;
                }
                case 3: {
                    string name; double rating, price;
                    cout << "Название приложения: ";
                    cin.ignore(); getline(cin, name);
                    cout << "Рейтинг: "; cin >> rating;
                    cout << "Цена: "; cin >> price;

                    UtilityApp* newApp = new UtilityApp(name, rating, price, dev1, false, "Android 10+");
                    appMap[name] = newApp;
                    ratingMultiset.insert(rating);
                    devAppsMultiMap.insert(make_pair(dev1->getFullName(), newApp));

                    cout << "Приложение добавлено в map!\n";
                    break;
                }
                case 4: {
                    string name;
                    cout << "Введите название приложения: "; cin.ignore(); getline(cin, name);
                    map<string, MobileApp*>::const_iterator it = appMap.find(name);
                    if (it != appMap.end()) {
                        cout << "Найдено в map:\n";
                        it->second->printTableRow(cout);
                    }
                    else {
                        cout << "Приложение с таким именем не найдено.\n";
                    }
                    break;
                }
                case 5: {
                    string name;
                    cout << "Введите название приложения для удаления из map: "; cin.ignore(); getline(cin, name);
                    map<string, MobileApp*>::iterator it = appMap.find(name);
                    if (it != appMap.end()) {
                        delete it->second;
                        appMap.erase(it);
                        cout << "Успешно удалено из map.\n";
                    }
                    else {
                        cout << "Элемент не найден.\n";
                    }
                    break;
                }
                case 6: {
                    ofstream outFile("map_report.txt");
                    outFile << "=== КАТАЛОГ ПРИЛОЖЕНИЙ ===\n\n";
                    printCompactAppsTable(appMap, outFile);
                    outFile.close();
                    cout << "Отчет сохранен в файл map_report.txt\n";
                    break;
                }
                case 0: break;
                default: cout << "Неверный выбор.\n";
                }
            } while (subChoice != 0);
            break;
        }
        case 2: {
            int subChoice = -1;
            do {
                cout << "\n----------------------------------------\n";
                cout << "       Работа с платформами    \n";
                cout << "----------------------------------------\n";
                cout << " 1. Посмотреть все платформы\n";
                cout << " 2. Добавить платформу\n";
                cout << " 3. Проверить наличие платформы \n";
                cout << " 4. Удалить платформу\n";
                cout << " 0. Назад в главное меню\n";
                cout << "Выберите пункт: ";
                cin >> subChoice;

                switch (subChoice) {
                case 1: {
                    cout << "\nУникальные отсортированные платформы:\n";
                    for (set<string>::const_iterator it = targetPlatforms.begin(); it != targetPlatforms.end(); ++it) {
                        cout << " - " << *it << "\n";
                    }
                    break;
                }
                case 2: {
                    string name;
                    cout << "Название новой платформы: "; cin.ignore(); getline(cin, name);
                    targetPlatforms.insert(name);
                    cout << "Добавлено в set.\n";
                    break;
                }
                case 3: {
                    string name;
                    cout << "Введите название платформы для проверки: "; cin.ignore(); getline(cin, name);
                    if (targetPlatforms.count(name) > 0) {
                        cout << "Платформа '" << name << "' присутствует в множестве.\n";
                    }
                    else {
                        cout << "Платформа не найдена.\n";
                    }
                    break;
                }
                case 4: {
                    string name;
                    cout << "Название платформы для удаления: "; cin.ignore(); getline(cin, name);
                    if (targetPlatforms.erase(name) > 0) cout << "Удалено из set.\n";
                    else cout << "Элемент не найден.\n";
                    break;
                }
                case 0: break;
                default: cout << "Неверный выбор.\n";
                }
            } while (subChoice != 0);
            break;
        }
        case 3: {
            int subChoice = -1;
            do {
                cout << "\n----------------------------------------\n";
                cout << "       Работа с рейтингами    \n";
                cout << "----------------------------------------\n";
                cout << " 1. Посмотреть отсортированные рейтинги\n";
                cout << " 2. Посчитать количество одинаковых рейтингов (count)\n";
                cout << " 0. Назад в главное меню\n";
                cout << "Выберите пункт: ";
                cin >> subChoice;

                switch (subChoice) {
                case 1: {
                    cout << "\nСписок всех рейтингов (отсортирован, с повторами):\n";
                    for (multiset<double>::const_iterator it = ratingMultiset.begin(); it != ratingMultiset.end(); ++it) {
                        cout << fixed << setprecision(1) << *it << "  ";
                    }
                    cout << "\n";
                    break;
                }
                
                case 2: {
                    double val;
                    cout << "Введите рейтинг для подсчета: "; cin >> val;
                    size_t cnt = ratingMultiset.count(val);
                    cout << "Количество приложений с рейтингом " << val << ": " << cnt << "\n";
                    break;
                }
                case 0: break;
                default: cout << "Неверный выбор.\n";
                }
            } while (subChoice != 0);
            break;
        }
        case 4: {
            int subChoice = -1;
            do {
                cout << "\n----------------------------------------\n";
                cout << "      Работа с разработчиками \n";
                cout << "----------------------------------------\n";
                cout << " 1. Посмотреть всю хеш-карту\n";
                cout << " 2. Найти все приложения разработчика \n";
                cout << " 0. Назад в главное меню\n";
                cout << "Выберите пункт: ";
                cin >> subChoice;

                switch (subChoice) {
                case 1: {
                    
                    for (unordered_multimap<string, MobileApp*>::const_iterator it = devAppsMultiMap.begin(); it != devAppsMultiMap.end(); ++it) {
                        cout << "Разработчик:"<< it->first<<"|";
                        if (it->second) cout << it->second->getName() << " (Рейтинг: " << it->second->getRating() << ")\n";
                        else cout << "nullptr\n";
                    }
                    break;
                }
                case 2: {
                    string devName;
                    cout << "Введите ФИО разработчика: "; cin.ignore(); getline(cin, devName);

                    pair<unordered_multimap<string, MobileApp*>::const_iterator, unordered_multimap<string, MobileApp*>::const_iterator> range = devAppsMultiMap.equal_range(devName);

                    cout << "\nРезультаты поиска для разработчика '" << devName << "':\n";
                    bool found = false;
                    for (unordered_multimap<string, MobileApp*>::const_iterator it = range.first; it != range.second; ++it) {
                        if (it->second) {
                            it->second->printTableRow(cout);
                            found = true;
                        }
                    }
                    if (!found) cout << "Приложений для данного разработчика не найдено.\n";
                    break;
                }
                case 0: break;
                default: cout << "Неверный выбор.\n";
                }
            } while (subChoice != 0);
            break;
        }
        case 0:
            cout << "Выход из программы...\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (mainMenuChoice != 0);

    for (map<string, MobileApp*>::iterator it = appMap.begin(); it != appMap.end(); ++it) {
        delete it->second;
    }

    return 0;
}