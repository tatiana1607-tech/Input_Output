#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include "MobileApp.h"
using namespace std;

int getValidIntInput(string pr)
{
    int value;
    while (true)
    {
        cout << pr;
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите корректное число\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

double getValidDoubleInput(string pr)
{
    double value;
    while (true)
    {
        cout << pr;
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите корректное число\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

int menu()
{
    cout << "==================================\n";
    cout << "       МОБИЛЬНЫЕ ПРИЛОЖЕНИЯ      \n";
    cout << "==================================\n";
    cout << "1) Добавить новое приложение\n";
    cout << "2) Показать все приложения\n";
    cout << "3) Найти самое новое приложение\n";
    cout << "4) Найти приложение по ОС\n";
    cout << "5) Найти приложение по рейтингу\n";
    cout << "6) Найти платные/бесплатные приложения\n";
    cout << "7) Сохранить в файл\n";
    cout << "8) Выход\n";
    cout << "==================================\n";

    return getValidIntInput("Ваш выбор: ");
}

int main()
{
    setlocale(LC_ALL, "rus");

    int count = getValidIntInput("Сколько приложений хотите ввести? ");

    
    if (count <= 0)
    {
        cout << "Некорректное количество. Будет создан пустой массив.\n";
        count = 0;
    }

    MobileApp* arr = nullptr;
    if (count > 0)
    {
        arr = new MobileApp[count];

        for (int i = 0; i < count; i++)
        {
            cout << "-------------------------------------\n";
            cout << "Приложение " << i + 1 << endl;
            arr[i].input();
        }
    }

    while (true)
    {
        int choice = menu();

        switch (choice)
        {
        case 1:
        {
           
            MobileApp* new_arr = new MobileApp[count + 1];

            
            for (int i = 0; i < count; i++)
                new_arr[i] = arr[i];

            cout << "-------------------------------------\n";
            cout << "Введите новое приложение:\n";
            new_arr[count].input();

           
            if (arr != nullptr)
                delete[] arr;

            
            arr = new_arr;
            count++;

            cout << "Приложение успешно добавлено! Всего приложений: " << count << "\n";
            break;
        }

        case 2:
        {
            if (count == 0 || arr == nullptr)
            {
                cout << "Нет приложений!\n";
                break;
            }

            cout << "\n===== ВСЕ ПРИЛОЖЕНИЯ =====\n";
            for (int i = 0; i < count; i++)
                arr[i].out();

            break;
        }

        case 3:
        {
            if (count == 0 || arr == nullptr)
            {
                cout << "Нет приложений!\n";
                break;
            }

            cout << "\n===== САМОЕ НОВОЕ ПРИЛОЖЕНИЕ =====\n";
            MobileApp newest = MobileApp::newest_app(arr, count);
            newest.out();
            break;
        }

        case 4:
        {
            if (count == 0 || arr == nullptr)
            {
                cout << "Нет приложений!\n";
                break;
            }

            string os;
            cout << "Введите ОС (Android/IOS/Windows/Linux/MacOS): ";
            cin >> os;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            MobileApp::find_app(arr, count, os);
            break;
        }

        case 5:
        {
            if (count == 0 || arr == nullptr)
            {
                cout << "Нет приложений!\n";
                break;
            }

            double r = getValidDoubleInput("Введите минимальный рейтинг (0–5): ");

            while (r < 0 || r > 5)
                r = getValidDoubleInput("Введите рейтинг от 0 до 5: ");

            MobileApp::find_raiting(arr, count, r);
            break;
        }

        case 6:
        {
            if (count == 0 || arr == nullptr)
            {
                cout << "Нет приложений!\n";
                break;
            }

            int t = getValidIntInput("1 — платные, 0 — бесплатные: ");

            while (t != 0 && t != 1)
                t = getValidIntInput("Введите только 0 или 1: ");

            MobileApp::paid(arr, count, t == 1);
            break;
        }

        case 7:
        {
            if (count == 0 || arr == nullptr)
            {
                cout << "Нет приложений для сохранения!\n";
                break;
            }

            ofstream file("fail_lab1.txt");
            if (!file.is_open())
            {
                cout << "Ошибка открытия файла!\n";
                break;
            }

            for (int i = 0; i < count; i++)
                arr[i].save_file(file);

            file.close();
            cout << "Данные сохранены в файл fail_lab1.txt!\n";
            break;
        }

        case 8:
        {
            if (arr != nullptr)
                delete[] arr;

            cout << "Программа завершена.\n";
            return 0;
        }

        default:
            cout << "Неверный выбор! Попробуйте снова.\n";
        }
    }

    return 0;
}