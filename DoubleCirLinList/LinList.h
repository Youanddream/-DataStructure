#include<iostream>
#include<stdlib.h>
#include "ListNode.h"
using namespace std;


template<class DataType>
class LinList
{
private:
	ListNode<DataType>* head;
	int size;
	ListNode<DataType>* Index(int i);

public:
	LinList();
	~LinList();

	int Size() const;
	void Insert(const DataType& item, int i);
	DataType Delete(int i);
	DataType GetData(int i);
	LinList InversionToNew();
	void Inversion();
	//LinList<DataType> operator =(LinList<DataType> &a) { head = a.head; size = a.size; }
};

template<class DataType>
LinList<DataType>::LinList()
{
	head = new ListNode<DataType>();
	size = 0;
}

template<class DataType>
LinList<DataType>::~LinList()
{
	ListNode<DataType> *p, *q;
	p = head;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		delete q;
	}
	size = 0;
	head = NULL;
}


template<class DataType>
ListNode<DataType> * LinList<DataType>::Index(int i)
{
	if (i<-1 || i>size - 1)
	{
		cout << "参数越界！index";
		//exit（0）;
	}

	if (i == -1)
		return head;

	ListNode<DataType>* p = head->next;
	int j = 0;
	while (p != NULL && j<i)
	{
		p = p->next;
		j++;
	}
	return p;
}


template<class DataType>
int LinList<DataType>::Size() const
{
	return size;
}

template<class DataType>
void LinList<DataType>::Insert(const DataType& item, int i)
{
	if (i<0 || i>size)
	{
		cout << "参数越界！insert";
		//exit（0）;
	}
	ListNode<DataType> *p = Index(i - 1);
	ListNode<DataType> *q = new ListNode<DataType>(item, p->next);
	p->next = q;
	size++;
}

template<class DataType>
DataType LinList<DataType>::Delete(int i)
{
	if (size == 0)
	{
		cout << "链表空，无可删除元素！" << endl;
		//exit(0);
	}
	if (i<0 || i>size - 1)
	{
		cout << "参数i越界！delete";
		//exit(0);
	}
	
	ListNode<DataType> *s, *p = Index(i - 1);
	s = p->next;
	p->next = p ->next->next;
	DataType x = s->data;
	size--;
	return x;
}

template<class DataType>
DataType LinList<DataType>::GetData(int i)
{
	if (i<0 || i>size - 1)
	{
		cout << "参数越界！getdata";
		//exit(0);
	}
	ListNode<DataType> *p = Index(i);
	return p->data;
}

//倒置到新的linlist
template<class DataType>
LinList<DataType> LinList<DataType>::InversionToNew()
{
	LinList<DataType> b;
	for (int i = size-1, j = 0;i>0;i--, j++)
	{
		ListNode<DataType> *p = Index(i);
		b.Insert(p->data, j);
	}
	return b->head;
}


//就地倒置
template<class DataType>
void LinList<DataType>::Inversion()
{
	for (int i = size-1, j = 0; j<i; i--, j++)
	{
		ListNode<DataType> *p, *q;
		p = Index(j);
		q = Index(i);
		DataType tmp;
		tmp = q->data;
		q->data = p->data;
		p->data = tmp;
	}
}