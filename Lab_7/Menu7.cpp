#include <iostream>
#include <string>
#include <windows.h>
#include "Phone.h"
#include "Customer.h"
#include "Buy.h"
#include "Sale.h"
#include "Catalog.h"

using namespace std;


void showMenu() {
    cout << "\n==========================================" << endl;
    cout << "|     КАТАЛОГ МОБИЛЬНЫХ ТЕЛЕФОНОВ        |" << endl;
    cout << "==========================================" << endl;
    cout << "| 1. Добавить покупку (для клиента)      |" << endl;
    cout << "| 2. Добавить продажу (для менеджера)    |" << endl;
    cout << "| 3. Показать все покупки                |" << endl;
    cout << "| 4. Показать все продажи                |" << endl;
    cout << "| 5. Показать общую сумму покупок        |" << endl;
    cout << "| 6. Показать общую сумму продаж         |" << endl;
    cout << "| 7. Сохранить отчет покупок в файл      |" << endl;
    cout << "| 8. Сохранить отчет продаж в файл       |" << endl;
    cout << "| 9. Очистить каталог покупок            |" << endl;
    cout << "| 10. Очистить каталог продаж            |" << endl;
    cout << "| 0. Выход                               |" << endl;
    cout << "==========================================" << endl;
    cout << "Выберите пункт: ";
}


Buy inputBuy() {
    string customerName, customerPhone, phoneModel, date;
    double price;
    int quantity;

    cout << "\n=== ВВОД ДАННЫХ О ПОКУПКЕ ===" << endl;

    cout << "Введите имя клиента: ";
    cin.ignore();
    getline(cin, customerName);

    cout << "Введите телефон клиента: ";
    getline(cin, customerPhone);

    cout << "Введите модель телефона: ";
    getline(cin, phoneModel);

    cout << "Введите цену телефона: ";
    cin >> price;

    cout << "Введите количество: ";
    cin >> quantity;

    cout << "Введите дату покупки (ГГГГ-ММ-ДД): ";
    cin >> date;

    Customer customer(customerName, customerPhone);
    Phone phone(phoneModel, price);
    Buy buy(customer, phone, quantity, date);

    cout << "\nПокупка успешно добавлена!" << endl;
    cout << "Итоговая сумма: " << buy.getTotalPrice() << " руб." << endl;

    return buy;
}


Sale inputSale() {
    int saleId;
    string managerName, date;
    double amount;
    static int nextId = 1;

    cout << "\n=== ВВОД ДАННЫХ О ПРОДАЖЕ ===" << endl;

    saleId = nextId++;
    cout << "ID продажи (автоматически): " << saleId << endl;

    cout << "Введите имя менеджера: ";
    cin.ignore();
    getline(cin, managerName);

    cout << "Введите сумму продажи: ";
    cin >> amount;

    cout << "Введите дату продажи (ГГГГ-ММ-ДД): ";
    cin >> date;

    Sale sale(saleId, managerName, amount, date);

    cout << "\nПродажа успешно добавлена!" << endl;

    return sale;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Catalog<Buy> buyCatalog;  
    Catalog<Sale> saleCatalog; 
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            Buy b = inputBuy();
            buyCatalog.addItem(b);
            break;
        }

        case 2: {
            Sale s = inputSale();
            saleCatalog.addItem(s);
            break;
        }

        case 3: {
            cout << "\n=== ВСЕ ПОКУПКИ ===" << endl;
            buyCatalog.printTable();
            break;
        }

        case 4: {
            cout << "\n=== ВСЕ ПРОДАЖИ ===" << endl;
            saleCatalog.printTable();
            break;
        }

        case 5: {
            cout << "\n=== ОБЩАЯ СУММА ПОКУПОК ===" << endl;
            cout << "Итого: " << buyCatalog.getTotalSum() << " руб." << endl;
            break;
        }

        case 6: {
            cout << "\n=== ОБЩАЯ СУММА ПРОДАЖ ===" << endl;
            cout << "Итого: " << saleCatalog.getTotalSum() << " руб." << endl;
            break;
        }

        case 7: {
            buyCatalog.saveToFile("buys_report.txt");
            break;
        }

        case 8: {
            saleCatalog.saveToFile("sales_report.txt");
            break;
        }

        case 9: {
            buyCatalog.clear();
            cout << "Каталог покупок очищен!" << endl;
            break;
        }

        case 10: {
            saleCatalog.clear();
            cout << "Каталог продаж очищен!" << endl;
            break;
        }

        case 0: {
            cout << "\nДо свидания!" << endl;
            break;
        }

        default: {
            cout << "\nОшибка: неверный пункт меню!" << endl;
            break;
        }
        }

    } while (choice != 0);

    return 0;
}