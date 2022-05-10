#pragma once
#include "Norma.h"
class Vector10 : public Norma
{
private:
	int* vct = 0;
public:
	Vector10();
	Vector10(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10);
	~Vector10();

	double func_norm() override final;
	void show();

	char* saveToStr(char* tmp);
};

