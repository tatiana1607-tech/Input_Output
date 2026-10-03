#include"Matrix.h"
#include<iostream>
using namespace std;

Matrix::Matrix() : rows(0), cols(0), arr(nullptr)
{

}
Matrix::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	
	arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			arr[i][j] = 0;
		}
	}
}
Matrix::Matrix(const Matrix& other)
{
	this->rows =other.rows;
	this->cols = other.cols;
	arr = new int* [other.rows];
	for (int i = 0; i < other.rows; i++)
	{
		arr[i] = new int[other.cols];
	}
	for (int i = 0; i < other.rows; i++)
	{
		for (int j = 0; j < other.cols; j++)
		{
			arr[i][j] = other.arr[i][j];
		}
	}
}
Matrix :: ~Matrix()
{
	for (int i = 0; i < rows; i++)
		delete[] arr[i];
	delete[] arr;
}
void Matrix :: set_el(int r, int c, int value)
{
	if ((r >= 0 && r < rows) && (c >= 0 && c < cols))
		arr[r][c] = value;
	else
		cout << "Нет такого индекса!" << endl;
}
int Matrix::get_el(int r,int c) const
{
	if (arr == NULL)
	{
		cout << "Матрица пуста!" << endl;
		return 0;
	}
	if ((r >= 0 && r < rows) && (c >= 0 && c < cols))
	{
		return arr[r][c];
	}
	else
	{
		cout << "Ошибка!Нет такого индекса!" << endl;
	}
}
int Matrix::get_rows() const
{
	return rows;
}
int Matrix::get_cols() const
{
	return cols;
}
bool Matrix :: operator==(const Matrix& other) const
{
	if (this->rows != other.rows || this->cols != other.cols)
	{
		return false;
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (this->arr[i][j] != other.arr[i][j])
				return false;
		}
	}
	return true;
}
Matrix& Matrix::operator=(const Matrix& other)
{
	if (this == &other)
		return *this;

	
	for (int i = 0; i < rows; i++)
		delete[] arr[i];
	delete[] arr;

	rows = other.rows;
	cols = other.cols;

	arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
		for (int j = 0; j < cols; j++)
			arr[i][j] = other.arr[i][j];
	}

	return *this;
}
 