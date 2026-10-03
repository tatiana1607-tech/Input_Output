#pragma once
#include<iostream>
using namespace std;
class Vector;
class Matrix
{
private:
	int rows, cols;
	int** arr;
	
public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(const Matrix& other);
	~Matrix();
	int get_rows() const;
	int get_cols() const;
	int get_el(int r,int c) const;
	void set_el(int r, int c, int value);
  bool operator==(const Matrix& other) const;
  Matrix& operator=(const Matrix& other);
  friend Vector operator*(const Matrix& m, const Vector& v);
  friend ostream& operator<<(ostream& os, const Matrix& m);
  friend istream& operator>>(istream& is, Matrix& m);
};
