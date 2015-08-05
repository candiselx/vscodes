#include "stdafx.h"
#include "DesignMode.h"
#include <limits>



double COperation::GetResult()
{
	return 0;
}

double AddOperation::GetResult()
{
	return m_dFirst+m_dSecond;
}

double SubtracionOperation::GetResult()
{
	return m_dFirst-m_dSecond;
}

double MultiplyOperation::GetResult()
{
	return m_dFirst*m_dSecond;
}

double DivisionOperation::GetResult()
{
	if (m_dSecond == 0)
	{
		return INT_MAX;
	}
	else
	{
		return m_dFirst/m_dSecond;
	}
}

//COperation* CalculatorFactory::Create( char ch )
//{
//	switch (ch)
//	{
//	case '+':
//		return new AddOperation();
//	case '-':
//		return new SubtracionOperation();
//	case '*':
//		return new MultiplyOperation();
//	default:
//			return new DivisionOperation();
//		break;
//	}
//}
COperation* AddFactory::Create(  )
{
	return new AddOperation();
}
COperation* SubtractionFactory::Create(  )
{
	return new SubtracionOperation();
}
COperation* MutiplyFactory::Create(  )
{
	return new MultiplyOperation();
}
COperation* DivisionFactory::Create(  )
{
	return new DivisionOperation();
}

