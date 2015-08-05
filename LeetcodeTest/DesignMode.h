#pragma once
#include <iostream>
using namespace std;
class COperation
{
public:
	virtual double  GetResult();
	double m_dFirst;
	double m_dSecond;
	double m_dResult;

};
class AddOperation:public COperation
{
public:
	double GetResult();
};
class SubtracionOperation:public COperation
{
public:
	double GetResult();
};
class MultiplyOperation:public COperation
{
public:
	double GetResult();
};
class DivisionOperation:public COperation
{
public:
	double GetResult();
};
//工厂模式，根据条件不同生成不同的产品
class CalculatorFactory
{
public:
  virtual  COperation* Create() =0;
};
//简单工厂模式
//class CalculatorFactory
//{
//public:
//	COperation* Create(char ch);
//};
//工厂方法模式
class AddFactory :public CalculatorFactory
{
public:
    COperation* Create();
};
class SubtractionFactory:public CalculatorFactory
{
public:
	COperation* Create();
};
class MutiplyFactory:public CalculatorFactory
{
public:
	COperation* Create();
};
class DivisionFactory:public CalculatorFactory
{
public:
	COperation* Create();
};
//抽象工厂模式
