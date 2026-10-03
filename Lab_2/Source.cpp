/*12. Создать класс Array для работы с двумерными массивами (как
целочисленными, так и дробными). Найти сумму отрицательных элементов
массива, вывести на экран этот массив в обратном порядке. Память под
массив выделять динамически. Размер массива указывает пользователь.
Необходимо обязательно освобождать память, выделенную под массив.
Написать свой манипулятор, выводящий содержимое массива в табличном
виде*/
#include"Array.h"
#include<iostream>
#include<string>
#include<ctime>
#include<iomanip>
using namespace std;
int menu()
{
	int ch;
    cout << "=================="<<endl;
    cout << "       ARRAY      " << endl;
    cout << "==================" << endl;
    cout << "Что бы вы хотели сделать?" << endl;
    cout << "==================================" << endl;
    cout << "1)Добавить массив" << endl;
    cout << "2)Вывести массив на экран" << endl;
    cout << "3)Вывести массив на экран в обратном порядке" << endl;
    cout << "4)Найти сумму отрицательных элементов массива" << endl;
    cout << "5)Выход из программы" << endl;
   
    cout << "Ваш выбор?";
    while (true)
    {
        cin >> ch;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка: введите корректное действительное число!\n";
        }
        else
        {
            char c;
            if (cin.get(c) && c != '\n')
            {

                cout << "Ошибка: введите корректное действительное число!\n";
                cin.ignore(10000, '\n');
            }
            else
            {
                break;
            }
        }
    }
    return ch;
}
int main()
{
    
    setlocale(0, "rus");
    Array* arr = nullptr;
    bool exists = false;

    while (true)
    {
        switch (menu())
        {
        case 1:
        {
            int rows, cols, type;
            cout << "Введите количество строк: ";
            while (true)
            {
                cin >> rows;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Ошибка: введите корректное действительное число!\n";
                }
                else
                {
                    char c;
                    if (cin.get(c) && c != '\n')
                    {

                        cout << "Ошибка: введите корректное действительное число!\n";
                        cin.ignore(10000, '\n');
                    }
                    else
                    {
                        break;
                    }
                }
            }
            cout << "Введите количество столбцов: ";
            while (true)
            {
                cin >> cols;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Ошибка: введите корректное действительное число!\n";
                }
                else
                {
                    char c;
                    if (cin.get(c) && c != '\n')
                    {

                        cout << "Ошибка: введите корректное действительное число!\n";
                        cin.ignore(10000, '\n');
                    }
                    else
                    {
                        break;
                    }
                }
            }

            cout << "Введите тип массива (1-int, 2-double): ";
            while (true)
            {
                cin >> type;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Ошибка: введите корректное действительное число!\n";
                }
                else
                {
                    char c;
                    if (cin.get(c) && c != '\n')
                    {

                        cout << "Ошибка: введите корректное действительное число!\n";
                        cin.ignore(10000, '\n');
                    }
                    else
                    {
                        break;
                    }
                }
            }

            bool isInt = (type == 1);

            if (exists)
                delete arr;

            arr = new Array(rows, cols, isInt);
            arr->input();
            exists = true;

            cout << "Массив создан!\n";
        }
        break;

        case 2:
            if (!exists) { cout << "Сначала создайте массив!\n"; break; }
            arr->printTable();
            break;

        case 3:
            if (!exists) { cout << "Сначала создайте массив!\n"; break; }
            arr->printReverse();
            break;

        case 4:
            if (!exists) { cout << "Сначала создайте массив!\n"; break; }
            cout << "Сумма отрицательных: " << arr->sum_neg() << endl;
            break;

        case 5:
            if (exists) delete arr;
            return 0;

        default:
            cout << "Неверный выбор!\n";
        }
    }
    return 0;
 }
