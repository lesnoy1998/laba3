#pragma once
#include "Norma.h"
class Matrix2x2 : public Norma
{
private:
	int mtr[2][2];
public:
	Matrix2x2();
	Matrix2x2(int a1, int a2, int b1, int b2);
	~Matrix2x2();

	double func_norm() final;
	void show();

	char* saveToStr(char* tmp);
};

