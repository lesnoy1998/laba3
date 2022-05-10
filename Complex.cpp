#include "Complex.h"
#include <iostream>
Complex::Complex(int a1, int b1)
{
	a = a1;
	b = b1;
}
Complex::~Complex()
{
	a = 0;
	b = 0;
}
double Complex::func_norm()
{
	std::cout << "\nKOMPLEX MODULE\n";
	return pow(abs(sqrt(pow(a, 2) + pow(b, 2))), 2); //модуль комплексного числа в квадрате
}
void Complex::show()
{
	std::cout << "\nKOMPLEX = " << a << " + " << b << "i\n";
	return;
}

char* Complex::saveToStr(char* tmp)
{
	sprintf(tmp, "%d\n%d", a, b);
	return tmp;
}