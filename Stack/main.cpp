#include<iostream>
#include"C:\Users\Administrator\Desktop\SeqStack.h"
using namespace std;
int main()
{
	int a[]={1,2,3,4,5};
	SeqStack<int>sta;
	for(int i=0;i<5;i++)
	{
		sta.Push(a[i]);
	}
	for(int j=0;j<5;j++)
	{
		cout<<sta.GetTop()<<" ";
		sta.Pop();
	}
}
