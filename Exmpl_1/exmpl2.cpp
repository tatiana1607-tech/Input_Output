#include <iostream>
#include <iomanip>

void main{
	const long double result = std::acos(-1.L);
	std::cout << std::fixed << "Точность, устанавливаемая по умолчанию(6): " << result << ' \n'
		<< "установка точности с помощью функции std::setprecision(10) :"<<std::setprecision(10) <<result<<' \n'<< "установка максимальной точности :" <<std::setprecision(std::numeric_limits<long double>::digits10)<<result<<' \n' ;
		double newResult = -2646693125139304345. / 842468587426513207.;
	std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(0) << newResult << ' \n';
	std::cout << std::showpoint << newResult << ' \n';
	std::cout << "Left fill: \n" << std::left << std::setfill(' ')
		<< std::setw(12) << -1.23 << ' \n'
		<< std::setw(12) << std::hex << std::showbase << 255 << std::endl;
	std::cout << "Internal fill: \n" << std::internal
		<< std::setw(12) << std::setprecision(3) << -1.23 << ' \n'
		<< std::setw(12) << 255 << "\n";
	std::cout << "Right fill: \n" << std::right
		<< std::setw(15) << -1.23 << ' \n'
		<< std::setw(15) << std::hex << std::noshowbase << 255 << ' \n';
}