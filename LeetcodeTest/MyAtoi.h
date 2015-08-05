#pragma once
#include <string>
using namespace std;
#include <sstream>
class MyAtoi
{
public:
	MyAtoi(void);
	~MyAtoi(void);
	//这个自己的思路有问题，因为有各种边界条件没考虑到
	int myAtoi(string str) 
	{
		long long k =0;
		bool b = false;
		trim(str);
		int space = 0;
		bool bspace = false;
		for (unsigned int i = 0 ;i < str.size();i++)
		{
			if (isspace(str[i]))
			{
				space=i;
				bspace = true;
				break;
			}
		}
		if (bspace)
		{
			str.erase(space,str.size()-space);
		}
		
		char ch = str[0];
		if (str[0]=='+'&&str[1]=='-'||str[1]=='+'&&str[0]=='-')
		{
			return 0;
		}
		if (str[0]=='+'||str[0]=='-')
		{
			b = true;
			str = str.erase(0,1);
		}
		for (unsigned int i = 0 ;i < str.size();i++)
		{
			if (!isdigit(str[i]))
			{
				str = str.erase(i,str.size()-1);
			}
		}
		if(str=="")
			return 0;

		//str.insert(0,ch);
		stringstream mysream;
		mysream<<str;
		mysream>>k;
		if (b)
		{
			if (ch == '-')
			k=-k;
		}
	   if(k>=INT_MAX)
			return INT_MAX;
		if(k<=INT_MIN)
				return INT_MIN;
		return k;			

		
		
	}
	void  trim(string &s) 
	{
		if (s.empty()) 
		{
			return;
		}
		s.erase(0,s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);

	}
	/************************************************************************/
	/*  考虑四个方面：1.丢弃所有前面的空格2.注意数字的正负3.注意越界处理
	 *   4.注意不正确的输入
	 * 这样的解决方式好给力，思考！！！！！！*/
	
	/************************************************************************/

	int LeetcodeAtioi(string str)
	{
		int sign =1;
		int base =0;
		int i = 0;
		//去除前面的空格
		while(str[i]==' ')i++;
		//开始处理数据的正负号,如果有正负号，那么计算，如果没有正负号，则默认为正数,如果有正负，处理的同时，索引必须增1
		if(str[i]=='+'||str[i]=='-')
			sign = 1-2*(str[i++]=='-');
		//这里需要限定每个字符必须是数字否则进行返回值为0处理或者截断
		while(str[i]>='0'&&str[i]<='9')
		{
			//判断是否越界
			if(base>INT_MAX/10||base==INT_MAX/10&&str[i]-'7'>0)
				if(sign==1)
					return INT_MAX;
				else
					return INT_MIN;
			base = base*10 +(str[i++]-'0');

		}
		return base*sign;   
	}
};

