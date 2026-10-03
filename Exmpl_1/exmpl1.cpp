#include <iostream>
#include <windows.h>
using namespace std;
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout.setf(ios::right);
	cout.width(50);
	cout << "Этот текст выровнен по правому краю" << endl;
	cout.unsetf(ios::right); 
	cout << "Этот текст выровнен по левому краю" << endl;
}