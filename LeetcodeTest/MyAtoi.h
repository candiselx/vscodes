#pragma once
#include <string>
using namespace std;
#include <sstream>
class MyAtoi
{
public:
	MyAtoi(void);
	~MyAtoi(void);
	//����Լ���˼·�����⣬��Ϊ�и��ֱ߽�����û���ǵ�
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
	/*  �����ĸ����棺1.��������ǰ��Ŀո�2.ע�����ֵ�����3.ע��Խ�紦��
	 *   4.ע�ⲻ��ȷ������
	 * �����Ľ����ʽ�ø�����˼��������������*/
	
	/************************************************************************/

	int LeetcodeAtioi(string str)
	{
		int sign =1;
		int base =0;
		int i = 0;
		//ȥ��ǰ��Ŀո�
		while(str[i]==' ')i++;
		//��ʼ�������ݵ�������,����������ţ���ô���㣬���û�������ţ���Ĭ��Ϊ����,����������������ͬʱ������������1
		if(str[i]=='+'||str[i]=='-')
			sign = 1-2*(str[i++]=='-');
		//������Ҫ�޶�ÿ���ַ����������ַ�����з���ֵΪ0������߽ض�
		while(str[i]>='0'&&str[i]<='9')
		{
			//�ж��Ƿ�Խ��
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

