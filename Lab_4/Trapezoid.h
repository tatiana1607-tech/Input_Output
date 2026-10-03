#pragma once
#include"Quadrilateral.h"
#include<iostream>
using namespace std;

class Trapezoid : public Quadrilateral
{
public:
	Trapezoid();
	Trapezoid(double x1, double y1, double x2, double y2,
		double x3, double y3, double x4, double y4);
	~Trapezoid();
	void input();
	void display() const;
	double triangleArea(double x1, double y1, double x2, double y2,
		double x3, double y3) const;
	double area() const;
	bool valid() const;
};
