#pragma once
#include"Quadrilateral.h"
#include<iostream>
using namespace std;

class Square : public Quadrilateral
{
public:
	Square();
	Square(double x1, double y1, double x2, double y2,
		double x3, double y3, double x4, double y4);
	~Square();
	void input();
	void display() const;
	double area() const;
	bool valid() const;
};
