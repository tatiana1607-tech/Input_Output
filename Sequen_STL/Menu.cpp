#include <iostream>
#include <vector>
#include <list>
#include <array>
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

void printAppsTable(const vector<MobileApp*>& apps, ostream& os) {
    os << "+" << string(22, '-') << "+" << string(9, '-') << "+" << string(18, '-')
        << "+" << string(22, '-') << "+" << string(10, '-') << "+" << string(45, '-') << "+\n";
    os << "| " << left << setw(20) << "Название"
        << " | " << setw(7) << "Рейтинг"
        << " | " << setw(16) << "Цена"
        << " | " << setw(20) << "Ведущий разраб."
        << " | " << setw(8) << "Версия"
        << " | " << setw(43) << "Специфика (B2C/B2B)" << " |\n";
    os << "+" << string(22, '-') << "+" << string(9, '-') << "+" << string(18, '-')
        << "+" << string(22, '-') << "+" << string(10, '-') << "+" << string(45, '-') << "+\n";
    for (size_t i = 0; i < apps.size(); ++i) {
        apps[i]->printTableRow(os);
    }
    os << "+" << string(22, '-') << "+" << string(9, '-') << "+" << string(18, '-')
        << "+" << string(22, '-') << "+" << string(10, '-') << "+" << string(45, '-') << "+\n";
}

void printDevsTable(const list<Developer>& devs, ostream& os) {
    os << "+" << string(27, '-') << "+" << string(22, '-') << "+" << string(14, '-') << "+\n";
    os << "| " << left << setw(25) << "ФИО Разработчика"
        << " | " << setw(20) << "Должность"
        << " | " << setw(12) << "Стаж (лет)" << " |\n";
    os << "+" << string(27, '-') << "+" << string(22, '-') << "+" << string(14, '-') << "+\n";
    for (std::list<Developer>::const_iterator it = devs.begin(); it != devs.end(); ++it) {
        it->printTableRow(os);
    }
    os << "+" << string(27, '-') << "+" << string(22, '-') << "+" << string(14, '-') << "+\n";
}

void printPlatformsTable(const array<string, 4>& platforms, ostream& os) {
    os << "+" << string(8, '-') << "+" << string(35, '-') << "+\n";
    os << "| " << left << setw(6) << "Индекс"
        << " | " << setw(33) << "Платформа" << " |\n";
    os << "+" << string(8, '-') << "+" << string(35, '-') << "+\n";
    for (size_t i = 0; i < platforms.size(); ++i) {
        os << "| " << right << setw(6) << i
            << " | " << left << setw(33) << platforms[i] << " |\n";
    }
    os << "+" << string(8, '-') << "+" << string(35, '-') << "+\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<MobileApp*> appCatalog;
    list<Developer> staffList;
    array<string, 4> targetPlatforms = { "Android (Google Play)", "iOS (App Store)", "HarmonyOS", "Web App" };

    staffList.push_back(Developer("Иванов Иван", "TeamLead iOS", 7));
    staffList.push_back(Developer("Петров Петр", "Senior Android Dev", 5));
    staffList.push_back(Developer("Сидорова Анна", "Middle Flutter Dev", 3));

    Developer* dev1 = &(*staffList.begin());
    Developer* dev2 = &(*(next(staffList.begin(), 1)));
    Developer* dev3 = &(*(next(staffList.begin(), 2)));

    UtilityApp* app1 = new UtilityApp("Fitness Tracker", 4.8, 0.0, dev1, true, "Android 11+");
    app1->addVersion(Version("1.0.0", "10.01.2026", 45.2));
    app1->addVersion(Version("1.1.0", "15.05.2026", 48.0));

    EnterpriseApp* app2 = new EnterpriseApp("SberBank Mobile", 4.9, 1500000.0, dev2, "ПАО Сбербанк", "ГОСТ-34.12");
    app2->addVersion(Version("2.4.0", "12.08.2026", 120.5));
    app2->addVersion(Version("2.5.1", "01.10.2026", 125.0));

    UtilityApp* app3 = new UtilityApp("Photo Editor Pro", 4.2, 299.0, dev1, false, "Android 9+");
    app3->addVersion(Version("1.2.0", "15.03.2026", 85.0));
    app3->addVersion(Version("1.3.0", "20.08.2026", 90.5));

    UtilityApp* app4 = new UtilityApp("Weather Forecast", 2.9, 0.0, dev3, false, "Android 8+");
    app4->addVersion(Version("0.9.1", "01.02.2026", 15.4));

    EnterpriseApp* app5 = new EnterpriseApp("ERP Logistics", 4.6, 500000.0, dev1, "ООО Логистик", "AES-256");
    app5->addVersion(Version("3.0.1", "20.07.2026", 210.0));
    app5->addVersion(Version("3.1.0", "10.09.2026", 215.4));

    UtilityApp* app6 = new UtilityApp("Pixel Game", 3.5, 99.0, dev3, false, "Android 10+");
    app6->addVersion(Version("1.0.1", "05.04.2026", 150.0));

    appCatalog.push_back(app1);
    appCatalog.push_back(app2);
    appCatalog.push_back(app3);
    appCatalog.push_back(app4);
    appCatalog.push_back(app5);
    appCatalog.push_back(app6);

    int mainMenuChoice = -1;
    do {
        cout << "\n========================================\n";
        cout << "             ГЛАВНОЕ МЕНЮ               \n";
        cout << "========================================\n";
        cout << " 1. Работа с вектором (Приложения)\n";
        cout << " 2. Работа со списком (Сотрудники)\n";
        cout << " 3. Работа с массивом (Платформы)\n";
        cout << " 0. Выход\n";
        cout << "----------------------------------------\n";
        cout << "Выберите пункт: ";
        cin >> mainMenuChoice;

        switch (mainMenuChoice) {
        case 1: {
            int subChoice = -1;
            do {
                cout << "\n----------------------------------------\n";
                cout << "       ПОДМЕНЮ: РАБОТА С ВЕКТОРОМ       \n";
                cout << "----------------------------------------\n";
                cout << " 1. Посмотреть список приложений\n";
                cout << " 2. Добавить приложение\n";
                cout << " 3. Удалить приложение\n";
                cout << " 4. Редактировать приложение\n";
                cout << " 5. Найти приложение\n";
                cout << " 6. Отсортировать приложения по рейтингу\n";
                cout << " 0. Назад в главное меню\n";
                cout << "Выберите пункт: ";
                cin >> subChoice;

                switch (subChoice) {
                case 1: {
                    cout << "\nСписок приложений:\n";
                    printAppsTable(appCatalog, cout);
                    ofstream f("apps_report.txt");
                    printAppsTable(appCatalog, f);
                    f.close();
                    break;
                }
                case 2: {
                    string name; double rating, price;
                    int appType;
                    cout << "Выберите тип приложения (1 - Утилита [B2C], 2 - Корпоративное [B2B]): ";
                    cin >> appType;

                    cout << "Название: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Рейтинг: "; cin >> rating;
                    cout << "Цена: "; cin >> price;

                    if (appType == 1) {
                        bool sub;
                        string osVer;
                        cout << "Требуется подписка (1 - Да, 0 - Нет): "; cin >> sub;
                        cout << "Целевая версия ОС (например, Android 11+): "; cin.ignore(); getline(cin, osVer);

                        UtilityApp* uApp = new UtilityApp(name, rating, price, dev1, sub, osVer);
                        uApp->addVersion(Version("1.0.0", "01.01.2026", 50.0));
                        appCatalog.push_back(uApp);
                    }
                    else if (appType == 2) {
                        string client, sec;
                        cout << "Компания-заказчик: "; cin.ignore(); getline(cin, client);
                        cout << "Протокол безопасности (например, ГОСТ-34.12): "; getline(cin, sec);

                        EnterpriseApp* eApp = new EnterpriseApp(name, rating, price, dev1, client, sec);
                        eApp->addVersion(Version("1.0.0", "01.01.2026", 100.0));
                        appCatalog.push_back(eApp);
                    }
                    else {
                        cout << "Неверный тип. По умолчанию создана утилита.\n";
                        UtilityApp* uApp = new UtilityApp(name, rating, price, dev1, false, "Android 10+");
                        uApp->addVersion(Version("1.0.0", "01.01.2026", 50.0));
                        appCatalog.push_back(uApp);
                    }

                    cout << "Приложение успешно добавлено в каталог.\n";
                    break;
                }
                case 3: {
                    int idx;
                    cout << "Введите индекс для удаления (0 - " << appCatalog.size() - 1 << "): ";
                    cin >> idx;
                    if (idx >= 0 && idx < (int)appCatalog.size()) {
                        delete appCatalog[idx];
                        appCatalog.erase(appCatalog.begin() + idx);
                        cout << "Приложение удалено.\n";
                    }
                    else {
                        cout << "Неверный индекс.\n";
                    }
                    break;
                }
                case 4: {
                    int idx;
                    cout << "Введите индекс для редактирования (0 - " << appCatalog.size() - 1 << "): ";
                    cin >> idx;
                    if (idx >= 0 && idx < (int)appCatalog.size()) {
                        string newName; double newRating;
                        cout << "Новое название: "; cin >> newName;
                        cout << "Новый рейтинг: "; cin >> newRating;
                        appCatalog[idx]->setName(newName);
                        appCatalog[idx]->setRating(newRating);
                        cout << "Данные обновлены.\n";
                    }
                    else {
                        cout << "Неверный индекс.\n";
                    }
                    break;
                }
                case 5: {
                    string query;
                    cout << "Введите название для поиска: "; cin >> query;
                    bool found = false;
                    for (size_t i = 0; i < appCatalog.size(); ++i) {
                        if (appCatalog[i]->getName() == query) {
                            appCatalog[i]->printTableRow(cout);
                            found = true;
                        }
                    }
                    if (!found) cout << "Ничего не найдено.\n";
                    break;
                }
                case 6: {
                    sort(appCatalog.begin(), appCatalog.end(), [](MobileApp* a, MobileApp* b) {
                        return a->getRating() > b->getRating();
                        });
                    cout << "Приложения отсортированы по рейтингу (от высшего к низшему).\n";
                    printAppsTable(appCatalog, cout);
                    break;
                }
                case 0:
                    break;
                default:
                    cout << "Неверный выбор.\n";
                }
            } while (subChoice != 0);
            break;
        }
        case 2: {
            int subChoice = -1;
            do {
                cout << "\n----------------------------------------\n";
                cout << "       ПОДМЕНЮ: РАБОТА СО СПИСКОМ       \n";
                cout << "----------------------------------------\n";
                cout << " 1. Посмотреть список сотрудников\n";
                cout << " 2. Добавить сотрудника\n";
                cout << " 3. Удалить сотрудника\n";
                cout << " 4. Редактировать сотрудника\n";
                cout << " 5. Найти сотрудника\n";
                cout << " 6. Отсортировать сотрудников по стажу\n";
                cout << " 0. Назад в главное меню\n";
                cout << "Выберите пункт: ";
                cin >> subChoice;

                switch (subChoice) {
                case 1: {
                    cout << "\nСписок сотрудников:\n";
                    printDevsTable(staffList, cout);
                    ofstream f("devs_report.txt");
                    printDevsTable(staffList, f);
                    f.close();
                    break;
                }
                case 2: {
                    string name, pos; int exp;
                    cout << "ФИО: "; cin.ignore(); getline(cin, name);
                    cout << "Должность: "; getline(cin, pos);
                    cout << "Стаж (лет): "; cin >> exp;
                    staffList.push_back(Developer(name, pos, exp));
                    cout << "Сотрудник добавлен.\n";
                    break;
                }
                case 3: {
                    if (!staffList.empty()) {
                        staffList.pop_front();
                        cout << "Первый сотрудник удален.\n";
                    }
                    else {
                        cout << "Список пуст.\n";
                    }
                    break;
                }
                case 4: {
                    int n;
                    cout << "Введите номер сотрудника (1 - " << staffList.size() << "): ";
                    cin >> n;
                    if (n >= 1 && n <= (int)staffList.size()) {
                        std::list<Developer>::iterator it = staffList.begin();
                        advance(it, n - 1);
                        string newPos; int newExp;
                        cout << "Новая должность: "; cin.ignore(); getline(cin, newPos);
                        cout << "Новый стаж: "; cin >> newExp;
                        it->setPosition(newPos);
                        it->setExperience(newExp);
                        cout << "Данные сотрудника обновлены.\n";
                    }
                    else {
                        cout << "Неверный номер.\n";
                    }
                    break;
                }
                case 5: {
                    string qName;
                    cout << "Введите ФИО для поиска: "; cin.ignore(); getline(cin, qName);
                    bool found = false;
                    for (std::list<Developer>::const_iterator it = staffList.begin(); it != staffList.end(); ++it) {
                        if (it->getFullName() == qName) {
                            it->printTableRow(cout);
                            found = true;
                        }
                    }
                    if (!found) cout << "Сотрудник не найден.\n";
                    break;
                }
                case 6: {
                    staffList.sort();
                    cout << "Сотрудники отсортированы по стажу.\n";
                    printDevsTable(staffList, cout);
                    break;
                }
                case 0:
                    break;
                default:
                    cout << "Неверный выбор.\n";
                }
            } while (subChoice != 0);
            break;
        }
        case 3: {
            int subChoice = -1;
            do {
                cout << "\n----------------------------------------\n";
                cout << "       ПОДМЕНЮ: РАБОТА С МАССИВОМ       \n";
                cout << "----------------------------------------\n";
                cout << " 1. Посмотреть список платформ\n";
                cout << " 2. Редактировать платформу\n";
                cout << " 3. Отсортировать платформы\n";
                cout << " 0. Назад в главное меню\n";
                cout << "Выберите пункт: ";
                cin >> subChoice;

                switch (subChoice) {
                case 1: {
                    cout << "\nСписок платформ:\n";
                    printPlatformsTable(targetPlatforms, cout);
                    ofstream f("platforms_report.txt");
                    printPlatformsTable(targetPlatforms, f);
                    f.close();
                    break;
                }
                case 2: {
                    int idx; string val;
                    cout << "Введите индекс (0 - 3): "; cin >> idx;
                    if (idx >= 0 && idx < 4) {
                        cout << "Новое название платформы: "; cin.ignore(); getline(cin, val);
                        targetPlatforms[idx] = val;
                        cout << "Платформа изменена.\n";
                    }
                    else {
                        cout << "Неверный индекс.\n";
                    }
                    break;
                }
                case 3: {
                    sort(targetPlatforms.begin(), targetPlatforms.end());
                    cout << "Платформы отсортированы по алфавиту.\n";
                    printPlatformsTable(targetPlatforms, cout);
                    break;
                }
                case 0:
                    break;
                default:
                    cout << "Неверный выбор.\n";
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

    for (size_t i = 0; i < appCatalog.size(); ++i) {
        delete appCatalog[i];
    }

    return 0;
}