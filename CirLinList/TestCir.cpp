#pragma once
#include"CirLinList.h"

int main()
{
	int n = 6, a[] = { 0,1,2,3,4,5 };
	CirLinList<int> cir;
	for (int i = 0; i < n; i++)
	{
		cir.Insert(a[i], i);
	}
	cout << "��ǰѭ������Ԫ�ظ�����"<<cir.Size()<<endl<<"������Ԫ��:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout<<cir.GetData(i)<<" ";
	}
	cout << endl;
	int x=cir.Delete(2);
	n--;
	cout << "ɾ����" << x<<endl;
	cout << "��ǰѭ������Ԫ�ظ�����" << cir.Size() << endl << "������Ԫ��:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << cir.GetData(i) << " ";
	}
}