#include"Quadrilateral.h"
#include"Trapezoid.h"
#include<iostream>
using namespace std;
Trapezoid::Trapezoid()
{

}
Trapezoid::Trapezoid(double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4) :Quadrilateral()
{

}
Trapezoid::~Trapezoid()
{
}
void Trapezoid::input()
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
            cout << "ќшибка!Ёто не трапеци€.ѕовторите ввод!" << endl;
        }
    } while (!valid());
}
double Trapezoid::triangleArea(double x1, double y1, double x2, double y2,
    double x3, double y3) const {
    return 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

double Trapezoid::area() const {
    
    double area1 = triangleArea(x1, y1, x2, y2, x3, y3);  
    double area2 = triangleArea(x1, y1, x3, y3, x4, y4);  
    return area1 + area2;
}
void Trapezoid::display() const
{
    cout << "========“–јѕ≈÷»я========" << endl;
    displaycoord();
    cout << "ѕЋќўјƒ№:" << area() << endl;
}
bool Trapezoid::valid() const {
  
    double ABx = x2 - x1;
    double ABy = y2 - y1;
    double CDx = x4 - x3;
    double CDy = y4 - y3;
    double BCx = x3 - x2;
    double BCy = y3 - y2;

    double DAx = x1 - x4;
    double DAy = y1 - y4;


   
    double cross1 = ABx * CDy - ABy * CDx;
    bool basesParallel = abs(cross1) < 0.001; 


   
    double cross2 = BCx * DAy - BCy * DAx;
    bool legsParallel = abs(cross2) < 0.001;   

    
    bool hasArea = area() > 0;
    return (basesParallel || legsParallel) && hasArea;
}