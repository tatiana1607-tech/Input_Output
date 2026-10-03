#include"Vector.h"
#include"Matrix.h"
#include<iostream>
#include<iomanip>
#include<windows.h>
using namespace std;

Vector operator*(const Matrix& m, const Vector& v)
{
	if (m.cols != v.size)
	{
		cout << "Ошибка: нельзя перемножить! "
			<< "Столбцов матрицы: " << m.cols
			<< ", размер вектора: " << v.size << endl;
		return Vector();
	}
	
		Vector result(m.rows);
		for (int i = 0; i < m.rows; i++)
		{
			result.coord[i] = 0;
			for (int j = 0; j < m.cols; j++)
			{
				result.coord[i] += m.arr[i][j] * v.coord[j];
			}
		}
	
	return result;
}
ostream& operator<<(ostream& os, const Vector& v)
{
	for (int i = 0; i < v.size; i++)
	{
		os << "|"<<v.coord[i] << "|";
	}
	os << endl;
	return os;
}
istream& operator>>(istream& is, Vector& v)
{
	cout << "Введите элементы вектора (" << v.size << "):" << endl;
	for (int i = 0; i < v.size; i++)
	{
		cout << "Элемент " << i << ":" << endl;
		is >> v.coord[i];
	}
	return is;
}
ostream& operator<<(ostream& os, const Matrix& m)
{
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
		{
			os <<setw(6) <<m.arr[i][j];
		}
		os << endl;
	}
	return os;
}
istream& operator>>(istream& is, Matrix& m)
{
	cout << "Введите элементы матрицы " << m.rows << "х" << m.cols << ":" << endl;
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
		{
			cout << "Элемент [" << i << "][" << j << "]:" << endl;
			is >> m.arr[i][j];
		}
	}
	return is;
}

int menu()
{

	int ch;
	cout << "==================" << endl;
	cout << "       MENU        " << endl;
	cout << "==================" << endl;
	cout << "Что бы вы хотели сделать?" << endl;
	cout << "==================================" << endl;
	cout << "1)Добавить матрицу" << endl;
	cout << "2)Добавить вектор" << endl;
	cout << "3)Сравнение матриц" << endl;
	cout << "4)Умножение матрицы на вектор" << endl;
	cout << "5) Выход из программы" << endl;
	cin >> ch;
	return ch;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int count1, count2;
	cout << "Сколько матриц хотите ввести?" << endl;
	cin >> count1;
	cout << "Сколько векторов хотите ввести?" << endl;
	cin >> count2;
	Matrix* rm = new Matrix[count1];
	Vector* rv = new Vector[count2];
	int cm = 0, cv = 0;
	while (true)
	{
		switch (menu())
		{
		case 1:
		{
			if (cm >= count1)
			{
				cout << "Больше нельзя добавить матриц!" << endl;
				break;
			}

			int rows, cols;
			cout << "Введите количество сторок:" << endl;
			cin >> rows ;
			cout << "Введите количество столбцов:" << endl;
			cin >> cols;
			cin.ignore();
			rm[cm] = Matrix(rows, cols);
			cin >> rm[cm];
			cm++;
			cout << "Матрица добавлена. Всего матриц: " << cm << endl;
			break;
		}
		case 2: 
		{
			if (cv >= count2)
			{
				cout << "Больше нельзя добавить векторы!" << endl;
				break;
			}

			int size;
			cout << "Введите количество элементов вектора:" << endl;
			cin >> size;
			rv[cv] = Vector(size);
			cin >> rv[cv];
			cv++;
			cout << "Вектор добавлен. Всего векторов: " << cv << endl;
			break;
		}
		case 3:
		{
			if (cm < 2) {
				cout << "Нужно хотя бы 2 матрицы для сравнения!" << endl;
				cout << "Сейчас матриц: " << cm << endl;
				break;
			}
			cout << "Доступные матрицы (0-" << cm - 1 << "):" << endl;
			for (int i = 0; i < cm; i++) {
				cout << "Матрица " << i << ":" << endl;
				cout << rm[i];  
			}

			int idx1, idx2;
			cout << "Введите индексы двух матриц для сравнения: ";
			cin >> idx1 >> idx2;

			if (idx1 >= 0 && idx1 < cm &&
				idx2 >= 0 && idx2 < cm) {
				if (rm[idx1] ==rm[idx2]) 
				{  

					cout << "Матрицы " << idx1 << " и " << idx2 << " РАВНЫ" << endl;
				}
				else {
					cout << "Матрицы " << idx1 << " и " << idx2 << " НЕ РАВНЫ" << endl;
				}
			}
			else {
				cout << "Неверные индексы!" << endl;
			}
			break;
		}
		case 4:
		{
			if (cm == 0 || cv == 0)
			{
				cout << "Нужен хотя бы один вектор или матрица для умножения!" << endl;
				break;
			}
			cout << "Доступные матрицы (0-" << cm - 1 << "):" << endl;
			for (int i = 0; i < cm; i++) {
				cout << "Матрица " << i << ": "
					<< rm[i].get_rows() << "x"
					<< rm[i].get_cols() << endl;
			}

			cout << "Доступные векторы (0-" << cv - 1 << "):" << endl;
			for (int i = 0; i < cv; i++) {
				cout << "Вектор " << i << ": " << rv[i] << endl;
			}

			int mIdx, vIdx;
			cout << "Введите индекс матрицы и вектора: ";
			cin >> mIdx >> vIdx;

			Vector result = rm[mIdx] * rv[vIdx];
			cout << "Результат умножения" << endl;
			cout << result;
			break;
		}
		case 5:
			cout << "Программа завершена!" << endl;
			delete[] rm;
			delete[] rv;
			return 0;
			break;
		default:cout << "Неверный выбор!";
		}
	}
}