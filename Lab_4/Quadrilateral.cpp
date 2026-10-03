#include "Quadrilateral.h"

Quadrilateral::Quadrilateral() : x1(0), y1(0), x2(0), y2(0), x3(0), y3(0), x4(0), y4(0) {}

Quadrilateral::Quadrilateral(double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4)
    : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {
}

Quadrilateral::~Quadrilateral() {}

void Quadrilateral::set_coord1(double x, double y) { x1 = x; y1 = y; }
void Quadrilateral::set_coord2(double x, double y) { x2 = x; y2 = y; }
void Quadrilateral::set_coord3(double x, double y) { x3 = x; y3 = y; }
void Quadrilateral::set_coord4(double x, double y) { x4 = x; y4 = y; }

double Quadrilateral::get_x1() const { return x1; }
double Quadrilateral::get_y1() const { return y1; }
double Quadrilateral::get_x2() const { return x2; }
double Quadrilateral::get_y2() const { return y2; }
double Quadrilateral::get_x3() const { return x3; }
double Quadrilateral::get_y3() const { return y3; }
double Quadrilateral::get_x4() const { return x4; }
double Quadrilateral::get_y4() const { return y4; }

void Quadrilateral::displaycoord() const {
    cout << "Вершина 1: (" << x1 << ";" << y1 << ")" << endl;
    cout << "Вершина 2: (" << x2 << ";" << y2 << ")" << endl;
    cout << "Вершина 3: (" << x3 << ";" << y3 << ")" << endl;
    cout << "Вершина 4: (" << x4 << ";" << y4 << ")" << endl;
}