#pragma once
#include"DoubleCirLinList.h"

int main()
{
	int n = 6, a[] = { 0,1,2,3,4,5 };
	DC_LinList<int> dc;
	for (int i = 0; i < n; i++)
	{
		dc.Insert(a[i], i);
	}
	cout << "当前循环链表元素个数："<<dc.Size()<<endl<<"包含的元素:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout<<dc.GetData(i)<<" ";
	}
	cout << endl;
	int x=dc.Delete(2);
	n--;
	cout << "删除了" << x<<endl;
	cout << "当前循环链表元素个数：" << dc.Size() << endl << "包含的元素:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << dc.GetData(i) << " ";
	}
}