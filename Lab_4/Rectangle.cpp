#include"Quadrilateral.h"
#include"Rectangle.h"
#include<iostream>
using namespace std;

Rectangle::Rectangle()
{

}
Rectangle::Rectangle(double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4) :Quadrilateral()
{

}
Rectangle::~Rectangle()
{ }
void Rectangle::input()
{
    do {
        cout << "¬ведите координату 1 вершины:" << endl;
        cin >> x1 >> y1;
        
        cout << "¬ведите координату 2 вершины:" << endl;
        cin >> x2 >> y2;
       
        cout << "¬ведите координату 3 вершины:" << endl;
        cin >> x3 >> y3;
        
        cout << "¬ведите координату 4 вершины:" << endl;
        cin >> x4 >> y4;
       

        if (!valid())
        {
            cout << "ќшибка!Ёто не пр€моугольник.ѕовторите ввод!" << endl;
        }
    } while (!valid());
}
bool Rectangle::valid() const {
   
    double width1 = abs(x2 - x1);
    double width2 = abs(x3 - x4);
    double height1 = abs(y3 - y2);
    double height2 = abs(y4 - y1);

    
    bool oppositeEqual = abs(width1 - width2) < 0.001 &&
        abs(height1 - height2) < 0.001;

    
    double dot1 = (x2 - x1) * (x4 - x1) + (y2 - y1) * (y4 - y1);
    double dot2 = (x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2);

    bool rightAngles = abs(dot1) < 0.001 && abs(dot2) < 0.001;

    return oppositeEqual && rightAngles && width1 > 0 && height1 > 0;
}
double Rectangle::area() const
{

    double width = abs(x2 - x1);   
    double height = abs(y3 - y1);  
    return width * height;
}
void Rectangle::display() const
{
    cout << "========ѕ–яћќ”√ќЋ№Ќ» ========" << endl;
    displaycoord();
    cout << "ѕЋќўјƒ№:" << area() << endl;
}
