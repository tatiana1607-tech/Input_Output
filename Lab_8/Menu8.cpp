#include <iostream>
#include <windows.h>
#include "SmartPtr.h"
#include "Transaction.h"
#include "MobilePhone.h"
#include "Customer.h"
#include "Manager.h"
#include "Purchase.h"
#include "Sale.h"
#include "IO.h"

using namespace std;


SmartPointer<MobilePhone> lastCreatedPhone(nullptr);


double getValidDouble(const string& prompt) {
    double value;
    cout << prompt;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ошибка! Введите число: ";
    }
    return value;
}

int getValidInt(const string& prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ошибка! Введите целое число: ";
    }
    return value;
}


void editLastPhone() {
    if (lastCreatedPhone.operator->() == nullptr) {
        cout << "Нет телефона для редактирования. Сначала добавьте покупку или продажу.\n";
        return;
    }

    cout << "\n===== РЕДАКТИРОВАНИЕ ТЕЛЕФОНА (ДЕМОНСТРАЦИЯ ТРАНЗАКЦИИ) =====\n";
    cout << "Текущие данные телефона:\n";
    cout << "  Модель: " << lastCreatedPhone->getModel() << endl;
    cout << "  Цена: " << lastCreatedPhone->getPrice() << endl;
    cout << "  Количество: " << lastCreatedPhone->getQuantity() << endl;

   
    string oldModel = lastCreatedPhone->getModel();
    double oldPrice = lastCreatedPhone->getPrice();
    int oldQty = lastCreatedPhone->getQuantity();

  
    Transaction<MobilePhone> transaction(*lastCreatedPhone);

    cout << "\nВведите НОВЫЕ данные (для демонстрации отката введите цену <=0):\n";

    string newModel;
    double newPrice;
    int newQty;

    cout << "Новая модель (" << oldModel << "): ";
    cin.ignore();
    getline(cin, newModel);
    if (newModel.empty()) newModel = oldModel;

    newPrice = getValidDouble("Новая цена (0 для отката): ");
    newQty = getValidInt("Новое количество: ");

    
    MobilePhone newPhone(newModel, newPrice, newQty);

    cout << "\n--- Начинаем транзакцию ---\n";
    transaction.beginTransaction(newPhone);

   
    if (transaction->getPrice() <= 0) {
        cout << " ОШИБКА: цена не может быть <= 0!\n";
        cout << "--- ВЫПОЛНЯЕМ ОТКАТ ТРАНЗАКЦИИ ---\n";
        transaction.rollback(); 
        cout << " Телефон ВОССТАНОВЛЕН к исходному состоянию:\n";
        cout << "  Модель: " << lastCreatedPhone->getModel() << endl;
        cout << "  Цена: " << lastCreatedPhone->getPrice() << endl;
        cout << "  Количество: " << lastCreatedPhone->getQuantity() << endl;
        return;
    }

    cout << " Данные корректны!\n";
    cout << "--- ПОДТВЕРЖДАЕМ ТРАНЗАКЦИЮ (COMMIT) ---\n";
    transaction.commit();

    *lastCreatedPhone = transaction.getState();

    cout << " Телефон УСПЕШНО ОБНОВЛЁН:\n";
    cout << "  Было: " << oldModel << ", " << oldPrice << ", " << oldQty << endl;
    cout << "  Стало: " << lastCreatedPhone->getModel() << ", "
        << lastCreatedPhone->getPrice() << ", " << lastCreatedPhone->getQuantity() << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true) {
        cout << "\n==================== МЕНЮ ====================\n";
        cout << "1. Добавить покупку (клиент)\n";
        cout << "2. Добавить продажу (менеджер)\n";
        cout << "3. Показать все покупки\n";
        cout << "4. Показать все продажи\n";
        cout << "5.  РЕДАКТИРОВАТЬ последний телефон (демо транзакции)\n";
        cout << "6. Выход\n";
        cout << "==============================================\n";

        int choice = getValidInt("Ваш выбор: ");

        if (choice == 6) break;

        if (choice == 1) {
            string model, customerName;
            double price;
            int qty;

            cout << "Модель телефона: ";
            cin >> model;
            price = getValidDouble("Цена: ");
            qty = getValidInt("Количество: ");
            cout << "Имя клиента: ";
            cin >> customerName;

            Transaction<MobilePhone> transaction;
            MobilePhone newPhone(model, price, qty);

            if (price <= 0 || qty <= 0) {
                cout << "Ошибка: цена и количество должны быть > 0!\n";
                transaction.rollback();
                continue;
            }

            transaction.beginTransaction(newPhone);
            transaction.commit();

            SmartPointer<MobilePhone> ptr(new MobilePhone(transaction.getState()));
            lastCreatedPhone = ptr; 

            Customer c(customerName);
            Purchase p(ptr, c);
            IO::savePurchase(p);

            cout << "Покупка успешно добавлена!\n";
        }

        if (choice == 2) {
            string model, managerName;
            double price;
            int qty;

            cout << "Модель телефона: ";
            cin >> model;
            price = getValidDouble("Цена: ");
            qty = getValidInt("Количество: ");
            cout << "Имя менеджера: ";
            cin >> managerName;

            Transaction<MobilePhone> transaction;
            MobilePhone newPhone(model, price, qty);

            if (price <= 0 || qty <= 0) {
                cout << "Ошибка: цена и количество должны быть > 0!\n";
                transaction.rollback();
                continue;
            }

            transaction.beginTransaction(newPhone);
            transaction.commit();

            SmartPointer<MobilePhone> ptr(new MobilePhone(transaction.getState()));
            lastCreatedPhone = ptr;  

            Manager m(managerName);
            Sale s(ptr, m);
            IO::saveSale(s);

            cout << "Продажа успешно добавлена!\n";
        }

        if (choice == 3) {
            IO::printPurchases();
        }

        if (choice == 4) {
            IO::printSales();
        }

        if (choice == 5) {
            editLastPhone(); 
        }
    }

    cout << "Программа завершена.\n";
    return 0;
}