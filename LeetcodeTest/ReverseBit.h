#pragma once
#include <stdint.h>
#include <vector>
using namespace std;
class ReverseBit
{
public:
	ReverseBit(void);
	~ReverseBit(void);
	/*For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
	 *return 964176192 (represented in binary as 00111001011110000010100101000000).
	 *˼·��int ����ת��Ϊvector<int>���飬�����ǽ�������ת���ɶ����Ƶ�32λ��Ȼ���ÿ��λ����2�Ĵη��ǣ�������
	 */
	uint32_t reverseBits(uint32_t n) 
	{
		vector<int> iBits(32,0);
		int i = 0;
		while (n)
		{
			iBits[i]=(n%2);
			n = n/2;
			i++;
		}
		uint32_t  sum = 0;
		for (unsigned int i = 0;i<32;i++)
		{
			sum+=(uint32_t)iBits[32-1-i]*(pow(2,i));
		}
		return sum;
	}
	void DecToBit( int idata,vector<int>& iBits)
	{
		int i = 0;
		while (idata)
		{
			iBits[i]=(idata%2);
			idata = idata/2;
			i++;
		}
	}
};

