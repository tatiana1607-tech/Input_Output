#pragma once
#include<iostream>
using namespace std;
class Matrix;
class Vector
{
private:
	int* coord;
	int size;
	
public:
	Vector();
	Vector(int size);
	Vector(const Vector& other);
	~Vector();
	void set_val(int index, int value);
	int get_size() const;
	int get_val (int index) const;
	Vector& operator=(const Vector& other);
	friend Vector operator*(const Matrix& m, const Vector& v);
	friend ostream& operator<<(ostream& os, const Vector& v);
	friend istream& operator>>(istream& is, Vector& v);

};
