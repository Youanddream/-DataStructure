#pragma once
#include<iostream>
using namespace std;
template <class DataType>
class SeqList
{
protected:
	DataType *list;
	int maxSize;
	int size;

public:
	SeqList(int max = 0);
	SeqList(DataType *Arr,int low,int high);    //low  high为数组下标
	~SeqList();
	int Size() const;
	int maxsize()const;
	void Expand();
	void Insert(const DataType& item, int i);
	DataType Delete(const int i);
	DataType GetData(int i) const;
	void InversionToNew();
	void InversionLocal();
	/*friend SeqList<DataType> operator =(const SeqList<DataType> &a)
	{
		cout << "=重载";
		list = a.list; maxSize = a.maxSize; size = a.size;
	}*/
};

template <class DataType>
SeqList<DataType>::SeqList(int max)
{
	maxSize = max;
	size = 0;
	list = new DataType[maxSize];
}

template <class DataType>
SeqList<DataType>::SeqList(DataType *Arr, int low, int high)
{
	maxSize = (high - low + 1);
	size = 0;
	list = new DataType[maxSize];
	int leng = high - low + 1;
	for (int i = 0; i < leng; i++, low++)
	{
		list[i] = Arr[low];
		size++;
	}
}

template <class DataType>
SeqList<DataType>::~SeqList()
{
	delete[]list;
}

template <class DataType>
int SeqList<DataType>::Size() const           
{
	return size;
}

template <class DataType>
int SeqList<DataType>::maxsize() const      //测试expand
{
	return maxSize;
}

template <class DataType>
void SeqList<DataType>::Expand()
{
	if (size == maxSize)
	{
		DataType *tmp=list;
		maxSize = 2 * maxSize;
		list=new DataType[maxSize];
		for (int i = 0; i < size; i++)
		{
			list[i] = tmp[i];
		}
		delete[]tmp;
		cout << "完成扩容！";
	}

}

template <class DataType>
void SeqList<DataType>::Insert(const DataType& item, int i)
{
	Expand();

	if (i<0 || i>size)                  //只能在有数据的区间内任意插入  
										//不能在size+1到maxSize的空白区间内随意插入
	{
		cout << "参数越界insert！";
		exit(0);
	}

	for (int j = size; j > i; j--)
	{
		list[j] = list[j - 1];
	}
	 list[i] = item;
	 size++;
	
}

template <class DataType>
DataType SeqList<DataType>::Delete(const int i)
{
	if (size == 0)
	{
		cout << "顺序表已空，无法可删除元素！";
		exit(0);
	}

	if (i<0 || i>size - 1)
	{
		cout << "参数越界！delete";
		exit(0);
	}

	DataType x = list[i];

	for (int j = i; j < size - 1; j++)
	{
		list[j] = list[j + 1];
	}
	size--;
	return x;
	
}

template <class DataType>
DataType SeqList<DataType>::GetData(int i) const
{
	if (i<0 || i>maxSize - 1)
	{
		cout << "参数越界！getdata";
		exit(0);
	}
	return list[i];
}

template <class DataType>
void SeqList<DataType>::InversionToNew()
{
	/*int leng = size - 1; 
	int i = leng;
	int j = 0;
	DataType *Arr;
	Arr=new DataType[size];
	for (i,j; i <0;i--, j++)
	{		
		Arr[j]=list[i];
	}
	SeqList<DataType> a(Arr, 0, leng);*/
	SeqList<DataType> a;
	for (int i = size - 1, j = 0; i > 0; i--, j++)
	{
		a.Insert(GetData(i), j);
	}
	for (int i = 0; i < 5; i++)
	{
		cout << a.GetData(i) << endl;
	}	
}

template <class DataType>
void SeqList<DataType>::InversionLocal()
{
	for (int i = 0, j = size - 1; i <j; i++, j--)
	{
		DataType tmp = list[i];
		list[i] = list[j];
		list[j] = tmp;
	}
}