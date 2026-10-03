#pragma once
#include"Quadrilateral.h"
#include<iostream>
using namespace std;

class Parallelogram : public Quadrilateral
{
public:
	Parallelogram();
	Parallelogram(double x1, double y1, double x2, double y2,
		double x3, double y3, double x4, double y4);
	~Parallelogram();
	void input();
	void display() const;
	double area() const;
	double triangleArea(double x1, double y1, double x2, double y2,
		double x3, double y3) const;
	bool valid() const;
};
