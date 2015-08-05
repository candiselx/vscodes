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
	//排序需要的基础函数
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

	//插入排序----直接插入排序
	/*
	 *直接插入排序(Insertion Sort)的基本思想是：每次将一个待排序的记录，
	 *按其关键字大小插入到前面已经排好序的子序列中的适当位置，直到全部记录插入完成为止。
	 *算法时间复杂度是O(n^2),空间复杂度O(1)
	 */
	 //严格按照书上的定义进行：左手是已经排好序的，当来一个时，将其放到最合适的位置，直到完全排好序
public:
	void  InsertSort1(vector<int>&Nums)
	{
		for (unsigned int i = 1; i < Nums.size(); i++)
		{
			for (unsigned int j = 0; j < i; j++)
			{
				//跟已经排好序的最后一个比较，如果比大，那么直接不变，相当于插入，否则进行交换
				if (Nums[i] < Nums[j])
				{
					swap(Nums[i], Nums[j]);
				}
			}
		}
	}
	//改进后插入排序：当新的数据来这前，先检查这个数据跟已经排好序的数据的大小，如果大于，则直接插入，否则，按照常规进行插入
	void  InsertSort2(vector<int>&Nums)
	{
		for (unsigned int i = 1; i < Nums.size(); i++) //初始值为1是因为，当左手只有一个数据的时候，自然已经是已经拍好的序列
	 //出现个问题，为什么unsigned int 在这里会出现越界：原因：因为当i=1 j=0；执行问内循环后，进行j求值，如果j是unsigned int 那么j-- 就会出现-1会越界
			for (int j = i - 1; j >= 0 && Nums[j] > Nums[j + 1]; j--)
			{
				cout << j << endl;
				swap(Nums[j], Nums[j + 1]);
			}
	}

	//end of  直接插入排序

	//插入排序----希尔排序:其实直接插入排序是希尔排序的特殊情况
	//仅进行一次dx=1的排序，就是直接插入排序

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
	//end of  希尔排序


	//选择排序

};

