#include"Array.h"
#include<iostream>
#include<string>
#include<ctime>
#include<iomanip>

using namespace std;


Array::Array( int r, int c, bool i) 
{
	rows = r;
	cols = c;
	isInt = i;
	el = new double* [r];
	for (int i = 0; i < r; i++)
		el[i] = new double[c];
}
Array ::~Array()
{
	for (int i = 0; i < rows; i++)
		delete[] el[i];
	delete[] el;
}
void Array::input()
{
	srand(time(NULL));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			double x;
			if (isInt) 
			{
				x = -20 + rand() % 50;
				el[i][j] = (int)x;
			}
			else
			{
				x = (double) -20.0 +(rand() % 10000) / 100.0;
				el[i][j] = x;
			}
			
		}
	}
}
double Array::sum_neg() const
{
	double sum=0;
	bool f = false;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (el[i][j] < 0)
			{
				sum += el[i][j];
				f = true;
			}
		}
	}
	if (!f) cout << "В массиве нет отрицательных элементов!" << endl;
	return sum;
}
ostream& Array::printTable(ostream& out) const
{
	out << "        ";
	for (int j = 0; j < cols; j++) {
		out << setw(8) << j;
	}
	out << "\n";

	out << "    ";
	for (int j = 0; j < cols + 1; j++) {
		out << "--------";
	}
	out << "\n";

	for (int i = 0; i < rows; i++) {
		out << setw(2) << i << " | \t";

		for (int j = 0; j < cols; j++) {
			if (isInt)
				out << setw(8) << (int)el[i][j];
			else
				out << setw(8) << fixed << setprecision(2) << el[i][j];
		}
		out << "\n";
	}

	return out;
}

ostream& Array::printReverse(ostream& out) const
{
	out << "        ";
	for (int j = cols - 1; j >= 0; j--) {
		out << setw(8) << j;
	}
	out << "\n";

	out << "    ";
	for (int j = 0; j < cols + 1; j++) {
		out << "--------";
	}
	out << "\n";

	for (int i = rows - 1; i >= 0; i--) {
		out << setw(2) << i << " | \t";

		for (int j = cols - 1; j >= 0; j--) {
			if (isInt)
				out << setw(8) << (int)el[i][j];
			else
				out << setw(8) << fixed << setprecision(2) << el[i][j];
		}
		out << "\n";
	}

	return out;
}

