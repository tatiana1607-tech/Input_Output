#include"Quadrilateral.h"
#include"Square.h"
#include<iostream>
using namespace std;
Square::Square()
{

}
Square::Square(double x1, double y1, double x2, double y2,
	double x3, double y3, double x4, double y4) :Quadrilateral()
{

}
Square::~Square()
{

}
bool Square:: valid() const {
   
    double s1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double s2 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    double s3 = sqrt((x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3));
    double s4 = sqrt((x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4));

    
    bool sidesEqual = abs(s1 - s2) < 0.001 &&
        abs(s2 - s3) < 0.001 &&
        abs(s3 - s4) < 0.001;

    
    double dot1 = (x2 - x1) * (x4 - x1) + (y2 - y1) * (y4 - y1);
    double dot2 = (x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2);
    double dot3 = (x2 - x3) * (x4 - x3) + (y2 - y3) * (y4 - y3);
    double dot4 = (x3 - x4) * (x1 - x4) + (y3 - y4) * (y1 - y4);

    bool rightAngles = abs(dot1) < 0.001 && abs(dot2) < 0.001 &&
        abs(dot3) < 0.001 && abs(dot4) < 0.001;

    return sidesEqual && rightAngles;
}
void Square::input()
{
    do {
        cout << "Введите координату 1 вершины:" << endl;
        cin >> x1 >> y1;
        set_coord1(x1, y1);
        cout << "Введите координату 2 вершины:" << endl;
        cin >> x2 >> y2;
        set_coord2(x2, y2);
        cout << "Введите координату 3 вершины:" << endl;
        cin >> x3 >> y3;
        set_coord3(x3, y3);
        cout << "Введите координату 4 вершины:" << endl;
        cin >> x4 >> y4;
        set_coord4(x4, y4);

        if (!valid())
        {
            cout << "Ошибка!Это не квадрат.Повторите ввод!" << endl;
        }
    } while (!valid());
}
double Square::area() const
{
  
double side= sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
return side * side;
}
void Square::display() const
{
    cout << "========КВАДРАТ========" << endl;
    displaycoord();
    cout << "ПЛОЩАДЬ:" << area() << endl;
}
