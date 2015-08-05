#pragma once
class MathFunc
{
public:
	MathFunc(void);
	~MathFunc(void);
	double MathSqrt(double x);
	double MathPow(double x, int n);//有些输入时时间超时的
	double Mypow(double x,int n);
};

