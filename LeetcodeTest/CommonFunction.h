#pragma once
class CommonFunction
{
public:
	CommonFunction(void);
	~CommonFunction(void);
	static int Max(int a,int b)
	{
		if (a>b)
			return a;
		else
			return b;
		
	}
};

