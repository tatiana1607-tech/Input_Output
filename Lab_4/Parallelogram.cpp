#include"Quadrilateral.h"
#include"Parallelogram.h"
#include<iostream>
using namespace std;

Parallelogram::Parallelogram()
{

}
Parallelogram::Parallelogram(double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4) :Quadrilateral()
{

}
Parallelogram::~Parallelogram()
{
}
void Parallelogram::input()
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
            cout << "ќшибка!Ёто не параллелограм.ѕовторите ввод!" << endl;
        }
    } while (!valid());
}
double Parallelogram::area() const {
    
    double area1 = triangleArea(x1, y1, x2, y2, x3, y3);
    double area2 = triangleArea(x1, y1, x3, y3, x4, y4);
    return area1 + area2;
}

double Parallelogram::triangleArea(double x1, double y1, double x2, double y2,
    double x3, double y3) const {
    return 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}
void Parallelogram::display() const
{
    cout << "========ѕј–јЋЋ≈Ћќ√–јћ========" << endl;
    displaycoord();
    cout << "ѕЋќўјƒ№:" << area() << endl;
}
bool Parallelogram::valid() const {
   
    double ab_x = x2 - x1;
    double ab_y = y2 - y1;
    double dc_x = x3 - x4;
    double dc_y = y3 - y4;

    
    return abs(ab_x * dc_y - ab_y * dc_x) < 0.001 && area() > 0;
}
