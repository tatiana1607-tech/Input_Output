#include <iostream>
#include <windows.h>
#include "ToyCatalog.h"
#include "SoftToy.h"
#include "Electronic.h"
#include "Constructor.h"
#include "Order.h"

using namespace std;

const string FILE_NAME = "catalog_data.txt";

void printMenu() {
    cout << "\n================ МЕНЮ ================\n"
        << "1. Просмотреть каталог товаров\n"
        << "2. Добавить новый товар\n"
        << "3. Редактировать товар по артикулу\n"
        << "4. Удалить товар по артикулу\n"
        << "5. Поиск товара по названию\n"
        << "6. Добавить товар в чек заказа\n"
        << "7. Посмотреть текущий чек\n"
        << "0. Выход\n"
        << "======================================\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ToyCatalog catalog(FILE_NAME);
    Order currentOrder;

    int choice = -1;
    while (choice != 0) {
        printMenu();
        choice = readInt(cin, "Выберите пункт меню: ");

        switch (choice) {
        case 1:
            catalog.printTable();
            break;

        case 2: {
            cout << "\nВыберите тип игрушки:\n1. Мягкая\n2. Электронная\n3. Конструктор\nВыбор: ";
            int type = readInt(cin, "");

            Toy* newToy = nullptr;
            if (type == 1) newToy = new SoftToy();
            else if (type == 2) newToy = new Electronic();
            else if (type == 3) newToy = new Constructor();

            if (newToy) {
                cin >> *newToy;
                catalog.add(*newToy);
                delete newToy;
            }
            else {
                cout << "Неверный тип товара.\n";
            }
            break;
        }

        case 3: {
            cout << "Введите артикул для редактирования: ";
            string art;
            cin >> ws; getline(cin, art);
            if (!catalog.editByArticle(art)) {
                cout << "Товар с таким артикулом не найден.\n";
            }
            else {
                cout << "Данные товара успешно обновлены!\n";
            }
            break;
        }

        case 4: {
            cout << "Введите артикул для удаления: ";
            string art;
            cin >> ws; getline(cin, art);
            if (catalog.removeByArticle(art)) {
                cout << "Товар успешно удален из файла.\n";
            }
            else {
                cout << "Товар не найден.\n";
            }
            break;
        }

        case 5: {
            cout << "Введите название товара: ";
            string namePart;
            cin >> ws; getline(cin, namePart);
            catalog.printFindByName(namePart);
            break;
        }

        case 6: {
            cout << "Введите артикул товара: ";
            string art;
            cin >> ws; getline(cin, art);

            Toy* toy = catalog.findByArticle(art);
            if (toy) {
                int qty = readInt(cin, "Введите количество: ");
                currentOrder.addItem(new OrderItem(toy, qty));
                cout << "Товар добавлен в чек!\n";
            }
            else {
                cout << "Товар с таким артикулом не найден.\n";
            }
            break;
        }

        case 7:
            currentOrder.printReceipt();
            break;

        case 0:
            cout << "Завершение работы.\n";
            break;

        default:
            cout << "Неверный пункт меню.\n";
            break;
        }
    }

    return 0;
}