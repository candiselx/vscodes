#include "stdafx.h"
#include "MathFunc.h"
#include <math.h>
MathFunc::MathFunc(void)
{

}


MathFunc::~MathFunc(void)
{
}

double MathFunc::MathSqrt( double x )
{
	if (x<0)
		return 0; 
	else
	return pow(x,0.5);
}

double MathFunc::MathPow( double x, int n )
{
	if (n==0)
	{
		return 1;
	}
	else
	{
		return n%2==0?MathPow(x*x,n/2):MathPow(x*x,(n-1)/2)*x;
	}
	
}

double MathFunc::Mypow( double x,int n )
{
	if (n==0) 
		return 1;
	double t = pow(x,n/2);//采用c++本身的库函数，这样就减少递归的栈的进出耗时
	if (n%2) 
	{
		return n<0 ? 1/x*t*t : x*t*t;
	} else 
	{
		return t*t;
	}
}
