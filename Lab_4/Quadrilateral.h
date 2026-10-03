#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Quadrilateral {
protected:
    double x1, y1, x2, y2, x3, y3, x4, y4;

public:
    Quadrilateral();
    Quadrilateral(double x1, double y1, double x2, double y2,
        double x3, double y3, double x4, double y4);
    ~Quadrilateral();

    void set_coord1(double x, double y);
    void set_coord2(double x, double y);
    void set_coord3(double x, double y);
    void set_coord4(double x, double y);

    double get_x1() const;
    double get_y1() const;
    double get_x2() const;
    double get_y2() const;
    double get_x3() const;
    double get_y3() const;
    double get_x4() const;
    double get_y4() const;

    void displaycoord() const;
};