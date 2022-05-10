#include "Matrix2x2.h"
#include <iostream>
Matrix2x2::Matrix2x2()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			mtr[i][j] = 0;
		}
	}
}
Matrix2x2::Matrix2x2(int a1, int a2, int b1, int b2)
{
	mtr[0][0] = a1;
	mtr[0][1] = a2;
	mtr[1][0] = b1;
	mtr[1][1] = b2;
}
Matrix2x2::~Matrix2x2()
{
	mtr[0][0] = 0;
	mtr[0][1] = 0;
	mtr[1][0] = 0;
	mtr[1][1] = 0;
}

double Matrix2x2::func_norm()
{
	int max = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (abs(mtr[i][j]) >= max)
			{
				max = abs(mtr[i][j]);
			}
		}
	}
	return max; //максимальное значение по модулю
}
void Matrix2x2::show()
{
	std::cout << "\n";
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			std::cout << mtr[i][j] << " ";
		}
		std::cout << "\n";
	}
}
char* Matrix2x2::saveToStr(char* tmp)
{
	sprintf(tmp, "%d\n%d\n%d\n%d", mtr[0][0], mtr[0][1], mtr[1][0], mtr[1][1]);
	return tmp;
}