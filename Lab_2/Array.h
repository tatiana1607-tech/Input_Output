#pragma once
#include<iostream>

using namespace std;

class Array
{
private:
	double** el;
	int rows, cols;
	bool isInt;
public:
	Array(int r, int c, bool i);
	~Array();
	void input();
	 double sum_neg() const;
	 ostream& printTable(ostream& out=cout) const;
	 ostream& printReverse(ostream& out = cout) const;
};
