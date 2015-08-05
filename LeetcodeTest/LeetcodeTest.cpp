// LeetcodeTest.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"
#include "BTree.h"
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include "DesignMode.h"
#include "ReverseBit.h"
#include "MyAtoi.h"
#include "sqrtFunc.h"
#include "CommonFunction.h"
#include "MathFunc.h"
#include "SortQuestion.h"
using namespace std;
vector<int> Nodes;
void main()
{
	int a[5] = { 10,4,5,6,3 };
	vector<int> all(a, a + 5);
	SortQuestion sort;
	cout << "before" << endl;
	sort.printNum(all);
	cout << "after" << endl;
	//sort.InsertSort1(all);
	//sort.InsertSort2(all);
	sort.shellsort(all);
	sort.printNum(all);
	

}
