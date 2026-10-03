#include <iostream>
#include <windows.h>
#include "ToyCatalog.h"
#include "SoftToy.h"
#include "Constructor.h"
#include "Electronic.h"
#include "Order.h"

using namespace std;

void seedCatalog(ToyCatalog& catalog) {
    catalog.add(new SoftToy("101", "Мишка ", 33.0, 3, "Плюш", 35.0));
    catalog.add(new SoftToy("102", "Зайчик Пушистик", 19.0, 1, "Ткань", 25.0));
    catalog.add(new Constructor("103", "Лего Сити", 500.0, 6, 700, "City"));
    catalog.add(new Constructor("104", "Магнитный замок", 286.0, 4, 120, "Mag-World"));
    catalog.add(new Electronic("105", "Машинка ", 100.0, 8, "AA x4", true));
    catalog.add(new Electronic("106", "Робот Паук", 50.0, 5, "AAA x3", false));
}

void printMenu() {
    cout << "\n================ МЕНЮ МАГАЗИНА ================\n"
        << "--- КАТАЛОГ ВИТРИНЫ ---\n"
        << "1. Просмотреть каталог товаров\n"
        << "2. Сортировать каталог\n"
        << "3. Поиск товара по названию\n"
        << "--- ЧЕК / КОРЗИНА ---\n"
        << "4. Добавить товар из каталога в чек\n"
        << "5. Посмотреть чек заказа\n"
        << "6. Редактировать количество товара в чеке\n"
        << "7. Удалить товар из чека\n"
        << "8. Очистить весь чек\n"
        << "0. Выход\n"
        << "================================================\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ToyCatalog catalog;
    seedCatalog(catalog);

    Order currentOrder;

    int choice = -1;
    while (choice != 0) {
        printMenu();
        choice = readInt(cin, "Выберите пункт меню: ");

        switch (choice) {
        case 1: {
            catalog.printTable();
            break;
        }
        case 2: {
            cout << "\nПараметры сортировки:\n"
                << "1. По цене (возрастание)\n"
                << "2. По названию (А-Я)\n";
            int sortChoice = readInt(cin, "Ваш выбор: ");
            if (sortChoice == 1) {
                catalog.sortByPrice();
                cout << "Каталог отсортирован по цене.\n";
            }
            else if (sortChoice == 2) {
                catalog.sortByName();
                cout << "Каталог отсортирован по названию.\n";
            }
            else {
                cout << "Неверный вариант сортировки.\n";
            }
            break;
        }
        case 3: {
            cout << "Введите название товара или его часть: ";
            string namePart;
            cin >> ws;
            getline(cin, namePart);
            catalog.printFindByName(namePart);
            break;
        }
        case 4: {
            cout << "Введите артикул товара из каталога: ";
            string art;
            cin >> ws;
            getline(cin, art);

            Toy* toy = catalog.findByArticle(art);
            if (toy) {
                int qty = readInt(cin, "Введите количество для заказа: ");
                currentOrder.addItem(new OrderItem(toy, qty));
            }
            else {
                cout << "Товар с артикулом \"" << art << "\" не найден в каталоге.\n";
            }
            break;
        }
        case 5: {
            currentOrder.printReceipt();
            break;
        }
        case 6: {
            if (currentOrder.getCount() == 0) {
                cout << "Чек пуст!\n";
                break;
            }
            cout << "Введите артикул товара в чеке для изменения количества: ";
            string art;
            cin >> ws;
            getline(cin, art);

            int newQty = readInt(cin, "Введите новое количество (0 для удаления): ");
            if (currentOrder.editQuantityByArticle(art, newQty)) {
                cout << "Количество успешно изменено.\n";
            }
            else {
                cout << "Товар с артикулом \"" << art << "\" не найден в чеке.\n";
            }
            break;
        }
        case 7: {
            if (currentOrder.getCount() == 0) {
                cout << "Чек пуст!\n";
                break;
            }
            cout << "Введите артикул товара для удаления из чека: ";
            string art;
            cin >> ws;
            getline(cin, art);

            if (currentOrder.removeItemByArticle(art)) {
                cout << "Товар удален из чека.\n";
            }
            else {
                cout << "Товар с артикулом \"" << art << "\" не найден в чеке.\n";
            }
            break;
        }
        case 8: {
            currentOrder.clear();
            cout << "Чек полностью очищен.\n";
            break;
        }
        case 0:
            cout << "Завершение работы программы.\n";
            break;
        default:
            cout << "Неверный выбор, повторите попытку.\n";
            break;
        }
    }

    return 0;
}