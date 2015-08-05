#pragma once
#include <vector>
#include<iostream>
using namespace std;
class SortQuestion
{
public:
	SortQuestion(void);
	~SortQuestion(void);
	void printNum(vector<int>Nums)
	{
		for (unsigned int j = 0; j < Nums.size(); j++)
		{
			cout << Nums[j] << endl;
		}
	}
protected:
	//������Ҫ�Ļ�������
	void swap(int &a, int &b)
	{
		int temp = 0;
		temp = a;
		a = b;
		b = temp;
	}
	int selectMinKey(vector<int>&Nums,int n)
	{

	}

	//��������----ֱ�Ӳ�������
	/*
	 *ֱ�Ӳ�������(Insertion Sort)�Ļ���˼���ǣ�ÿ�ν�һ��������ļ�¼��
	 *����ؼ��ִ�С���뵽ǰ���Ѿ��ź�����������е��ʵ�λ�ã�ֱ��ȫ����¼�������Ϊֹ��
	 *�㷨ʱ�临�Ӷ���O(n^2),�ռ临�Ӷ�O(1)
	 */
	 //�ϸ������ϵĶ�����У��������Ѿ��ź���ģ�����һ��ʱ������ŵ�����ʵ�λ�ã�ֱ����ȫ�ź���
public:
	void  InsertSort1(vector<int>&Nums)
	{
		for (unsigned int i = 1; i < Nums.size(); i++)
		{
			for (unsigned int j = 0; j < i; j++)
			{
				//���Ѿ��ź�������һ���Ƚϣ�����ȴ���ôֱ�Ӳ��䣬�൱�ڲ��룬������н���
				if (Nums[i] < Nums[j])
				{
					swap(Nums[i], Nums[j]);
				}
			}
		}
	}
	//�Ľ���������򣺵��µ���������ǰ���ȼ��������ݸ��Ѿ��ź�������ݵĴ�С��������ڣ���ֱ�Ӳ��룬���򣬰��ճ�����в���
	void  InsertSort2(vector<int>&Nums)
	{
		for (unsigned int i = 1; i < Nums.size(); i++) //��ʼֵΪ1����Ϊ��������ֻ��һ�����ݵ�ʱ����Ȼ�Ѿ����Ѿ��ĺõ�����
	 //���ָ����⣬Ϊʲôunsigned int ����������Խ�磺ԭ����Ϊ��i=1 j=0��ִ������ѭ���󣬽���j��ֵ�����j��unsigned int ��ôj-- �ͻ����-1��Խ��
			for (int j = i - 1; j >= 0 && Nums[j] > Nums[j + 1]; j--)
			{
				cout << j << endl;
				swap(Nums[j], Nums[j + 1]);
			}
	}

	//end of  ֱ�Ӳ�������

	//��������----ϣ������:��ʵֱ�Ӳ���������ϣ��������������
	//������һ��dx=1�����򣬾���ֱ�Ӳ�������

	void shellsort(vector<int>&Nums)
	{
		int n = Nums.size();
		int dk = n / 2;
		while (dk >= 1)
		{
			ShellInsertSort(Nums, n, dk);
			dk = dk / 2;
		}

	}
	void ShellInsertSort(vector<int>&Nums, int n, int dx)
	{
		for (int i = dx; i < n; i++)

			for (int j = i - dx; j >= 0 && Nums[j] > Nums[j + dx]; j = j - dx)
			{
				swap(Nums[j], Nums[j + dx]);
			}
	}
	//end of  ϣ������


	//ѡ������

};

