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
//����ģʽ������������ͬ���ɲ�ͬ�Ĳ�Ʒ
class CalculatorFactory
{
public:
  virtual  COperation* Create() =0;
};
//�򵥹���ģʽ
//class CalculatorFactory
//{
//public:
//	COperation* Create(char ch);
//};
//��������ģʽ
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
//���󹤳�ģʽ
