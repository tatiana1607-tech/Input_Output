#include"Quadrilateral.h"
#include"Square.h"
#include"Rectangle.h"
#include"Parallelogram.h"
#include"Trapezoid.h"
#include"Chek.h"
#include<iostream>
#include<fstream>
int menu()
{
    int k;
    cout << "==========================================" << endl;
    cout << "|              МЕНЮ ПРОГРАММЫ             |" << endl;
    cout << "==========================================" << endl;
    cout << "| 1. Добавить квадрат                     |" << endl;
    cout << "| 2. Добавить прямоугольник               |" << endl;
    cout << "| 3. Добавить параллелограмм              |" << endl;
    cout << "| 4. Добавить трапецию                    |" << endl;
    cout << "| 5. Найти фигуру с максимальной площадью |" << endl;
    cout << "| 6. Вывод в файл                         |" << endl;
    cout << "| 0. Выход                                |" << endl;
    cout << "========================================" << endl;
    k = getValidIntInRange("Ваш выбор:",0,6);
    return k;
}
int main()
{
    setlocale(0, "rus");
    double maxArea = -1;
    int typeMax = 0;
    Square maxS;      // 1
    Rectangle maxR;   // 2
    Parallelogram maxP; // 3
    Trapezoid maxT;   // 4

    while (true)
    {
        switch (menu())
        {
        case 1:
        {
            Square a;
            a.input();
            a.display();

            double area = a.area();
            if (area > maxArea)
            {
                maxArea = area;
                maxS = a;
                typeMax = 1;
            }
            break;  
        }

        case 2:
        {
            Rectangle b;
            b.input();
            b.display();
            double area = b.area();
            if (area > maxArea)
            {
                maxArea = area;
                maxR = b;
                typeMax = 2;
            }
            break;  
        }

        case 3:
        {
            Parallelogram c;
            c.input();
            c.display();
            double area = c.area();
            if (area > maxArea)
            {
                maxArea = area;
                maxP = c;
                typeMax = 3;
            }
            break;  
        }

        case 4:
        {
            Trapezoid d;
            d.input();
            d.display();
            double area = d.area();
            if (area > maxArea)
            {
                maxArea = area;
                maxT = d;
                typeMax = 4;
            }
            break; 
        }

        case 5:
        {
            if (maxArea < 0)
            {
                cout << "Нет добавленных фигур" << endl;
                break;
            }
            cout << "========== ФИГУРА С МАКСИМАЛЬНОЙ ПЛОЩАДЬЮ ==========" << endl;
            if (typeMax == 1)
            {
                maxS.display();
            }
            else if (typeMax == 2)
            {
                maxR.display();
            }
            else if (typeMax == 3)
            {
                maxP.display();
            }
            else if (typeMax == 4)
            {
                maxT.display();
            }
            break; 
        }

        case 6:
        {
            if (maxArea < 0)
            {
                cout << "Нет добавленных фигур для сохранения!" << endl;
                break;
            }

            ofstream outfile("max_figure.txt");
            if (outfile.is_open())
            {
                outfile << "========== ФИГУРА С МАКСИМАЛЬНОЙ ПЛОЩАДЬЮ ==========" << endl;
                outfile << "Площадь: " << maxArea << endl;

                
                if (typeMax == 1)
                {
                    outfile << "Тип: КВАДРАТ" << endl;
                    
                }
                else if (typeMax == 2)
                {
                    outfile << "Тип: ПРЯМОУГОЛЬНИК" << endl;
                }
                else if (typeMax == 3)
                {
                    outfile << "Тип: ПАРАЛЛЕЛОГРАММ" << endl;
                }
                else if (typeMax == 4)
                {
                    outfile << "Тип: ТРАПЕЦИЯ" << endl;
                }

                outfile.close();
                cout << "Данные сохранены в файл max_figure.txt" << endl;
            }
            else
            {
                cout << "Ошибка открытия файла!" << endl;
            }
            break;  
        }

        case 0:
        {
            cout << "Программа завершена!" << endl;
            return 0;
        }

        default:
        {
            cout << "Неверный выбор!" << endl;
            break;
        }
        }
    }
}