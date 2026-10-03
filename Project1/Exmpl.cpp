#include <iostream>
#include <windows.h>
using namespace std;
void Ex1() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cout.setf(ios::right);
	cout.width(50);
	cout << "Этот текст выровнен по правому краю" << endl;
	cout.unsetf(ios::right); //вернуться к прежнему форматированию
	cout << "Этот текст выровнен по левому краю" << endl;
}