//#include "LinList.h"
//int main()
//{
//	LinList<int> a,*b;
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	for (int i = 0; i < 10; i++)
//	{
//		a.Insert(arr[i], i);
//	}
//	b.head=a.InversionToNew();
//	for (int j = 0; j < 10; j++)
//	{
//		cout << b.GetData(j) << " ";
//	}
//
//	//Inversion测试
//	/*
//	a.Inversion();
//	for (int j = 0; j < 10; j++)
//	{
//		cout << a.GetData(j) << " ";
//	}
//	*/
//}

#pragma once
#include"NoHNLinList.h"

int main()
{
	int n = 6, a[] = { 0,1,2,3,4,5 };
	NoHNLinList<int> No;
	for (int i = 0; i < n; i++)
	{
		No.Insert(a[i], i);
	}
	cout << "当前循环链表元素个数：" << No.Size() << endl << "包含的元素:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << No.GetData(i) << " ";
	}
	cout << endl;
	int x = No.Delete(2);
	n--;
	cout << "删除了" << x << endl;
	cout << "当前循环链表元素个数：" << No.Size() << endl << "包含的元素:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << No.GetData(i) << " ";
	}
}