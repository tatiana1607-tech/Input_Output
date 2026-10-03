#include"Vector.h"
#include<iostream>
#include<ctime>
using namespace std;

Vector::Vector() : coord(nullptr), size(0)
{ 
}
Vector::Vector(int size)
{
	this->size = size;
	coord = new int[size];
}
Vector::Vector(const Vector& other)
{
	this->size = other.size;
	coord = new int[size];
	for (int i = 0; i < size; i++)
	{
		coord[i] = other.coord[i];
	}
}
Vector :: ~Vector()
{
	delete[] coord;
}
 void Vector::set_val(int index,int value)
{
	if (index >= 0 && index < size)
	{
		coord[index] = value;
	}
	else
	{
		cout << "Ошибка!Нет такого индекса!" << endl;
	}
}

 int Vector::get_size() const
 {
	 return size;
 }
 int Vector::get_val(int index) const
 {
	 if (coord == NULL)
	 {
		 cout << "Вектор пуст!" << endl;
		 return 0;
	 }
	 if(index>=0 && index<size)
	 { 
		 return coord[index];
	 }
	 else {
		 cout << "Ошибка!Нет такого индекса!" << endl;
	 }
 }
 Vector& Vector::operator=(const Vector& other)
 {
	 if (this == &other)
		 return *this;

	 delete[] coord;

	 size = other.size;
	 coord = new int[size];

	 for (int i = 0; i < size; i++)
		 coord[i] = other.coord[i];

	 return *this;
 }
 