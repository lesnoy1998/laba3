#pragma once
#include "Norma.h"
class Complex : public Norma
{
private:
	int a;
	int b;
public:
	Complex(int a1, int b1);
	~Complex();
	double func_norm() override;
	void show();
	char* saveToStr(char* tmp);
};

