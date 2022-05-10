#include "Vector10.h"
#include <iostream>
Vector10::Vector10()
{
	vct = new int[10];
	for (int i = 0; i < 10; i++)
	{
		vct[i] = 0;
	}
}

Vector10::Vector10(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
	vct = new int[10]{a1, a2, a3, a4, a5, a6, a7, a8, a9, a10};
}
Vector10::~Vector10()
{
	delete[] vct;
}

double Vector10::func_norm()
{
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum = sum + vct[i];
	}
	return sqrt(abs(sum)); //корень квадратный из суммы элементов по модулю
}
void Vector10::show()
{
	std::cout << "\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << vct[i] << " ";
	}
	std::cout << "\n";
}
char* Vector10::saveToStr(char* tmp)
{
	sprintf(tmp, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", vct[0], vct[1], vct[2], vct[3], vct[4], vct[5], vct[6], vct[7], vct[8], vct[9]);
	return tmp;
}