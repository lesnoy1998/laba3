#pragma once
class Norma
{
public:
	virtual double func_norm() = 0;
	virtual void show() = 0;

	virtual char* saveToStr(char* tmp) = 0;
};

