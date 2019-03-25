#include "LinList.h"
int main()
{
	LinList<int> a,*b;
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 10; i++)
	{
		a.Insert(arr[i], i);
	}
	b.head=a.InversionToNew();
	for (int j = 0; j < 10; j++)
	{
		cout << b.GetData(j) << " ";
	}

	//Inversion²âÊÔ
	/*
	a.Inversion();
	for (int j = 0; j < 10; j++)
	{
		cout << a.GetData(j) << " ";
	}
	*/
}